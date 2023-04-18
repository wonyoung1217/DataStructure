#include <iostream>
#include "MyArrayStack.h"
using namespace std;

void Stack_Init(ArrStack* pStack) {
    pStack->top = -1;
}

void Stack_Push(ArrStack* pStack, Data item) {
    if (Stack_IsFull(pStack)) {
        cout << "Stack is full." << endl;
        return;
    }
    pStack->arr[++(pStack->top)] = item;
}

Data Stack_Pop(ArrStack* pStack) {
    if (Stack_IsEmpty(pStack)) {
        cout << "Stack is empty." << endl;
        exit(-1);
    }
    return pStack->arr[(pStack->top)--];
}

Data Stack_Peek(ArrStack* pStack) {
    if (Stack_IsEmpty(pStack)) {
        cout << "Stack is empty." << endl;
        exit(-1);
    }
    return pStack->arr[pStack->top];
}

Bool Stack_IsEmpty(ArrStack* pStack) {
    return pStack->top == -1 ? T : F;
}

Bool Stack_IsFull(ArrStack* pStack) {
    return pStack->top == STACK_LEN - 1 ? T : F;
}