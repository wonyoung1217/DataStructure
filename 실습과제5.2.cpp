#include <iostream> 
#include <cstring>
#include "MyArrayStack.hpp" 
using namespace std;

int IsOperator(char token) {
    return (token == '+' || token == '-' || token == '*' || token == '/');
}

int Priority(char op) {
    switch(op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

void Infix2Postfix(const char* infix_exp, char* postfix_exp) {
    int len = strlen(infix_exp);
    int k = 0;

    ArrStack<char> s; // 스택 객체 생성

    for(int i = 0; i < len; i++) {
        char token = infix_exp[i];

        if(isdigit(token)) {
            postfix_exp[k++] = token;
        }
        else if(IsOperator(token)) {
            while(!s.Stack_IsEmpty() && Priority(token) <= Priority(s.Stack_Peek())) {
                postfix_exp[k++] = s.Stack_Peek();
                s.Stack_Pop();
            }
            s.Stack_Push(token);
        }
        else if(token == '(') {
            s.Stack_Push(token);
        }
        else if(token == ')') {
            while(!s.Stack_IsEmpty() && s.Stack_Peek() != '(') {
                postfix_exp[k++] = s.Stack_Peek();
                s.Stack_Pop();
            }
            s.Stack_Pop(); // pop '('
        }
    }

    while(!s.Stack_IsEmpty()) {
        postfix_exp[k++] = s.Stack_Peek();
        s.Stack_Pop();
    }

    postfix_exp[k] = '\0';
}

int IsDigit(char token) {
    return isdigit(token);
}

int Eval_Postfix(char* postfix_exp) {
    ArrStack<int> s; // 스택 객체 생성

    for(int i = 0; postfix_exp[i] != '\0'; i++) {
        char token = postfix_exp[i];

        if(isdigit(token)) {
            s.Stack_Push(token - '0'); // char to int conversion
        }
        else if(IsOperator(token)) {
            int op2 = s.Stack_Peek(); s.Stack_Pop();
            int op1 = s.Stack_Peek(); s.Stack_Pop();
            switch(token) {
                case '+':
                    s.Stack_Push(op1 + op2);
                    break;
                case '-':
                    s.Stack_Push(op1 - op2);
                    break;
                case '*':
                    s.Stack_Push(op1 * op2);
                    break;
                case '/':
                    s.Stack_Push(op1 / op2);
                    break;
            }
        }
    }

    return s.Stack_Peek();
}

int main(void) {
  char exp[] = "(2+5)*(3+4)-(2+(7-5))"; //계산할 수식 
  char* postfix = new char[strlen(exp) + 1]; //후위식 변환 결과 
  //1) 중위식에서 후위식으로 변환
  Infix2Postfix(exp, postfix); //중위식에서 후위식으로 변환 
  printf("Infix: %s\n", exp);
  printf("Postfix: %s\n", postfix); //변환 결과 출력 
  //2) 변환된 후위식을 계산
  int result = Eval_Postfix(postfix);
  printf("%s = %d \n", postfix, result);
  return 0; 
}