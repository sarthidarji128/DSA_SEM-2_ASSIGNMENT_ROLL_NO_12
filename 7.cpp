#include <iostream>
using namespace std;
struct Node {
    int data; 
    Node* next; 
};
class LinkedList {
    private:
        Node* head;
        int size; 
    public:
        LinkedList() {
            head = NULL; 
            size = 0; 
        }

        ~LinkedList() {
            Node* temp = head;
            while (temp != NULL) {
                Node* next = temp->next;
                delete temp;
                temp = next;
            }
        }
        Node* createNode(int data) {
            Node* newNode = new Node; 
            newNode->data = data; 
            newNode->next = NULL; 
            return newNode; 
        }
        void insertAtBeginning(int data) {
            Node* newNode = createNode(data); 
            newNode->next = head; 
            head = newNode; 
            size++; 
            cout << "Node inserted at the beginning.\n";
        }
        void insertAtEnd(int data) {
            Node* newNode = createNode(data); 
            if (head == NULL) { 
                head = newNode; 
            }
            else { 
                Node* temp = head; 
                while (temp->next != NULL) { 
                    temp = temp->next;
                }
                temp->next = newNode; 
            }
            size++; 
            cout << "Node inserted at the end.\n";
        }
        void insertBeforeElement(int data, int element) {
            Node* newNode = createNode(data); 
            if (head == NULL) { 
                cout << "List is empty.\n";
            }
            else if (head->data == element) { 
                newNode->next = head; 
                head = newNode;
                size++; 
                cout << "Node inserted before " << element << ".\n";
            }
            else { 
                Node* temp = head; 
                Node* prev = NULL; 
                while (temp != NULL && temp->data != element) { 
                    prev = temp; 
                    temp = temp->next; 
                }
                if (temp == NULL) { 
                    cout << "Element not found.\n";
                }
                else { 
                    newNode->next = temp; 
                    prev->next = newNode; 
                    size++; 
                    cout << "Node inserted before " << element << ".\n";
                }
            }
        }
        void insertAfterElement(int data, int element) {
            Node* newNode = createNode(data); 
            if (head == NULL) { 
                cout << "List is empty.\n";
            }
            else {
                Node* temp = head; 
                while (temp != NULL && temp->data != element) { 
                    temp = temp->next;
                }
                if (temp == NULL) { 
                    cout << "Element not found.\n";
                }
                else {
                    newNode->next = temp->next; 
                    temp->next = newNode; 
                    size++;
                    cout << "Node inserted after " << element << ".\n";
                }
            }
        }
        void deleteFromBeginning() {
            if (head == NULL) {
                cout << "List is empty.\n";
            }
            else { 
                Node* temp = head;
                head = head->next; 
                delete temp; 
                size--; 
                cout << "Node deleted from the beginning.\n";
            }
        }
        void deleteFromEnd() {
            if (head == NULL) { 
                cout << "List is empty.\n";
            }
            else if (head->next == NULL) { 
                delete head; 
                head = NULL; 
                size--; 
                cout << "Node deleted from the end.\n";
            }
            else { 
                Node* temp = head;
                Node* prev = NULL;
                while (temp->next != NULL) { 
                    prev = temp; 
                    temp = temp->next;
                }
                delete temp; 
                prev->next = NULL;
                size--; 
                cout << "Node deleted from the end.\n";
            }
        }
        void deleteBeforeElement(int element) {
            if (head == NULL) { 
                cout << "List is empty.\n";
            }
            else if (head->data == element) { 
                cout << "No node before " << element << ".\n";
            }
            else if (head->next->data == element) { 
                Node* temp = head; 
                head = head->next; 
                delete temp; 
                size--; 
                cout << "Node deleted before " << element << ".\n";
            }
            else { 
                Node* temp = head; 
                Node* prev = NULL; 
                Node* before = NULL;
                while (temp != NULL && temp->data != element) { 
                    before = prev; 
                    prev = temp; 
                    temp = temp->next; 
                }
                if (temp == NULL) { 
                    cout << "Element not found.\n";
                }
                else { 
                    delete prev; 
                    before->next = temp;
                    size--; 
                    cout << "Node deleted before " << element << ".\n";
                }
            }
        }
        void deleteAfterElement(int element) {
            Node* temp = head; 
            while (temp != NULL && temp->data != element) { 
                temp = temp->next; 
            }
            if (temp == NULL) { 
                cout << "Element not found.\n";
            }
            else if (temp->next == NULL) { 
                cout << "No node after " << element << ".\n";
            }
            else { 
                Node* next = temp->next; 
                temp->next = next->next; 
                delete next; 
                cout << "Node deleted after " << element << ".\n";
            }
        }
            bool search(int data) {
            Node* temp = head; 
            while (temp != NULL) { 
                if (temp->data == data) {
                    return true;
                }
            temp = temp->next;
            }
            return false; 
        }
        void display() {
            Node* temp = head; 
            cout << "The list contains: ";
            while (temp != NULL) { 
                cout << temp->data << " "; 
                temp = temp->next; 
            }
            cout << endl;
        }
};


int main() {
    LinkedList list; 
    int choice, data, element;
    bool exit = false;
    while (!exit) { 
        cout << "Menu:\n";
        cout << "1. Display the list\n";
        cout << "2. Insert node at beginning\n";
        cout << "3. Insert node at end\n";
        cout << "4. Insert node before element\n";
        cout << "5. Insert node after element\n";
        cout << "6. Delete node at beginning\n";
        cout << "7. Delete node at end\n";
        cout << "8. Delete node before element\n";
        cout << "9. Delete node after element\n";
        cout << "10. Search the element\n";
        cout << "11. Exit the program\n";
        cout << "Enter your choice: ";
        cin >> choice; 
        switch (choice) { 
            case 1:
                list.display();
                break;
            case 2: 
                cout << "Enter the data to insert: ";
                cin >> data; 
                list.insertAtBeginning(data);
                break;
            case 3:
                cout << "Enter the data to insert: ";
                cin >> data; 
                list.insertAtEnd(data);
                break;
            case 4: 
                cout << "Enter the data to insert: ";
                cin >> data; 
                cout << "Enter the element before which to insert: ";
                cin >> element; 
                list.insertBeforeElement(data, element);
                break;
            case 5: 
                cout << "Enter the data to insert: ";
                cin >> data; 
                cout << "Enter the element after which to insert: ";
                cin >> element; 
                list.insertAfterElement(data, element);
                break;
            case 6: 
                list.deleteFromBeginning();
                break;
            case 7:
                list.deleteFromEnd();
                break;
            case 8: 
                cout << "Enter the element before which to delete: ";
                cin >> element;
                list.deleteBeforeElement(element);
                break;
            case 9: 
                cout << "Enter the element after which to delete: ";
                cin >> element; 
                list.deleteAfterElement(element);
                break;
            case 10: 
                cout << "Enter the element to search: ";
                cin >> element; 
                list.search(element);
                break;
            case 11: 
                exit = true; 
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
    return 0;
}