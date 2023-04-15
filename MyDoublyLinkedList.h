#ifndef __MY_DOUBLY_LINKED_LIST_H__ 
#define __MY_DOUBLY_LINKED_LIST_H__ 

struct Node { 
  int data; 
  struct Node* prev; 
  struct Node* next;
};

Node* DLL_Create_Node(int newData); //노드 생성
void DLL_Destroy_Node(Node* node); //노드 소멸
void DLL_Append_Node(Node** head, Node* newNode);
Node* DLL_Get_Node(Node* head, int pos);
void DLL_Remove_Node(Node** head, Node* targetNode); //노드 삭제
void DLL_Insert_Node_After(Node* currentNode, Node* newNode); //노드 삽입 
void DLL_Print_Linked_List(Node* head); //이중 연결리스트 출력
void DLL_Print_Linked_List_Reverse(Node* tail);//이중 연결리스트 역순 출력 

#endif