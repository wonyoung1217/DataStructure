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

Node* Merge_List(Node* head_a, Node* head_b) {
    Node* head_c = NULL;
    Node** tail_c = &head_c;
    
    while (head_a != NULL && head_b != NULL) {
        if (head_a->data < head_b->data) {
            *tail_c = Create_Node(head_a->data);
            tail_c = &((*tail_c)->link);
            head_a = head_a->link;
        }
        else {
            *tail_c = Create_Node(head_b->data);
            tail_c = &((*tail_c)->link);
            head_b = head_b->link;
        }
    }
    
    while (head_a != NULL) {
        *tail_c = Create_Node(head_a->data);
        tail_c = &((*tail_c)->link);
        head_a = head_a->link;
    }
    
    while (head_b != NULL) {
        *tail_c = Create_Node(head_b->data);
        tail_c = &((*tail_c)->link);
        head_b = head_b->link;
    }
    
    return head_c;
}

void Print_Linked_List(Node* head) { 
    Node* iter = head;
    int i = 0;
    while (iter != NULL) {
        printf("N[%d]:%d", i, iter -> data);
        iter = iter -> link; 
        if (iter != NULL) printf(" -> ");
        i++;
    }
    printf("\n");
}


int main() {
  Node* head_a = NULL;
  Node* head_b = NULL;
  Node* head_c = NULL;
  
  //a 연결리스트 구성 
  Append_Node(&head_a, Create_Node(10)); 
  Append_Node(&head_a, Create_Node(20)); 
  Append_Node(&head_a, Create_Node(30)); 
  
  //b 연결리스트 구성 
  Append_Node(&head_b, Create_Node(15)); 
  Append_Node(&head_b, Create_Node(25)); 
  Append_Node(&head_b, Create_Node(27)); 
  Append_Node(&head_b, Create_Node(28)); 
  
  //a,b 연결리스트 출력 
  Print_Linked_List(head_a); 
  Print_Linked_List(head_b); 
  
  //연결리스트 합병 함수 호출
  head_c = Merge_List(head_a, head_b); 
  
  //합병된 연결리스트 출력 
  Print_Linked_List(head_c);
  
  return 0;
}