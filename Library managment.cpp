// fucking cod soft

#include <iostream>
#include <string>
#include <map>
using namespace std;

class Library {
private:
    struct Book {
        string author;
        string isbn;
        int quantity;
    };

    map<string, Book> books;

public:
    void displayMenu() {
        cout << "\nLibrary Management System" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. View Books" << endl;
        cout << "3. Search Book" << endl;
        cout << "4. Issue Book" << endl;
        cout << "5. Return Book" << endl;
        cout << "6. Exit" << endl;
    }

    void addBook() {
        string bookName, authorName, isbn;
        int quantity;

        cout << "Enter the book name: ";
        cin.ignore();
        getline(cin, bookName);
        cout << "Enter the author name: ";
        getline(cin, authorName);
        cout << "Enter the ISBN: ";
        getline(cin, isbn);
        cout << "Enter the number of copies: ";
        cin >> quantity;

        if (books.find(bookName) != books.end()) {
            books[bookName].quantity += quantity;
            cout << "Added " << quantity << " more copies of '" << bookName << "'." << endl;
        } else {
            books[bookName] = {authorName, isbn, quantity};
            cout << "Book '" << bookName << "' by " << authorName << " added successfully." << endl;
        }
    }

    void viewBooks() {
        cout << "\nAvailable Books:" << endl;
        if (books.empty()) {
            cout << "No books available in the library." << endl;
        } else {
            for (const auto &book : books) {
                cout << "- " << book.first << " by " << book.second.author
                     << " (ISBN: " << book.second.isbn << ", Copies: " << book.second.quantity << ")" << endl;
            }
        }
    }

    void searchBook() {
        cout << "\nSearch by: 1. Title 2. Author 3. ISBN" << endl;
        int option;
        cin >> option;
        cin.ignore();

        string query;
        cout << "Enter your search query: ";
        getline(cin, query);

        bool found = false;
        for (const auto &book : books) {
            if ((option == 1 && book.first == query) ||
                (option == 2 && book.second.author == query) ||
                (option == 3 && book.second.isbn == query)) {
                cout << "Found: " << book.first << " by " << book.second.author
                     << " (ISBN: " << book.second.isbn << ", Copies: " << book.second.quantity << ")" << endl;
                found = true;
            }
        }

        if (!found) {
            cout << "No matching book found." << endl;
        }
    }

    void issueBook() {
        string bookName;
        int daysLate;

        cout << "Enter the book name to issue: ";
        cin.ignore();
        getline(cin, bookName);

        auto it = books.find(bookName);
        if (it != books.end() && it->second.quantity > 0) {
            it->second.quantity--;
            cout << "You have successfully issued '" << bookName << "'." << endl;
            if (it->second.quantity == 0) {
                cout << "'" << bookName << "' is now out of stock." << endl;
            }
        } else if (it != books.end()) {
            cout << "Sorry, '" << bookName << "' is currently out of stock." << endl;
        } else {
            cout << "'" << bookName << "' is not available in the library." << endl;
        }
    }

    void returnBook() {
        string bookName;
        int daysLate;
        const double finePerDay = 1.5; // Fine amount per day

        cout << "Enter the book name to return: ";
        cin.ignore();
        getline(cin, bookName);

        auto it = books.find(bookName);
        if (it != books.end()) {
            it->second.quantity++;
            cout << "Enter the number of days late (0 if returned on time): ";
            cin >> daysLate;

            if (daysLate > 0) {
                double fine = daysLate * finePerDay;
                cout << "You are late by " << daysLate << " days. Your fine is $" << fine << "." << endl;
            } else {
                cout << "Book returned on time. No fine applied." << endl;
            }

            cout << "You have successfully returned '" << bookName << "'." << endl;
        } else {
            cout << "'" << bookName << "' does not belong to this library." << endl;
        }
    }
};

int main() {
    Library library;
    int choice;

    while (true) {
        library.displayMenu();
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            library.addBook();
            break;
        case 2: 
            library.viewBooks();
            break;
        case 3:
            library.searchBook();
            break;
        case 4:
            library.issueBook();
            break;
        case 5:
            library.returnBook();
            break;
        case 6:
            cout << "Exiting the Library Management System. Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
