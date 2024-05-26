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
    : QMainWindow(parent), tabWidget(new QTabWidget(this)), configComboBox(new QComboBox(this)), 
      imageLabel(new QLabel(this)), generateButton(new QPushButton("Generate", this)), 
      saveButton(new QPushButton("Save", this))
{
    //Window setup
    setupMenu();
    setupTabs();
    setCentralWidget(tabWidget);

    setFixedSize(800, 600); 

    // Load the config paths from the configs.json 
    string configsPath = "../configs.json";
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
}

void MainWindow::setupTabs()
{
    QWidget *generationTab = new QWidget();
    tabWidget->addTab(generationTab, "Generate");
    setupGenerationTab();

    //Add config tab in the future
}

void MainWindow::setupGenerationTab()
{
    QWidget *generationTab = tabWidget->widget(0);
    QVBoxLayout *layout = new QVBoxLayout();

    imageLabel->setText("No image generated yet.");
    imageLabel->setAlignment(Qt::AlignCenter);
    imageLabel->setMinimumSize(400, 400);  
    imageLabel->setStyleSheet("border: 1px solid black;");

    layout->addWidget(configComboBox);

    QHBoxLayout *imageLayout = new QHBoxLayout(); 
    imageLayout->addWidget(imageLabel);
    layout->addLayout(imageLayout);

    widthInput = new QLineEdit();
    heightInput = new QLineEdit();
    widthInput->setMaximumWidth(100);  
    heightInput->setMaximumWidth(100); 
    widthInput->setText("10");
    heightInput->setText("10");

    QHBoxLayout* inputLayout = new QHBoxLayout();
    inputLayout->addStretch(1);  
    inputLayout->addWidget(new QLabel("Width:"));
    inputLayout->addWidget(widthInput);
    inputLayout->addWidget(new QLabel("Height:"));
    inputLayout->addWidget(heightInput);
    inputLayout->addStretch(1);  

    layout->addLayout(inputLayout);

    QHBoxLayout* buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(generateButton);
    buttonLayout->addWidget(saveButton);

    layout->addStretch(1);
    layout->addLayout(buttonLayout);

    generationTab->setLayout(layout);
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

    // Set imageLabel image to image.png
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