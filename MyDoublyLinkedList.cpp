#include <iostream>

struct Node { 
  int data; 
  Node* prev;
  Node* next;
};

// 노드 생성
Node* DLL_Create_Node(int newData) {
  Node* newNode = new Node;
  newNode->data = newData;
  newNode->prev = NULL;
  newNode->next = NULL;
  return newNode;
}

void DLL_Destroy_Node(Node* node) {
  if (node != NULL) {
    delete node;
  }
}

// 노드 추가
void DLL_Append_Node(Node** head, Node* newNode) {
  if (*head == NULL) {
    *head = newNode;
  } else {
    Node* tail = *head;
    while (tail->next != NULL) {
      tail = tail->next;
    }
    tail->next = newNode;
    newNode->prev = tail;
  }
}

// 노드 탐색
Node* DLL_Get_Node(Node* head, int pos) {
  Node* current = head;
  int index = 0;
  while (current != NULL && index != pos) {
    current = current->next;
    index++;
  }
  return current;
}

// 노드 삭제
void DLL_Remove_Node(Node** head, Node* targetNode) {
  if (*head == targetNode) {
    *head = targetNode->next;
    if (*head != NULL) {
      (*head)->prev = NULL;
    }
  } else {
    Node* current = *head;
    while (current != NULL && current != targetNode) {
      current = current->next;
    }
    if (current != NULL) {
      current->prev->next = current->next;
      if (current->next != NULL) {
        current->next->prev = current->prev;
      }
    }
  }
  DLL_Destroy_Node(targetNode);
}

// 노드 삽입
void DLL_Insert_Node_After(Node* currentNode, Node* newNode) {
  newNode->prev = currentNode;
  newNode->next = currentNode->next;
  currentNode->next = newNode;
  if (newNode->next != NULL) {
    newNode->next->prev = newNode;
  }
}

void DLL_Print_Linked_List(Node* head) {
    Node* iter = head;
    int i = 0;
    while (iter != NULL) {
        std::cout << "N[" << i << "]: " << iter->data;
        iter = iter->next;
        if (iter != NULL) {
            std::cout << " <-> ";
        }
        i++;
    }
    std::cout << std::endl;
}

// 역순 출력
void DLL_Print_Linked_List_Reverse(Node* tail) {
    Node* iter = tail;
    int i = 0;
    while (iter != NULL) {
        std::cout << "N[" << i << "]: " << iter->data;
        iter = iter->prev;
        if (iter != NULL) {
            std::cout << " <-> ";
        }
        i++;
    }
    std::cout << std::endl;
}

