#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <memory>

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

private slots:
    void openLibrary();
    void newLibrary();
    void saveLibrary();
    void saveLibraryAs();
    void quit();
};

#endif // MAINWINDOW_HPP
