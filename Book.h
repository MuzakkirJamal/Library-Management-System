#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book {
private:
    int id;
    string title;
    string author;
    int copies;

public:
    Book();
    Book(int id, string title, string author, int copies);

    void display() const;

    int getId() const;
    string getTitle() const;
    string getAuthor() const;
    int getCopies() const;

    void setTitle(const string &t);
    void setAuthor(const string &a);
    void setCopies(int c);

    // For file handling
    string toString() const;
    static Book fromString(const string &line);
};

#endif
