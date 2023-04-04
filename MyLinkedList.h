#ifndef __MY_LINKED_LIST_H__
#define __MY_LINKED_LIST_H__

struct Node {
    int data;         
    struct Node* link; 
};

Node* Create_Node(int newData);
void Destroy_Node(Node* node);
void Append_Node(Node** head, Node* newNode);
Node* Get_Node(Node* head, int pos);
void Remove_Node(Node** head, Node* targetNode);
void Insert_Node_After(Node* currentNode, Node* newNode);
void Print_Linked_List(Node* head);

#endif