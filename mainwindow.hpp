#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

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
    QToolBar       *toolBar;

private slots:
    void openLibrary();
    void newLibrary();
    void saveLibrary();
    void saveLibraryAs();
    void quit();
};

#endif // MAINWINDOW_HPP
