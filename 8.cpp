#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    LinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (tail == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void insertBeforeElement(int data, int element) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        if (head->data == element) {
            newNode->next = head;
            head = newNode;
            size++;
            return;
        }
        Node* current = head;
        while (current->next != NULL && current->next->data != element) {
            current = current->next;
        }
        if (current->next == NULL) {
            cout << "Element not found.\n";
            return;
        }
        newNode->next = current->next;
        current->next = newNode;
        size++;
    }

    void insertAfterElement(int data, int element) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        Node* current = head;
        while (current != NULL && current->data != element) {
            current = current->next;
        }
        if (current == NULL) {
            cout << "Element not found.\n";
            return;
        }
        newNode->next = current->next;
        current->next = newNode;
        size++;
    }

    void deleteFromBeginning() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    void deleteFromEnd() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        if (head->next == NULL) {
            delete head;
            head = tail = NULL;
            size--;
            return;
        }
        Node* current = head;
        while (current->next->next != NULL) {
            current = current->next;
        }
        delete current->next;
        current->next = NULL;
        tail = current;
        size--;
    }

    void search(int data) {
        Node* current = head;
        while (current != NULL && current->data != data) {
            current = current->next;
        }
        if (current == NULL) {
            cout << "Element not found.\n";
        } else {
            cout << "Element found: " << data << "\n";
        }
    }

    void display() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList ll;
    ll.insertAtBeginning(01);
    ll.insertAtEnd(52);
    ll.insertAtEnd(12);
    ll.insertAtEnd(23);
    ll.insertBeforeElement(3, 2);
    ll.insertAfterElement(4, 2);
    ll.display(); 
    ll.deleteFromBeginning();
    ll.deleteFromEnd();
    ll.search(8);
    ll.display(); 
    return 0;
}
