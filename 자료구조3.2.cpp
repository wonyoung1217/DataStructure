#include <iostream>
#include "MyLinkedList.h"
using namespace std;

int main() {
  Node* head = NULL;

  Append_Node(&head, Create_Node(15));
  Append_Node(&head, Create_Node(31));
  Print_Linked_List(head);

  Node* temp = Get_Node(head, 0);
  printf("Get_Node() test: %d \n", temp->data);

  Insert_Node_After(Get_Node(head, 0), Create_Node(25));
  Print_Linked_List(head);

  Remove_Node(&head, Get_Node(head, 0));
  Print_Linked_List(head);
  
  return 0;
}