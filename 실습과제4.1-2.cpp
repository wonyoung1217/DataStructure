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

void Append_Node_T(Node** tail, Node* newNode) {
    if(*tail == NULL) { 
        *tail = newNode;
        newNode->link = newNode;
    }
    else { 
        newNode->link = (*tail)->link;
        (*tail)->link = newNode;
        *tail = newNode;
    }
}

void Print_Circular_Linked_List_T(Node* tail) {
    if (tail == NULL) return;

    Node* head = tail->link; 
    Node* iter = head;

    int i = 0;
    do {
        cout << "node[" << i << "]:" << iter->data;
        iter = iter->link;
        if (iter != head) {
            std::cout << " -> ";
            i++;
        }
    } while (iter != head);
    cout << " -> head:" << head->data << endl;
}

int main(){
  Node* tail = NULL;

  Append_Node_T(&tail, Create_Node(15));
  Append_Node_T(&tail, Create_Node(25));
  Append_Node_T(&tail, Create_Node(31));
  Append_Node_T(&tail, Create_Node(24));

  Print_Circular_Linked_List_T(tail);

  return 0;
}