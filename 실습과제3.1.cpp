#include <iostream>
using namespace std;

struct Node {
    int data;         
    struct Node* link; 
};

Node* Create_Node(int newData) { 
    Node* newNode = new Node; 
    (*newNode).data = newData;
    (*newNode).link = NULL;
    return newNode;
}

void Destroy_Node(Node* node) {
    delete node;  
}

void Append_Node(Node** head, Node* newNode) {
    if (*head == NULL) {
        *head = newNode;
    }
    else {
        Node* tail = *head;
        while ((*tail).link != NULL) {
            tail = (*tail).link;  
        }
        (*tail).link = newNode;
    }
}

void Print_Linked_List(Node* head) { 
    Node* iter = head;
    int i = 0;
    while (iter != NULL) {
        printf("node[%d]:%d", i, iter -> data);
        iter = iter -> link; 
        if (iter != NULL) printf(" -> ");
        i++;
    }
    printf("\n");
}


int main(){
  Node* head = NULL;
  Node* newNode = NULL;

  newNode = Create_Node(15);
  Append_Node(&head, newNode);
  newNode = Create_Node(31);
  Append_Node(&head, newNode);

  Print_Linked_List(head);
  return 0;
}