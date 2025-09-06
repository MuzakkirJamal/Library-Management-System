#include "Book.h"
#include <iostream>
#include <sstream>
using namespace std;

Book::Book() : id(0), title(""), author(""), copies(0) {}

Book::Book(int id, string title, string author, int copies)
    : id(id), title(title), author(author), copies(copies) {}

void Book::display() const {
    cout << "ID: " << id << ", Title: " << title
         << ", Author: " << author << ", Copies: " << copies << endl;
}

int Book::getId() const { return id; }
string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }
int Book::getCopies() const { return copies; }

void Book::setTitle(const string &t) { title = t; }
void Book::setAuthor(const string &a) { author = a; }
void Book::setCopies(int c) { copies = c; }

string Book::toString() const {
    stringstream ss;
    ss << id << "|" << title << "|" << author << "|" << copies;
    return ss.str();
}

Book Book::fromString(const string &line) {
    stringstream ss(line);
    string part;
    int id, copies;
    string title, author;

    getline(ss, part, '|');
    id = stoi(part);
    getline(ss, title, '|');
    getline(ss, author, '|');
    getline(ss, part, '|');
    copies = stoi(part);

    return Book(id, title, author, copies);
}
