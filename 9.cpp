#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};


class Stack {
    private:

    Node* top = NULL;

    public:

    Stack() : top(NULL) {}


    void push(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;

        if (top == NULL) {
            top = newNode;
        } else {
            Node* current = top;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
        cout<<"\n"<<newNode->data;
    }


    int pop() {
        if (top == NULL) {
            return -1;
        }

        int data = top->data;
        top = top->next;
        delete top;
        return data;
    }


    bool empty() const {
        return top == NULL;
    }


    int peek() const {
        if (empty()) {
            return -1;
        }
        return top->data;
    }


};

int main() {
    Stack s; 


    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    cout<<"Pushed element";

    return 0;
}