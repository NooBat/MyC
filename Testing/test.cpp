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

bool inputData(BookList bookList, string title, string author[], string year)
{
    if (bookList.numberOfBooks == MAX_NUMBER_OF_BOOKS) return false;
    int numberOfAuthor = (int)(sizeof(author) / sizeof(author[0]));
    if (numberOfAuthor > 30) return false;
    Book newBook;
    newBook.title = title;
    
    for (int i = 0; i < numberOfAuthor; i++)
    {
        newBook.author[i] = author[i];
    }
    newBook.numberOfAuthor = numberOfAuthor;
    newBook.year = year;

    bookList.list[bookList.numberOfBooks++] = newBook; 

    return true;
}

void printBook(Book book)
{
    cout << setw(100) << left << "Title" << setw(50) << left << "Author" << "Year" << endl;
    cout << setw(100) << left << book.title << setw(50) << left << book.author[0] << book.year << endl;
    for (int i = 1; i < book.numberOfAuthor; i++) 
    {
        cout << setw(150) << right << book.author[i] << endl;
    }
}

void printBookList(BookList bookList)
{
    for (int i = 0; i < bookList.numberOfBooks; i++)
    {
        printBook(bookList.list[i]);
    }
}

int main()
{  
    BookList bookList;
    bookList.numberOfBooks = 0;
    for (int i = 0; i < 10; i++)
    {
        string author[10];
        for (int j = 0; j < 10; j++)
        {
            author[j] = "ABDG";
        }

        inputData(bookList, "Book " + to_string(i + 1), author, "1999");
    }
    cout << "a" << endl;
    printBookList(bookList);

    return 0;
}
