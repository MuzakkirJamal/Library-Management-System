#include "Library.h"
#include <iostream>
#include <fstream>
using namespace std;

void Library::addBook(const Book &book) {
    books.push_back(book);
}

void Library::viewBooks() const {
    if (books.empty()) {
        cout << "No books in library.\n";
        return;
    }
    for (const auto &book : books) {
        book.display();
    }
}

void Library::searchBook(int id) const {
    for (const auto &book : books) {
        if (book.getId() == id) {
            cout << "Book found:\n";
            book.display();
            return;
        }
    }
    cout << "Book not found.\n";
}

void Library::deleteBook(int id) {
    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->getId() == id) {
            books.erase(it);
            cout << "Book deleted successfully.\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

void Library::issueBook(int id) {
    for (auto &book : books) {
        if (book.getId() == id) {
            if (book.getCopies() > 0) {
                book.setCopies(book.getCopies() - 1);
                cout << "Book issued successfully.\n";
            } else {
                cout << "No copies available.\n";
            }
            return;
        }
    }
    cout << "Book not found.\n";
}

void Library::returnBook(int id) {
    for (auto &book : books) {
        if (book.getId() == id) {
            book.setCopies(book.getCopies() + 1);
            cout << "Book returned successfully.\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

void Library::updateBook(int id) {
    for (auto &book : books) {
        if (book.getId() == id) {
            string title, author;
            int copies;
            cout << "Enter new title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter new author: ";
            getline(cin, author);
            cout << "Enter new copies: ";
            cin >> copies;
            book.setTitle(title);
            book.setAuthor(author);
            book.setCopies(copies);
            cout << "Book updated successfully.\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

void Library::saveToFile() const {
    ofstream fout(filename);
    for (const auto &book : books) {
        fout << book.toString() << endl;
    }
    fout.close();
}

void Library::loadFromFile() {
    ifstream fin(filename);
    if (!fin) return; // no file yet
    string line;
    while (getline(fin, line)) {
        if (!line.empty()) {
            books.push_back(Book::fromString(line));
        }
    }
    fin.close();
}
