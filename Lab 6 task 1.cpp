#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
Node* head = NULL;
void insertBefore(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }
    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;
    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}
void insertAfter(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }
    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}
void deleteNode(int value) {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }
    Node *curr = head, *prev = NULL;

    while (curr->data != value) {
        if (curr->next == head) {
            cout << "Node not found!\n";
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    if (curr->next == head && prev == NULL) {
        head = NULL;
        delete curr;
        return;
    }
    if (curr == head) {
        prev = head;
        while (prev->next != head)
            prev = prev->next;
        head = head->next;
        prev->next = head;
        delete curr;
    }
    else if (curr->next == head) { // Last node
        prev->next = head;
        delete curr;
    }
    else { 
        prev->next = curr->next;
        delete curr;
    }
}
void display() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }
    Node* temp = head;
    cout << "Circular Linked List: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}
int main() {
    int choice, value;
    while (true) {
        cout << "\n SELECT FROM THE FOLLOWING MENU " << endl;
        cout << "1. Insert Before (at beginning)" << endl;
        cout << "2. Insert After (at end)" << endl;
        cout << "3. Delete Node" << endl;
        cout << "4. Display List" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter value to insert at beginning: ";
            cin >> value;
            insertBefore(value);
            cout << "Node inserted at beginning.\n";
            break;
        case 2:
            cout << "Enter value to insert at end: ";
            cin >> value;
            insertAfter(value);
            cout << "Node inserted at end.\n";
            break;
        case 3:
            cout << "Enter value to delete: ";
            cin >> value;
            deleteNode(value);
            break;
        case 4:
            display();
            break;
        case 5:
            cout << "Exiting program... Goodbye!\n";
            return 0;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    }
    return 0;
}

