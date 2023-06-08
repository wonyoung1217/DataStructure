#include <iostream>
#include "MyGraphLL.h"

void ADJ_Degree(int adj_mat[][MAX_VERTICES], int n) {
    for (int i = 0; i < n; i++) {
        int degree = 0;
        for (int j = 0; j < n; j++) {
            degree += adj_mat[i][j];
        }
        printf("정점 %d의 차수: %d\n", i, degree);
    }
}

void ADJ_Insert(G_Node** List, int i, int j) {
    G_Node* newNode = new G_Node;
    newNode->vertex = j;
    newNode->link = List[i];
    List[i] = newNode;
}

void ADJ_Mat2List(int adj_mat[][MAX_VERTICES], int n, G_Node** List) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj_mat[i][j] == 1) {
                ADJ_Insert(List, i, j);
            }
        }
    }
}
 
void Graph_DFS(G_Node** List, int v) {
    int n = MAX_VERTICES;
    int visited[MAX_VERTICES] = {0}; // Initialize visited array
    ArrStack<int> stack(n); // Create an instance of Array Stack
    int current = v;
    int vFlag;

    visited[current] = 1;
    printf("%d ", current);

    do {
        vFlag = false;

        if (visited[current] == 0) {
            printf("%d ", current);
            visited[current] = 1;
            vFlag = true;
        } else {
            G_Node* iter = List[current];
            while (iter != NULL) {
                if (visited[iter->vertex] == 0) {
                    stack.Stack_Push(current);
                    current = iter->vertex;
                    vFlag = true;
                    break;
                }
                iter = iter->link;
            }
        }

        if (!vFlag) {
            if (stack.Stack_IsEmpty())
                break;
            else
                current = stack.Stack_Pop();
        }
    } while (!stack.Stack_IsEmpty());
}

void Graph_DFS_Recursive(G_Node** List, int v) {
    static int visited[MAX_VERTICES] = {0}; 
    visited[v] = 1;
    printf("%d ", v);

    G_Node* iter = List[v];
    while (iter != NULL) {
        int temp = iter->vertex;
        if (visited[temp] == 0) {
            Graph_DFS_Recursive(List, temp);
        }
        iter = iter->link;
    }
}

void ADJ_Create(const char* g_file, int adj_mat[][MAX_VERTICES]) {
  FILE* file = fopen(g_file, "r"); // read mode
  if (file == NULL) {
    printf("파일이 없습니다. 프로그램을 종료합니다.");
    return;
  }
  while (1) {
    int i, j;
    int result = fscanf(file, "%d, %d", &i, &j);
    if (result == EOF) break;
    adj_mat[i][j] = 1;
    adj_mat[j][i] = 1;
  }
  fclose(file);
}


void ADJ_Print_Array(int adj_mat[][MAX_VERTICES], int n) {
    for (int i = -1; i < n; i++) {
        for (int j = -1; j < n; j++) {
          if (i == -1) { 
            if (j != -1)    printf("%2d ", j);
            else    printf("   ");
          }
          else {
            if (j == -1)    printf("%2d ", i);
            else    printf("%2d ", adj_mat[i][j]);
          }
        }
        printf("\n");
    }
}

void ADJ_Print_List(G_Node** List, int n) {
    for (int i = 0; i < n; i++) { 
      G_Node* iter = List[i]; 
      printf("Vertex %2d: ", i); 
      while(iter != NULL){
          printf("%2d ", iter->vertex);
          iter = iter->link;
      }
      printf("\n"); 
    }
}