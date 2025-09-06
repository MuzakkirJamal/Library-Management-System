#include "Library.h"
#include <iostream>
#include <windows.h>  // For colors (Windows only)
using namespace std;

// Function to set console text color
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Function to clear screen
void clearScreen() {
    system("cls");
}

// Function to print menu
void printMenu() {
    setColor(14); // Yellow
    cout << "=====================================\n";
    cout << "         📚 Library Management        \n";
    cout << "=====================================\n";
    setColor(11); // Cyan
    cout << "1. ➕ Add Book\n";
    cout << "2. 📖 View Books\n";
    cout << "3. 🔍 Search Book\n";
    cout << "4. ❌ Delete Book\n";
    cout << "5. 📤 Issue Book\n";
    cout << "6. 📥 Return Book\n";
    cout << "7. ✏️ Update Book\n";
    cout << "8. 🚪 Exit\n";
    setColor(14);
    cout << "=====================================\n";
    setColor(15); // Reset to white
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    Library lib;
    lib.loadFromFile();

    int choice;
    do {
        clearScreen();
        printMenu();
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int id, copies;
            string title, author;
            cout << "Enter ID: "; cin >> id;
            cin.ignore();
            cout << "Enter Title: "; getline(cin, title);
            cout << "Enter Author: "; getline(cin, author);
            cout << "Enter Copies: "; cin >> copies;
            lib.addBook(Book(id, title, author, copies));
            cout << "Book added successfully!\n";
            system("pause");
        }
        else if (choice == 2) {
            lib.viewBooks();
            system("pause");
        }
        else if (choice == 3) {
            int id;
            cout << "Enter Book ID to search: ";
            cin >> id;
            lib.searchBook(id);
            system("pause");
        }
        else if (choice == 4) {
            int id;
            cout << "Enter Book ID to delete: ";
            cin >> id;
            lib.deleteBook(id);
            system("pause");
        }
        else if (choice == 5) {
            int id;
            cout << "Enter Book ID to issue: ";
            cin >> id;
            lib.issueBook(id);
            system("pause");
        }
        else if (choice == 6) {
            int id;
            cout << "Enter Book ID to return: ";
            cin >> id;
            lib.returnBook(id);
            system("pause");
        }
        else if (choice == 7) {
            int id;
            cout << "Enter Book ID to update: ";
            cin >> id;
            lib.updateBook(id);
            system("pause");
        }
        else if (choice == 8) {
            lib.saveToFile();
            setColor(10); // Green
            cout << "\n✅ Exiting... Data saved successfully.\n";
            setColor(15);
        }
        else {
            setColor(12); // Red
            cout << "Invalid choice! Try again.\n";
            setColor(15);
            system("pause");
        }

    } while (choice != 8);

    return 0;
}
