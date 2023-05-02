#include <iostream>
#include <cmath>
using namespace std;

void PrintTree2Matrix(int** M, int* bTree, int size, int idx, int col, int row, int height) { 
  if (idx >size) return;
  M[row][col] = bTree[idx];
  PrintTree2Matrix(M, bTree, size, idx*2, col - pow(2, height - 2), row + 1, height - 1);      
  PrintTree2Matrix(M, bTree, size, idx*2+1,col + pow(2, height - 2), row + 1, height - 1);
}

void TreePrinter(int* bTree, int size) {
  int h = (int)ceil(log2(size+1)); 
  int col = (1 << h) - 1;
  int** M = new int* [h];
  for (int i = 0; i < h; i++) {
      M[i] = new int[col];
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < col; j++) {
      M[i][j] = 0; 
    }
  }
  for (int j = 0; j < col; j++) {
    printf("==");
  }
  printf("\n");
  PrintTree2Matrix(M, bTree, size, 1,  col / 2, 0, h);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < col; j++) { 
      if (M[i][j] == 0)
        printf("  ");
      else
        printf("%2d",M[i][j]);
    }  
    printf("\n");
  }
  for (int j = 0; j < col; j++) {
    printf("=="); 
  }
  printf("\n");
}
 
void PrintAncestor(int* bTree, int size, int idx) {
    printf("%d의 모든 조상 노드: ", bTree[idx]);
    int parent_idx = idx / 2;
    while (parent_idx > 0) {
        printf("%d ", bTree[parent_idx]);
        parent_idx /= 2;
    }
    printf("\n");
}

void PrintLeftDescendant(int* bTree, int size, int idx) {
    printf("%d의 모든 왼쪽 후손 노드: ", bTree[idx]);
    int left_child_idx = idx * 2;
    while (left_child_idx <= size) {
        printf("%d ", bTree[left_child_idx]);
        left_child_idx *= 2;
    }
    printf("\n");
}

void PrintRightDescendant(int* bTree, int size, int idx) {
  if (idx < 1 || idx > size) return; // invalid index
  printf("%d의 모든 오른쪽 후손 노드: ", bTree[idx]);
  while (idx <= size) {
    idx = idx * 2 + 1;
    if (idx <= size) {
      printf("%d ", bTree[idx]);
    }
  }
  printf("\n");
}

int FindNode(int* bTree, int size, int data) {
  for (int i = 1; i <= size; i++) {
    if (bTree[i] == data) {
      return i;
    }
  }
  return -1; 
}


int main(){
  int full_bTree[] = { 0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 55, 35, 65,75,25,91}; 
  int size = sizeof(full_bTree) / sizeof(full_bTree[0]) - 1; 
  TreePrinter(full_bTree, size);
  PrintAncestor(full_bTree, size, 11);
  PrintLeftDescendant(full_bTree, size, 3);
  PrintRightDescendant(full_bTree, size, 7);
  printf("%d 노드의 인덱스는 %d 입니다. \n", 60, FindNode(full_bTree, size, 60)); 
  return 0;
}
