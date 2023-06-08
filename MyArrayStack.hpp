#ifndef __MY_ARRAY_STACK_HPP__ 
#define __MY_ARRAY_STACK_HPP__ 

#include <cstdio>
#include <cstdlib>

#define STACK_LEN 100 

template <typename T> 
class ArrStack { 
private:
  T* arr;
  int length; 
  int top;
public:
  ArrStack() {
    top = -1;
    length = STACK_LEN;
    arr = new T[STACK_LEN]; 
  }
  
  ArrStack(int len) {
    top = -1;
    length = len;
    arr = new T[len]; 
  }
   
  void Stack_Init() { // 배열 스택 초기화
    top = -1;
  }

  void Stack_Push(T item) { // 데이터 삽입
    if (Stack_IsFull()) {
      printf("Stack is full.\n");
      return;
    }
    arr[++top] = item;
  }

  T Stack_Pop() { // 데이터 인출
    if (Stack_IsEmpty()) {
      printf("Stack is empty.\n");
      exit(1);
    }
    return arr[top--];
  }

  T Stack_Peek() { // 최상단 데이터 확인
    if (Stack_IsEmpty()) {
      printf("Stack is empty.\n");
      exit(1);
    }
    return arr[top];
  }

  bool Stack_IsEmpty() { // 스택이 비어있는지 확인
    return top == -1;
  }

  bool Stack_IsFull() { // 스택이 가득 차 있는지 확인
    return top == length - 1;
  }
};

#endif
