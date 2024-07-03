#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

// Book class
class Book {
public:
    string title;
    string author;
    int id;
    bool isAvailable;

    Book(string title, string author, int id) {
        this->title = title;
        this->author = author;
        this->id = id;
        this->isAvailable = true;
    }
};

// Borrower class
class Borrower {
public:
    string name;
    int id;
    vector<Book*> borrowedBooks;

    Borrower(string name, int id) {
        this->name = name;
        this->id = id;
    }
};

// Library class
class Library {
public:
    vector<Book*> books;
    vector<Borrower*> borrowers;
    map<int, Book*> bookMap;
    map<int, Borrower*> borrowerMap;

    void addBook(string title, string author, int id) {
        Book* book = new Book(title, author, id);
        books.push_back(book);
        bookMap[id] = book;
    }

    void addBorrower(string name, int id) {
        Borrower* borrower = new Borrower(name, id);
        borrowers.push_back(borrower);
        borrowerMap[id] = borrower;
    }

    void borrowBook(int bookId, int borrowerId) {
        if (bookMap.find(bookId)!= bookMap.end() && borrowerMap.find(borrowerId)!= borrowerMap.end()) {
            Book* book = bookMap[bookId];
            Borrower* borrower = borrowerMap[borrowerId];
            if (book->isAvailable) {
                book->isAvailable = false;
                borrower->borrowedBooks.push_back(book);
                cout << "Book borrowed successfully!" << endl;
            } else {
                cout << "Book is not available!" << endl;
            }
        } else {
            cout << "Book or borrower not found!" << endl;
        }
    }

    void returnBook(int bookId, int borrowerId) {
        if (bookMap.find(bookId)!= bookMap.end() && borrowerMap.find(borrowerId)!= borrowerMap.end()) {
            Book* book = bookMap[bookId];
            Borrower* borrower = borrowerMap[borrowerId];
            for (int i = 0; i < borrower->borrowedBooks.size(); i++) {
                if (borrower->borrowedBooks[i]->id == bookId) {
                    book->isAvailable = true;
                    borrower->borrowedBooks.erase(borrower->borrowedBooks.begin() + i);
                    cout << "Book returned successfully!" << endl;
                    return;
                }
            }
            cout << "Book not found in borrower's list!" << endl;
        } else {
            cout << "Book or borrower not found!" << endl;
        }
    }

    void displayBooks() {
        cout << "Books:" << endl;
        for (int i = 0; i < books.size(); i++) {
            cout << "Title: " << books[i]->title << ", Author: " << books[i]->author << ", ID: " << books[i]->id << ", Available: " << (books[i]->isAvailable? "Yes" : "No") << endl;
        }
    }

    void displayBorrowers() {
        cout << "Borrowers:" << endl;
        for (int i = 0; i < borrowers.size(); i++) {
            cout << "Name: " << borrowers[i]->name << ", ID: " << borrowers[i]->id << endl;
            cout << "Borrowed Books:" << endl;
            for (int j = 0; j < borrowers[i]->borrowedBooks.size(); j++) {
                cout << "Title: " << borrowers[i]->borrowedBooks[j]->title << ", Author: " << borrowers[i]->borrowedBooks[j]->author << ", ID: " << borrowers[i]->borrowedBooks[j]->id << endl;
            }
        }
    }
};

int main() {
    Library library;

    library.addBook("Book 1", "Author 1", 1);
    library.addBook("Book 2", "Author 2", 2);
    library.addBook("Book 3", "Author 3", 3);

    library.addBorrower("Borrower 1", 1);
    library.addBorrower("Borrower 2", 2);

    library.displayBooks();
    library.displayBorrowers();

    library.borrowBook(1, 1);
    library.borrowBook(2, 1);

    library.displayBooks();
    library.displayBorrowers();

    library.returnBook(1, 1);

    library.displayBooks();
    library.displayBorrowers();

    return 0;
}
