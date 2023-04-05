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

Node* Get_Node(Node* head, int pos) {
    Node* currNode = head;
    int currPos = 0;
    while (currNode != NULL && currPos < pos) {
        currNode = currNode->link;
        currPos++;
    }
    if (currNode == NULL || currPos < pos) {
        return NULL;
    }
    else {
        return currNode;
    }
}

void Remove_Node(Node** head, Node* targetNode) {
    if (*head == targetNode) {
        *head = targetNode->link;
        Destroy_Node(targetNode);
    }
    else {
        Node* currNode = *head;
        while (currNode != NULL && currNode->link != targetNode) {
            currNode = currNode->link;
        }
        if (currNode != NULL) {
            currNode->link = targetNode->link;
            Destroy_Node(targetNode);
        }
    }
}

void Insert_Node_After(Node* currentNode, Node* newNode) {
    newNode->link = currentNode->link;
    currentNode->link = newNode;
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

Node* Reverse_List(Node* head) {
    Node* p = head;
    Node* q = NULL;
    while (p != NULL) {
        Node* r = q;
        q = p;
        p = p->link;
        q->link = r;
    }
  return q;
}

int main() {
  Node* head = NULL;

  Append_Node(&head, Create_Node(15));
  Append_Node(&head, Create_Node(25));
  Append_Node(&head, Create_Node(31));
  Append_Node(&head, Create_Node(24));
  
  Print_Linked_List(head);

  Node* reverse = Reverse_List(head);

  Print_Linked_List(reverse);
  cout << endl;
  
  return 0;
}