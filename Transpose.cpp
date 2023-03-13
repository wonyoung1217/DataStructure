#include <iostream>
using namespace std;

// 행렬의 가로크기 설정
#define MAT_SIZE 5

// 행렬 출력
void Print_MAT(int arr[][MAT_SIZE]){
  for (int i=0; i<MAT_SIZE; i++){
    for (int j=0; j<MAT_SIZE; j++){
      cout << arr[i][j];
    }
    cout << endl;
  }
}

// A행렬 전치시켜서 B행렬에 대입
void Transpose_MAT(int A[][MAT_SIZE], int B[][MAT_SIZE]){
  for (int i=0; i<MAT_SIZE; i++){
    for (int j=0; j<MAT_SIZE; j++){
      B[j][i] = A[i][j];
    }
  }
}

int main(){
  // A행렬 선언
  int arr1[5][5] = {{2,3,0,6,8},
  {8,9,1,5,3},
  {7,0,1,9,6},
  {1,4,2,1,8},
  {2,9,5,0,3}
  };
  // B행렬 선언
  int arr2[5][5] = {0};
  // 전치 
  Transpose_MAT(arr1, arr2);
  // A행렬 출력
  Print_MAT(arr1);
  cout << endl;
  // B행렬 출력
  Print_MAT(arr2);

  return 0;
}