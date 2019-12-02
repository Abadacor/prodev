#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    toolBar(addToolBar("&Library"))
{
    ui->setupUi(this);

    // Define actions. toolBar takes ownership of the pointers and handles the deletion
    QAction *actionOpen(new QAction("&Open", this));
    QAction *actionNew(new QAction("&New", this));
    QAction *actionSave(new QAction("&Save", this));
    QAction *actionSaveAs(new QAction("Save &as", this));
    QAction *actionQuit(new QAction("&Quit", this));

    toolBar->addAction(actionOpen);
    toolBar->addAction(actionNew);
    toolBar->addAction(actionSave);
    toolBar->addAction(actionSaveAs);
    toolBar->addAction(actionQuit);

    // Link actions to corresponding function
    connect(actionOpen, SIGNAL(triggered()), this, SLOT(openLibrary()));
    connect(actionNew, SIGNAL(triggered()), this, SLOT(newLibrary()));
    connect(actionSave, SIGNAL(triggered()), this, SLOT(saveLibrary()));
    connect(actionSaveAs, SIGNAL(triggered()), this, SLOT(saveLibraryAs()));
    connect(actionQuit, SIGNAL(triggered()), this, SLOT(quit()));

    repaint();
}

void MainWindow::openLibrary()
{
    statusBar()->showMessage(tr("open"),2000);
}

void MainWindow::newLibrary()
{
    statusBar()->showMessage(tr("new"),2000);
}

void MainWindow::saveLibrary()
{
    statusBar()->showMessage(tr("save"),2000);
}
void MainWindow::saveLibraryAs()
{
    statusBar()->showMessage(tr("saveas"),2000);
}
void MainWindow::quit()
{
    close();
}

void MainWindow::addBook()
{
    std::cout << "hello there" << std::endl;

    QString name = ui->name->text();
    QString author = ui->author->text();
    int isbn = ui->isbn->text().split(" ")[0].toInt();
    int year = ui->year->text().split(" ")[0].toInt();

    this->lib.addBook(QStringList(author), name, isbn, year);
    this->lib.printBooks();

    repaint();
}

void MainWindow::deleteBook()
{
    int isbn = ui->isbn->text().split(" ")[0].toInt();
    int index = -1;

    for(int i=0;i<lib.getBooks().size();i++)
    {
        if(lib.getBooks()[i].getISBN()==isbn)
        {
            std::cout << "IN!" << std::endl;
            lib.getBooks()[i].deleteBook();
            index = i;
        }
    }
    lib.getBooks().erase(lib.getBooks().begin()+index);

    repaint();

}

void MainWindow::repaint()
{
    QString str = "Title\tAuthor\tISBN\tYear of publication\n";
    for (auto book : this->lib.getBooks())
        str += book.to_string() + "\n";

    ui->display->setText(str);
}

MainWindow::~MainWindow()
{
    delete ui;
}
