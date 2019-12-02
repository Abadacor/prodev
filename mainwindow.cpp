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

void MainWindow::quit()
{
    close();
}

void MainWindow::addBook()
{
    QString name = ui->name->text();
    QString author = ui->author->text();
    int isbn = ui->isbn->text().split(" ")[0].toInt();
    int year = ui->year->text().split(" ")[0].toInt();

    assert(this->checkString(name));
    assert(this->checkString(author));
    //assert(this->checkISBN(isbn));
    assert(this->checkYear(year));


    this->lib.addBook(QStringList(author), name, isbn, year);
    this->lib.printBooks();

    repaint();
}

void MainWindow::deleteBook()
{
    int isbn = ui->isbn->text().split(" ")[0].toInt();
    int index = -1;
    std::vector<Book>& books(lib.getBooks());

    for(int i=0;i<books.size();i++)
    {
        if(books[i].getISBN()==isbn)
        {
            std::cout << "IN!" << std::endl;
            books[i].deleteBook();
            index = i;
            break;
        }
    }
    if(index != -1)
    {
        books.erase(books.begin()+index);
        lib.printBooks();
        repaint();
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
    QRegExp rx("\\d-\\d{4}-\\d{4}-\\d");
    return rx.exactMatch(isbn);
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
