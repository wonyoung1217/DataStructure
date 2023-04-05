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

void Append_Node(Node** head, Node* newNode) {
    if(*head == NULL) { 
        *head = newNode;
        newNode->link = newNode;
    }
    else { 
        Node* tail = *head;
        while(tail->link != *head) {
            tail = tail->link;
        }
        tail->link = newNode;
        newNode->link = *head;
    }
}

void Print_Circular_Linked_List(Node* head) {
    if (head == NULL) return; 
    Node* iter = head;
    int i = 0;
    do {
        std::cout << "node[" << i << "]:" << iter->data;
        iter = iter->link;
        if (iter != NULL) {
          cout << " -> ";
          i++;
        }
    } while (iter != head); 
    cout << "head:" << iter->data; 
    cout << endl;
}

int main(){
  Node* head = NULL;

  Append_Node(&head, Create_Node(15));
  Append_Node(&head, Create_Node(25));
  Append_Node(&head, Create_Node(31));
  Append_Node(&head, Create_Node(24));

  Print_Circular_Linked_List(head);

  return 0;
}