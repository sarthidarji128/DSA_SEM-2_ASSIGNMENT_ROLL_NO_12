#include <iostream>
#include <cstdlib>
using namespace std;

struct CircularQueue {
  int *array;
  int size; 
  int head; 
  int tail; 
};


void enqueue(CircularQueue *q, int element) {
  if (q->size == q->head + 1) {
    cout << "Queue is full!" << endl;
    return;
  }
  q->array[q->tail] = element; 
  q->tail = (q->tail + 1) % q->size; 
  q->size++; 
}


int dequeue(CircularQueue *q) {
  if (q->size ==  0) { 
    cout << "Queue is empty!" << endl;
    return -1; 
  }
  int element = q->array[q->head];
  q->head = (q->head + 1) % q->size;
  q->size--; 
  return element;
}


int peek(CircularQueue *q) {
  if (q->size == 0) { 
    cout << "Queue is empty!" << endl;
    return -1; 
  }
  return q->array[q->head];
}

int main() {
  CircularQueue q;
  int elements[5]; 
  q.array = elements;
  q.head = 0; 
  q.tail = 0; 

  cout << "Enqueuing elements..." << endl;
  for (int i = 0; i < 5; i++) {
    enqueue(&q, 1+i*4);
  }
  cout << "Dequeuing elements..." << endl;
  for (int i = 0; i < 5; i++) {
    int element = dequeue(&q); 
    cout << element << " ";
  }
  cout << endl;

  return 0;
}