#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    toolBar(addToolBar("&Library")),
    lib("windowLib")
{
    lib.loadBooks();
    ui->setupUi(this);

    // Define actions. toolBar takes ownership of the pointers and handles the deletion
    QAction *actionSave(new QAction("&Save", this));
    QAction *actionQuit(new QAction("&Quit", this));

    toolBar->addAction(actionSave);
    toolBar->addAction(actionQuit);

    // Link actions to corresponding function
    connect(actionSave, SIGNAL(triggered()), this, SLOT(saveLibrary()));
    connect(actionQuit, SIGNAL(triggered()), this, SLOT(quit()));

    repaint();
}

void MainWindow::saveLibrary()
{
    lib.saveBooks();
    statusBar()->showMessage(tr("saved"),2000);
}

void MainWindow::changeLibrary()
{
    QString newName = ui->libName->text();
    if(!checkString(newName))
        throw std::invalid_argument("The new Library name is not correct!");

    lib.saveBooks();
    lib = Library(newName);
    lib.loadBooks();

    repaint();
}

void MainWindow::quit()
{
    close();
}

void MainWindow::addBook()
{
    QString name;
    QStringList authors;
    QString isbn;
    int year;

    bool validValues = true;

    name = ui->name->text();
    authors = ui->author->text().split(',');
    isbn = ui->isbn->text();
    year = ui->year->text().split(" ")[0].toInt();

    if(!checkString(name))
        validValues=false;
    for(auto auth : authors)
        if(!checkString(auth))
            validValues=false;
    if(!checkString(isbn))
        validValues=false;
    if(!checkYear(year))
        validValues=false;

    if(validValues){

        lib.addBook(authors, name, isbn, year);
        lib.printBooks();
    }
    else
    {
        QMessageBox::warning(
            this,
            tr("Awesome Library Warning"),
            tr("One or more parameters you entered are not valid! Guess which :)") );
    }

    repaint();
}

void MainWindow::deleteBook()
{
    QString isbn = ui->isbn->text();
    std::vector<std::unique_ptr<Book>>& books(lib.getBooks());

    for(auto ite = books.begin(); ite != books.end(); ite++)
    {
        if((*ite)->getISBN()==isbn)
        {
            std::cout << "IN!" << std::endl;
            (*ite)->deleteBook((*ite)->getISBN());
            books.erase(ite);
            lib.printBooks();
            repaint();
            break;
        }
    }
}

void MainWindow::repaint()
{
    QString str = "";
    std::vector<std::unique_ptr<Book>>& books(lib.getBooks());
    for (auto ite = books.begin(); ite < books.end(); ite++)
        str += (*ite)->to_string();

    ui->display->setText(str);
    ui->name->setText("");
    ui->author->setText("");
    ui->isbn->setText("");
    ui->year->setText("");
}

bool MainWindow::checkString(QString str)
{
    if(str.isEmpty() || str.size()>=50 || (str[str.size()]=="-" && str[str.size()-1]=="-"))
        return false;
    else
        return true;
}

bool MainWindow::checkYear(int year)
{
    time_t theTime = time(NULL);
    struct tm *aTime = localtime(&theTime);
    int y = aTime->tm_year + 1900;

    return year<=y;
}

MainWindow::~MainWindow()
{
    delete ui;
}
