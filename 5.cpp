#include <iostream>
#include <cstdlib>
using namespace std;

class LinearQueue {
public:
    LinearQueue(int size) {
        data = new int[size];
        front = back = 0;
        this->size = size;
    }

    void enqueue(int element) {
        if (isFull()) {
            cout << "Error: Queue is full!" << endl;
            return;
        }
        data[back++] = element;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Error: Queue is empty!" << endl;
            return -1;
        }
        int element = data[front++];
        return element;
    }

    bool isFull() const {
        return back == size;
    }

    bool isEmpty() const {
        return front == back;
    }

private:
    int* data;
    int front, back;
    int size;
};

int main() {
    LinearQueue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    cout << "Dequeued elements: ";
    while (!q.isEmpty()) {
        int element = q.dequeue();
        cout << element << " ";
    }
    return 0;
}
