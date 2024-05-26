#include "mainwindow.h"
#include <iostream>
#include <fstream>
#include "wfc_generator.h"
#include "tileset.h"
#include "grid.h"
#include "image_generator.h"
#include <memory>
#include <chrono>

using std::string;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), tab_widget(new QTabWidget(this)), configComboBox(new QComboBox(this)), 
      imageLabel(new QLabel(this)), generateButton(new QPushButton("Generate", this)), 
      saveButton(new QPushButton("Save", this))
{
    setupMenu();
    setupTabs();
    setCentralWidget(tab_widget);

    setFixedSize(800, 600);  // Set the initial size of the main window

    // Example config paths, replace with actual paths
    string configsPath = "configs.json";
    std::ifstream file(configsPath);
    if (!file) {
        std::cerr << "Failed to open file\n";
        return;
    }
    json configs;
    file >> configs;

    for(auto& configPath : configs["config_paths"])
    {
        configPaths.push_back(QString::fromStdString(configPath.get<string>()));
    }


    configComboBox->addItems(QStringList::fromVector(configPaths));
    if (!configPaths.isEmpty()) {
        configComboBox->setCurrentIndex(0);
        onConfigSelected(configPaths[0]);
    }

    connect(configComboBox, &QComboBox::currentTextChanged, this, &MainWindow::onConfigSelected);
    connect(generateButton, &QPushButton::clicked, this, &MainWindow::onGenerateButtonClicked);
    connect(saveButton, &QPushButton::clicked, this, &MainWindow::onSaveButtonClicked);
}

void MainWindow::setupMenu()
{
    QMenu *fileMenu = menuBar()->addMenu("File");
    QMenu *settingsMenu = menuBar()->addMenu("Settings");
    QMenu *aboutMenu = menuBar()->addMenu("About");

    // You can add actions to these menus as needed
}

void MainWindow::setupTabs()
{
    QWidget *generationTab = new QWidget();
    tab_widget->addTab(generationTab, "Generate");
    setupGenerationTab();

    configTab = new QWidget();  // Placeholder for Config tab
    tab_widget->addTab(configTab, "Config");
    configTabLayout = new QVBoxLayout();
    configTab->setLayout(configTabLayout);
    setupConfigTab();
}

void MainWindow::setupGenerationTab()
{
    QWidget *generationTab = tab_widget->widget(0);
    QVBoxLayout *layout = new QVBoxLayout();

    // Set a placeholder text for imageLabel
    imageLabel->setText("No image generated yet.");

    // Center the text in imageLabel
    imageLabel->setAlignment(Qt::AlignCenter);

    // Set a minimum size for imageLabel
    imageLabel->setMinimumSize(400, 400);  // Adjust the size as needed

    // Add a border to imageLabel
    imageLabel->setStyleSheet("border: 1px solid black;");

    layout->addWidget(configComboBox);

    // Create a QHBoxLayout for centering imageLabel
    QHBoxLayout *imageLayout = new QHBoxLayout();
    imageLayout->addStretch(1);  // Add stretch before imageLabel
    imageLayout->addWidget(imageLabel);
    imageLayout->addStretch(1);  // Add stretch after imageLabel

    layout->addLayout(imageLayout);

    // Create the QLineEdit widgets
    widthInput = new QLineEdit();
    heightInput = new QLineEdit();

    // Set a maximum width for the QLineEdit widgets
    widthInput->setMaximumWidth(100);  // Adjust the width as needed
    heightInput->setMaximumWidth(100); // Adjust the width as needed

    // Create a QHBoxLayout for the QLineEdit widgets
    QHBoxLayout *inputLayout = new QHBoxLayout();
    inputLayout->addStretch(1);  // Add stretch before the input fields
    inputLayout->addWidget(new QLabel("Width:"));
    inputLayout->addWidget(widthInput);
    inputLayout->addWidget(new QLabel("Height:"));
    inputLayout->addWidget(heightInput);
    inputLayout->addStretch(1);  // Add stretch after the input fields

    // Add the QHBoxLayout to the main layout
    layout->addLayout(inputLayout);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(generateButton);
    buttonLayout->addWidget(saveButton);

    layout->addStretch(1);
    layout->addLayout(buttonLayout);

    generationTab->setLayout(layout);
}

void MainWindow::setupConfigTab()
{
    if(config["type"] != "auto")
    {

        QLabel *infoLabel = new QLabel("Only config for auto generating is available for changing in GUI!");
        configTabLayout->addWidget(infoLabel);
    }
    else
    {
        QLabel *imageLabel = new QLabel();
        QPixmap pixmap(QString::fromStdString(config["path"]));
        imageLabel->setPixmap(pixmap.scaled(200, 200, Qt::KeepAspectRatio, Qt::SmoothTransformation));  // Scale pixmap to fit in 200x200
        imageLabel->setFixedSize(200, 200);  // Set fixed size
        imageLabel->setStyleSheet("border: 1px solid black");  // Add black border

        QHBoxLayout *hLayout = new QHBoxLayout();
        hLayout->addStretch();
        hLayout->addWidget(imageLabel);
        hLayout->addStretch();

        configTabLayout->addLayout(hLayout);

        QPushButton *imageButton = new QPushButton("Open Image");
        connect(imageButton, &QPushButton::clicked, this, &MainWindow::onImageButtonClicked);
        configTabLayout->addWidget(imageButton);

        QLineEdit *heightInput = new QLineEdit(QString::number(static_cast<int>(config["y"])));
        QLineEdit *widthInput = new QLineEdit(QString::number(static_cast<int>(config["x"])));
        configTabLayout->addWidget(new QLabel("Height:"));
        configTabLayout->addWidget(heightInput);
        configTabLayout->addWidget(new QLabel("Width:"));
        configTabLayout->addWidget(widthInput);

        rotateCheckBox = new QCheckBox("Rotate");
        rotateCheckBox->setChecked(config["rotate"]);
        configTabLayout->addWidget(rotateCheckBox);

        QDoubleSpinBox *thresholdSpinBox = new QDoubleSpinBox();
        thresholdSpinBox->setRange(0, 1);
        thresholdSpinBox->setValue(config["threshold"]);
        configTabLayout->addWidget(new QLabel("Threshold:"));
        configTabLayout->addWidget(thresholdSpinBox);

        QPushButton *saveButton = new QPushButton("Save");
        connect(saveButton, &QPushButton::clicked, this, &MainWindow::onSaveConfigButtonClicked);
        configTabLayout->addWidget(saveButton);
    }
}

void MainWindow::onImageButtonClicked()
{
    QString imagePath = QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("Images (*.png *.jpg *.bmp)"));
    if (!imagePath.isEmpty()) {
        config["path"] = imagePath.toStdString();
        QPixmap pixmap(imagePath);
        imageLabel->setPixmap(pixmap.scaled(imageLabel->width(), imageLabel->height(), Qt::KeepAspectRatio));
    }
}

void MainWindow::onSaveConfigButtonClicked()
{
    config["y"] = heightInput->text().toInt();
    config["x"] = widthInput->text().toInt();
    config["rotate"] = rotateCheckBox->isChecked();
    config["threshold"] = thresholdSpinBox->value();

    // Save config to config.json
    std::ofstream configFile("config.json");
    configFile << config.dump(4);
    configFile.close();
}

void MainWindow::onConfigSelected(const QString &configPath)
{
    std::string configPathStd = "../" + configPath.toStdString();

    std::ifstream file(configPathStd);
    file >> config;

    // Clear the layout of configTab
    QLayoutItem *item;
    while ((item = configTabLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    // Call setupConfigTab again to update the configTab
    setupConfigTab();
}

void MainWindow::onGenerateButtonClicked()
{
    bool okWidth, okHeight;
    int gridWidth = widthInput->text().toInt(&okWidth);
    int gridHeight = heightInput->text().toInt(&okHeight);
    std::string path = "../" + configComboBox->currentText().toStdString();

    if (!okWidth || !okHeight) {
        // One of the inputs was not a valid integer
        QMessageBox::critical(this, "Input Error", "Please enter valid integers for width and height.");
        return;
    }
    
    Tileset ts(path);

    unique_ptr<Grid> grid;
    do {
        grid.reset(new Grid(ts, gridWidth, gridHeight));

        WFCGenerator generator(*grid, ts);
        auto start = std::chrono::high_resolution_clock::now();

        generator.collapseGrid();

        auto end = std::chrono::high_resolution_clock::now(); 
        std::chrono::duration<double> elapsed = end - start;

        std::cout << "Time taken to collapse grid: " << elapsed.count() << " seconds\n";
        std::cout << std::endl;
        
    } while(!grid->isValid());

    QString imagePath = "image.png";
    this->imagePath = imagePath.toStdString();
    ImageGenerator::saveImage(*grid, ts, imagePath.toStdString());

    // Set imageLabel's image to image.png
    QPixmap pixmap(imagePath);
    imageLabel->setPixmap(pixmap.scaled(imageLabel->width(), imageLabel->height(), Qt::KeepAspectRatio));
}

void MainWindow::onSaveButtonClicked()
{

    QString savePath = QFileDialog::getSaveFileName(this, tr("Save Image"), "", tr("Images (*.png *.jpg *.bmp)"));

    if (!savePath.isEmpty()) {
        if (!QFile::copy(QString::fromStdString(imagePath), savePath)) {
            QMessageBox::critical(this, "Save Error", "Failed to save the image.");
        }
    }
}