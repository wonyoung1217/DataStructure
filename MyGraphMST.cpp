#include <iostream>
#include <limits.h>
#include "MyGraphMST.h"

void ADJ_Create(const char* g_file, int adj_mat[][MAX_VERTICES]) {
  FILE* file = fopen(g_file, "r"); // read mode
  if (file == NULL) {
    printf("파일이 없습니다. 프로그램을 종료합니다.");
    return;
  }
  while (1) {
    int i, j, w;
    int result = fscanf(file, "%d, %d, %d", &i, &j, &w);
    if (result == EOF) break;
    adj_mat[i][j] = w;
    adj_mat[j][i] = w;
  }
  fclose(file);
}

void ADJ_Print_Array(int adj_mat[][MAX_VERTICES], int n) {
    for (int i = -1; i < n; i++) {
        for (int j = -1; j < n; j++) {
            if (i == -1) {
                if (j != -1)
                    printf("%2d  ", j);
                else
                    printf("   ");
            } else {
                if (j == -1)
                    printf("%2d ", i);
                else {
                    if (adj_mat[i][j] == INT_MAX)
                        printf("INF ");
                    else
                        printf("%3d ", adj_mat[i][j]);
                }
            }
        }
        printf("\n");
    }
}


void MST_Prim(int weight_mat[][MAX_VERTICES], int MST[][MAX_VERTICES], int n) {
  const int INF = INT_MAX; // 초기화를 위한 최대 값

  int selected[MAX_VERTICES] = {0}; // MST에 선택된 정점 표시 (0으로 초기화)
  selected[0] = 1; // 시작 정점은 정점 0으로 설정

  int edge_count = 0;
  while (edge_count < n - 1) {
    int min = INF;
    int u = 0;
    int v = 0;

    for (int i = 0; i < n; i++) {
      if (selected[i] == 1) { // 이미 MST에 포함된 정점
        for (int j = 0; j < n; j++) {
          if (selected[j] == 0 && min > weight_mat[i][j]) {
            min = weight_mat[i][j];
            u = i;
            v = j;
          }
        }
      }
    }

    selected[v] = 1;
    MST[u][v] = weight_mat[u][v];
    MST[v][u] = weight_mat[u][v];
    edge_count++;
  }
}


