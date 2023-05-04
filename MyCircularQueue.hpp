#ifndef __MY_CIRCULAR_QUEUE_HPP__ 
#define __MY_CIRCULAR_QUEUE_HPP__ 
#define QUEUE_SIZE 100
template <typename T>
class CircularQueue {
private:
  int front; 
  int rear; 
  T* arr; 
  int qSize;
public:
  CircularQueue(){ 
    front = 0;
    rear = 0;
    arr = new T[QUEUE_SIZE];
    qSize = QUEUE_SIZE;
  }
  CircularQueue(int size) {
    front = 0;
    rear = 0;
    arr = new T[size];
    qSize = size;
  }

  bool IsEmpty() {
    return (front == -1 && rear == -1);
  }

  bool IsFull() {
    return ((rear + 1) % qSize == front);
  }

  bool Enqueue(T item) {
    if (IsFull()) {
      return false; 
    }
    else if (IsEmpty()) {
      front = 0;
      rear = 0;
    }
    else {
      rear = (rear + 1) % qSize;
    }
    arr[rear] = item;
    return true;
  }

  T Dequeue() {
    if (IsEmpty()) {
      return T(); 
    }
    else if (front == rear) {
      T data = arr[front];
      front = -1;
      rear = -1;
      return data;
    }
    else {
      T data = arr[front];
      front = (front + 1) % qSize;
      return data;
    }
  }

  T Peek() {
    if (IsEmpty()) {
      return T(); 
    }
    else {
      return arr[front];
    }
  }

  ~CircularQueue() {
    delete[] arr; 
  }
};
#endif
