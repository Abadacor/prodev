#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <memory>
#include <iostream>
#include <time.h>
#include "library.h"
#include <QMessageBox>

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
    std::unique_ptr<QToolBar> toolBar;
    Library lib;
    void repaint();

    bool checkString(QString str);
    bool checkISBN(QString isbn);
    bool checkYear(int year);

private slots:
    void saveLibrary();
    void changeLibrary();

    void addBook();
    void deleteBook();

    void quit();
};

#endif // MAINWINDOW_HPP
