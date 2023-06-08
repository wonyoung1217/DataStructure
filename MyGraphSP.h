#ifndef __MY_GRAPH_SP_H__
#define __MY_GRAPH_SP_H__
#include <iostream>
#include <limits>
#include <stdio.h>
#define MAX_VERTICES 100
#include <fstream>
using namespace std;
#define INF std::numeric_limits<int>::max()

void ADJ_Create(const char *g_file, int adj_mat[][MAX_VERTICES]) {
  ifstream file(g_file);

  if (!file.is_open()) {
    cout << "파일이 없습니다. 프로그램을 종료합니다." << std::endl;
    return;
  }

  while (true) {
    int i, j, w;
    char comma;
    if (!(file >> i >> comma >> j >> comma >> w))
      break;
    adj_mat[i][j] = w;
    adj_mat[j][i] = w;
  }

  file.close();
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
                    if (adj_mat[i][j] == INF)
                        printf("INF ");
                    else
                        printf("%3d ", adj_mat[i][j]);
                }
            }
        }
        printf("\n");
    }
}
void Shortest_Path(int weight_mat[][MAX_VERTICES], int n, int v, int *path) {
  int distance[MAX_VERTICES];
  int visited[MAX_VERTICES];

  for (int i = 0; i < n; i++) {
    distance[i] = INF;
    path[i] = -1;
    visited[i] = 0;
  }

  distance[v] = 0;
  int step = 1;

  while (step <= n) {
    int min = INF;
    int k = -1;

    for (int i = 0; i < n; i++) {
      if (visited[i] == 0 && distance[i] < min) {
        min = distance[i];
        k = i;
      }
    }

    if (k == -1) {
      break;
    }

    visited[k] = 1;

    for (int u = 0; u < n; u++) {
      if (visited[u] == 0 && weight_mat[k][u] != INF &&
          distance[k] + weight_mat[k][u] < distance[u]) {
        distance[u] = distance[k] + weight_mat[k][u];
        path[u] = k;
      }
    }

    step++;
  }

  for (int i = 0; i < n; i++) {
    cout << "정점 " << v << " ->   정점" << i << " : " << distance[i] << endl;
  }
  cout << endl;
}
void PrintPath(int *path, int v, int u) {
  if (u == v) {
    printf("%d ", u);
    return;
  }
  PrintPath(path, v, path[u]);
  printf("-> %d ", u);
}
#endif