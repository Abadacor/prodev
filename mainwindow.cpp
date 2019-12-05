#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    toolBar(addToolBar("&Library")),
    lib("windowLib")
{
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

    this->lib.saveBooks();
    this->lib.~Library();
    new(&this->lib) Library(newName);
    this->lib.loadBooks();

    repaint();
}

void MainWindow::quit()
{
    close();
}

void MainWindow::addBook()
{
    QString name = ui->name->text();
    QString authorField = ui->author->text();

    //To get all authors, split string on "," and add them to a QStringList;
    QStringList authors = authorField.split(',');

    QString isbn = ui->isbn->text();
    int year = ui->year->text().split(" ")[0].toInt();

    if(!checkString(name))
        throw std::invalid_argument("The new book name is not correct!");
    for(auto auth : authors)
        if(!checkString(auth))
            throw std::invalid_argument("The new author name is not correct!");
    //if(!checkISBN(isbn))
    //    throw std::invalid_argument("The new ISBN is not correct!");
    if(!checkYear(year))
        throw std::invalid_argument("The new publication date is not correct!");


    this->lib.addBook(QStringList(authors), name, isbn, year);
    this->lib.printBooks();

    repaint();
}

void MainWindow::deleteBook()
{
    QString isbn = ui->isbn->text();
    std::vector<Book>& books(lib.getBooks());

    for(auto ite = books.begin(); ite != books.end(); ite++)
    {
        if(ite->getISBN()==isbn)
        {
            std::cout << "IN!" << std::endl;
            ite->deleteBook(ite->getISBN());
            books.erase(ite);
            lib.printBooks();
            repaint();
            break;
        }
    }
}

void MainWindow::repaint()
{
    QString str = "Title\tAuthor\tISBN\tYear of publication\n";
    for (auto book : this->lib.getBooks())
        str += book.to_string();

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

bool MainWindow::checkISBN(QString isbn)
{
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
