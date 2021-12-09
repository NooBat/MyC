#include<bits/stdc++.h>

using namespace std;

const int MAX_NUMBER_OF_BOOKS = 1000;

struct Book
{
public:
    string title;
    string author[30];
    string year;
    int numberOfAuthor;
};

struct BookList
{
public:
    Book list[MAX_NUMBER_OF_BOOKS];
    int numberOfBooks;
};

void printBook(Book& book);
void printBookList(BookList& bookList);
bool findBook(BookList& bookList, string title);
void editData(Book& book, string title, string author[], int numberOfAuthor, string year);

bool inputData(BookList& bookList, string title, string author[], int numberOfAuthor, string year)
{
    if (bookList.numberOfBooks == MAX_NUMBER_OF_BOOKS) return false;
    if (numberOfAuthor > 30) return false;

    Book newBook;

    editData(newBook, title, author, numberOfAuthor, year);

    bookList.list[bookList.numberOfBooks++] = newBook; 

    return true;
}

void printBook(Book& book)
{
    cout << setw(30) << left << "Title" << setw(30) << left << "Author" << "Year" << endl;
    cout << setw(30) << left << book.title << setw(30) << left << book.author[0] << book.year << endl;
    for (int i = 1; i < book.numberOfAuthor; i++) 
    {
        cout << setw(30) << "" << setw(30) << left << book.author[i] << endl;
    }
    cout << endl;
}

void printBookList(BookList& bookList)
{
    for (int i = 0; i < bookList.numberOfBooks; i++)
    {
        printBook(bookList.list[i]);
    }
}

bool findBook(BookList& bookList, string title) 
{
    for (int i = 0; i < bookList.numberOfBooks; i++) 
    {
        if (title == bookList.list[i].title) return true;
    }

    return false;
}

void editData(Book& book, string title, string author[], int numberOfAuthor, string year)
{
    book.title = title;
    for (int i = 0; i < numberOfAuthor; i++)
    {
        book.author[i] = author[i];
    }
    book.numberOfAuthor = numberOfAuthor;
    book.year = year;
    book.numberOfAuthor = numberOfAuthor;
}

int main()
{  
    BookList bookList;
    bookList.numberOfBooks = 0;
    int numberOfBooks = 0;
    cout << "How many books: ";
    cin >> numberOfBooks;

    for (int i = 0; i < numberOfBooks; i++)
    {
        cin.ignore();
        string title;
        cout << "Input the title of the book " + to_string(i + 1) << ": ";
        getline(cin, title);

        int numberOfAuthor;
        cout << "Number of Author: ";
        cin >> numberOfAuthor;
        
        cin.ignore(1000, '\n');
        string author[numberOfAuthor];
        for (int j = 0; j < numberOfAuthor; j++)
        {
            cout << "Name of author " + to_string(j + 1) << ": ";
            getline(cin, author[j]);
        }

        int year;
        cout << "Year: ";
        cin >> year;

        inputData(bookList, title, author, numberOfAuthor, to_string(year));
    }
    printBookList(bookList);

    findBook(bookList, "Book 1");

    return 0;
}
