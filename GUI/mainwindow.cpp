#include "mainwindow.h"
#include <iostream>
#include <fstream>
#include "wfc_generator.h"
#include "tileset.h"
#include "grid.h"
#include "image_generator.h"
#include <memory>
#include <chrono>
#include <QFileDialog>
#include <QFile>
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

    QWidget *configTab = new QWidget();  // Placeholder for Config tab
    tab_widget->addTab(configTab, "Config");
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
    QWidget *configTab = tab_widget->widget(1);
    QVBoxLayout *layout = new QVBoxLayout();

    // Add widgets to the layout as needed

    configTab->setLayout(layout);
}

void MainWindow::onConfigSelected(const QString &configPath)
{
    std::string configPathStd = "../" + configPath.toStdString();

    std::ifstream file(configPathStd);
    file >> config;

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