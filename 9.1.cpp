#include "MyGraphLL.h"

int main() {
  const char* file = "g_file.txt";
  int adj_mat[MAX_VERTICES][MAX_VERTICES] = { 0 };
  int num_of_ver = 7;
  G_Node** List = new G_Node* [num_of_ver]; //인접 리스트 헤더 포인터 배열 생성
  for (int i = 0; i < num_of_ver; i++) List[i] = NULL; //NULL로 초기화

  ADJ_Create(file, adj_mat); //0) 그래프를 인접 행렬로 생성
  ADJ_Print_Array(adj_mat, num_of_ver); //인접 행렬 출력
  ADJ_Degree(adj_mat, num_of_ver);
  ADJ_Mat2List(adj_mat, num_of_ver, List);
  ADJ_Print_List(List, num_of_ver);
  Graph_DFS(List, 1);
  Graph_DFS_Recursive(List, 1);
  
  delete[] List;
  return 0;
}