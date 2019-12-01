#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <memory>
#include <iostream>
#include "library.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    std::unique_ptr<QToolBar>       toolBar;
    Library lib = Library("windowLib");

private slots:
    void openLibrary();
    void newLibrary();
    void saveLibrary();
    void saveLibraryAs();

    void addBook();

    void quit();
};

#endif // MAINWINDOW_HPP
