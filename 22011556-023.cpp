#include<iostream>
using namespace std;

// Node structure for a linked list
struct Node {
    int data;
    Node* next;
};

// Class for handling linked list operations
class LinkedList {
private:
    Node* head;  // Pointer to the head of the linked list

public:
    // Constructor to initialize an empty linked list
    LinkedList() {
        head = nullptr;
    }

    // Function to insert a new node at the end of the linked list
    void insertAtEnd(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Function to insert a new node at any position in the linked list
    void insertAtPosition(int value, int position) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (position == 1) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            for (int i = 1; i < position - 1 && temp != nullptr; ++i) {
                temp = temp->next;
            }

            if (temp != nullptr) {
                newNode->next = temp->next;
                temp->next = newNode;
            } else {
                cout << "Invalid position." << endl;
            }
        }
    }

    // Function to delete the first node from the linked list
    void deleteFromBeginning() {
        if (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            cout << "List is empty. Cannot delete from beginning." << endl;
        }
    }

    // Function to delete the last node from the linked list
    void deleteFromEnd() {
        if (head != nullptr) {
            if (head->next == nullptr) {
                delete head;
                head = nullptr;
            } else {
                Node* temp = head;
                while (temp->next->next != nullptr) {
                    temp = temp->next;
                }
                delete temp->next;
                temp->next = nullptr;
            }
        } else {
            cout << "List is empty. Cannot delete from end." << endl;
        }
    }

    // Function to delete a node from any position in the linked list
    void deleteFromPosition(int position) {
        if (position == 1) {
            deleteFromBeginning();
        } else {
            Node* temp = head;
            for (int i = 1; i < position - 1 && temp != nullptr; ++i) {
                temp = temp->next;
            }

            if (temp != nullptr && temp->next != nullptr) {
                Node* nodeToDelete = temp->next;
                temp->next = temp->next->next;
                delete nodeToDelete;
            } else {
                cout << "Invalid position." << endl;
            }
        }
    }

    // Function to search for a value in the linked list and update it
    void searchAndUpdate(int valueToSearch, int newValue) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == valueToSearch) {
                temp->data = newValue;
                cout << "Value updated successfully." << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Value not found in the list." << endl;
    }

    // Function to display the linked list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList myList;

    myList.insertAtEnd(10);
    myList.insertAtEnd(20);
    myList.insertAtEnd(30);

    cout << "Original list: ";
    myList.display();

    myList.insertAtPosition(15, 2);
    cout << "List after inserting 15 at position 2: ";
    myList.display();

    myList.deleteFromBeginning();
    cout << "List after deleting from the beginning: ";
    myList.display();

    myList.deleteFromEnd();
    cout << "List after deleting from the end: ";
    myList.display();

    myList.deleteFromPosition(2);
    cout << "List after deleting from position 2: ";
    myList.display();

    myList.searchAndUpdate(20, 25);
    cout << "List after updating value 20 to 25: ";
    myList.display();

    return 0;
}