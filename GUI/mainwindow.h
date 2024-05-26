#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTabWidget>
#include <QComboBox>
#include <QLabel>
#include <QMenuBar>
#include <QMenu>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <nlohmann/json.hpp>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QCheckBox>
#include <QDoubleSpinBox>

using json = nlohmann::json;
using std::unique_ptr;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() = default;

private slots:
    void onConfigSelected(const QString &configPath);
    void onGenerateButtonClicked();
    void onSaveButtonClicked();

private:
    json config;
    QTabWidget* tabWidget;
    QComboBox* configComboBox;
    QLabel* imageLabel;
    QPushButton* generateButton;
    QPushButton* saveButton;
    QLineEdit* widthInput;  
    QLineEdit* heightInput;

    QVector<QString> configPaths; 
    std::string imagePath; 

    void setupMenu();
    void setupTabs();
    void setupGenerationTab();

};

#endif // MAINWINDOW_H
