#ifndef __MY_ARRAY_STACK_H__
#define __MY_ARRAY_STACK_H__
#include <cstdio>
#include <cstdlib>
#define STACK_LEN 100
typedef enum {F, T}Bool;
typedef int Data; //Data 타입 정의 
typedef struct MyArrayStack {
  Data arr[STACK_LEN];
  int top;
}ArrStack;
//Array Stack 구조체 선언
void Stack_Init(ArrStack* pStack);
void Stack_Push(ArrStack* pStack, Data item); //데이터 삽입 
Data Stack_Pop(ArrStack* pStack); //데이터 인출
Data Stack_Peek(ArrStack* pStack); //최상단 데이터 확인
Bool Stack_IsEmpty(ArrStack* pStack); //스택이 비어있는지 확인
Bool Stack_IsFull(ArrStack* pStack);
#endif