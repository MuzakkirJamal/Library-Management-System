#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include <vector>
#include <string>
using namespace std;

class Library {
private:
    vector<Book> books;
    string filename = "library.txt";

public:
    void addBook(const Book &book);
    void viewBooks() const;
    void searchBook(int id) const;
    void deleteBook(int id);
    void issueBook(int id);
    void returnBook(int id);
    void updateBook(int id);

    void saveToFile() const;
    void loadFromFile();
};

#endif
