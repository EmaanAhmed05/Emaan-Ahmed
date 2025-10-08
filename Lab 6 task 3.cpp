#include <iostream>
using namespace std;
class Book {
    string bookId, bookName, bookAuthor, bookISBN;
    double bookPrice;
public:
    Book() {}
    Book(string id, string name, double price, string author, string isbn) {
        bookId = id;
        bookName = name;
        bookPrice = price;
        bookAuthor = author;
        bookISBN = isbn;
    }
    string getId() { return bookId; }
    string getName() { return bookName; }
    double getPrice() { return bookPrice; }
    string getAuthor() { return bookAuthor; }
    string getISBN() { return bookISBN; }
    void setDetails(string name, double price, string author, string isbn) {
        bookName = name;
        bookPrice = price;
        bookAuthor = author;
        bookISBN = isbn;
    }
    void display() {
        cout << "ID: " << bookId
             << "  Name: " << bookName
             << "  Author: " << bookAuthor
             << "  Price: " << bookPrice
             << "  ISBN: " << bookISBN << endl;
    }
};
class Node {
public:
    Book book;
    Node* next;
    Node* prev;

    Node(Book b) {
        book = b;
        next = prev = NULL;
    }
};
class BookList {
    Node* head;
public:
    BookList() {
        head = NULL;
    }
    void addBook(string id, string name, double price, string author, string isbn) {
        Book b(id, name, price, author, isbn);
        Node* newNode = new Node(b);
        if (head == NULL) {
            head = newNode;
            head->next = head->prev = head;
            cout << "Book added successfully!\n";
            return;
        }
        Node* last = head->prev;
        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
        cout << "Book added successfully!\n";
    }
    void removeBook(string id) {
        if (head == NULL) {
            cout << "No books to remove!\n";
            return;
        }
        Node* temp = head;
        do {
            if (temp->book.getId() == id) {
                if (temp->next == temp) { // only one book
                    head = NULL;
                } else {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    if (temp == head)
                        head = temp->next;
                }
                delete temp;
                cout << "Book removed successfully!\n";
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Book with ID " << id << " not found!\n";
    }
    void updateBook(string id, string name, double price, string author, string isbn) {
        if (head == NULL) {
            cout << "No books to update!\n";
            return;
        }
        Node* temp = head;
        do {
            if (temp->book.getId() == id) {
                temp->book.setDetails(name, price, author, isbn);
                cout << "Book updated successfully!\n";
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Book with ID " << id << " not found!\n";
    }
    void printBooks() {
        if (head == NULL) {
            cout << "No books in the list!\n";
            return;
        } 
        Node* temp = head;
        cout << "\n_____ Book List _____\n";
        do {
            temp->book.display();
            temp = temp->next;
        } while (temp != head);
        cout << "________________\n";
    }
    void printBook(string id) {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        do {
            if (temp->book.getId() == id) {
                cout << "\nBook Details:\n";
                temp->book.display();
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Book with ID " << id << " not found!\n";
    }
};
int main() {
    BookList bl;
    int choice;
    string id, name, author, isbn;
    double price;
    while (true) {
        cout << "\n_____ Book Management Menu _____" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Remove Book" << endl;
        cout << "3. Update Book" << endl;
        cout << "4. Print All Books" << endl;
        cout << "5. Print Specific Book" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter Book ID: ";
            cin >> id;
            cout << "Enter Book Name: ";
            cin >> name;
            cout << "Enter Price: ";
            cin >> price;
            cout << "Enter Author: ";
            cin >> author;
            cout << "Enter ISBN: ";
            cin >> isbn;
            bl.addBook(id, name, price, author, isbn);
            break;
        case 2:
            cout << "Enter Book ID to remove: ";
            cin >> id;
            bl.removeBook(id);
            break;
        case 3:
            cout << "Enter Book ID to update: ";
            cin >> id;
            cout << "Enter New Book Name: ";
            cin >> name;
            cout << "Enter New Price: ";
            cin >> price;
            cout << "Enter New Author: ";
            cin >> author;
            cout << "Enter New ISBN: ";
            cin >> isbn;
            bl.updateBook(id, name, price, author, isbn);
            break;
        case 4:
            bl.printBooks();
            break;
        case 5:
            cout << "Enter Book ID to print: ";
            cin >> id;
            bl.printBook(id);
            break;
        case 6:
            cout << "Exiting program... Goodbye!\n";
            return 0;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
    return 0;
}

