#ifndef __MY_MAX_HEAP_TREE_HPP__
#define __MY_MAX_HEAP_TREE_HPP__
#include <cstdlib>
#include <cstdio>
#include <cmath>
//이진트리 출력 함수
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

//최대 힙 트리 삽입/삭제 함수
void Max_Heap_Insert(int* heap, int* h_size, int key) {
    (*h_size)++; // 힙 크기 증가
    int index = (*h_size); // 삽입할 위치
    while ((index != 1) && (key > heap[index/2])) { // 조상 노드와 비교
        heap[index] = heap[index/2]; // 조상 노드 값을 아래로 내림
        index /= 2; // 조상 노드로 이동
    }
    heap[index] = key; // 삽입할 위치에 key 삽입
}

int Max_Heap_Remove(int* heap, int* h_size) {
  int deleted_key = heap[1];
  int tmp = heap[*h_size];
  (*h_size)--;
  int parent = 1;
  int index = 2;
  while (index <= (*h_size)) {
    if ((index < (*h_size)) && (heap[index+1] > heap[index])) {
      index++;
    }
    if (tmp >= heap[index]) {
      break;
    }
    heap[parent] = heap[index];
    parent = index;
    index *= 2;
  }
  heap[parent] = tmp;
  return deleted_key;
}

#endif