#include <iostream>
using namespace std;
struct Node {
    string name;
    Node* next;
};
Node* head = NULL;
void addEmployee(string name) {
    Node* newNode = new Node();
    newNode->name = name;
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        cout << "Employee added successfully!\n";
        return;
    }
    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
    cout << "Employee added successfully!\n";
}
void deleteEmployee(string name) {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }
    Node *curr = head, *prev = NULL;
    while (curr->name != name) {
        if (curr->next == head) {
            cout << "Employee not found!\n";
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    if (curr->next == head && prev == NULL) {
        head = NULL;
        delete curr;
        cout << "Employee deleted successfully!\n";
        return;
    }
    if (curr == head) {
        prev = head;
        while (prev->next != head)
            prev = prev->next;
        head = head->next;
        prev->next = head;
        delete curr;
        cout << "Employee deleted successfully!\n";
    }
    else if (curr->next == head) { // Last node
        prev->next = head;
        delete curr;
        cout << "Employee deleted successfully!\n";
    }
    else { // Middle node
        prev->next = curr->next;
        delete curr;
        cout << "Employee deleted successfully!\n";
    }
}
void findEmployee(string name) {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }
    Node* temp = head;
    do {
        if (temp->name == name) {
            cout << "Employee '" << name << "' found successfully!\n";
            return;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Employee not found!\n";
}
void displayEmployees() {
    if (head == NULL) {
        cout << "No employees to display!\n";
        return;
    }
    Node* temp = head;
    cout << "Employees: ";
    do {
        cout << temp->name << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}
int main() {
    int choice;
    string name;
    while (true) {
        cout << "\n EMPLOYEE MANAGEMENT MENU " << endl;
        cout << "1. Add Employee" << endl;
        cout << "2. Delete Employee" << endl;
        cout << "3. Find Employee" << endl;
        cout << "4. Display All Employees" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter employee name to add: ";
            cin >> name;
            addEmployee(name);
            break;
        case 2:
            cout << "Enter employee name to delete: ";
            cin >> name;
            deleteEmployee(name);
            break;
        case 3:
            cout << "Enter employee name to find: ";
            cin >> name;
            findEmployee(name);
            break;
        case 4:
            displayEmployees();
            break;
        case 5:
            cout << "Exiting program... Goodbye!\n";
            return 0;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
    return 0;
}

