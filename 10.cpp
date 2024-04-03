#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};
class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }
    int dequeue() {
        if (front == nullptr) {
            cerr << "Queue is empty" << endl;
            return -1; 
        }
        Node* temp = front;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        int data = temp->data;
        delete temp;
        return data;
    }
    int peek() {
        if (front == nullptr) {
            cerr << "Queue is empty" << endl;
            return -1;
        }
        return front->data;
    }


    bool isEmpty() {
        return front == nullptr;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(50);
    cout << "Front element is: " << q.peek() << endl;
    cout << "Removed element: " << q.dequeue() << endl;
    cout << "Removed element: " << q.dequeue() << endl;
    cout << "Removed element: " << q.dequeue() << endl;
    cout << "Front element is now: " << q.peek() << endl;

    return 0;
}
