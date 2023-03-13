#include <iostream>
using namespace std;

#define MAT_SIZE 5

void Print_MAT(int arr[][MAT_SIZE]){
  for (int i=0; i<MAT_SIZE; i++){
    for (int j=0; j<MAT_SIZE; j++){
      cout << arr[i][j];
    }
    cout << endl;
  }
}

void Transpose_MAT(int A[][MAT_SIZE], int B[][MAT_SIZE]){
  for (int i=0; i<MAT_SIZE; i++){
    for (int j=0; j<MAT_SIZE; j++){
      B[j][i] = A[i][j];
    }
  }
}

int main(){
  int arr1[5][5] = {{2,3,0,6,8},
  {8,9,1,5,3},
  {7,0,1,9,6},
  {1,4,2,1,8},
  {2,9,5,0,3}
  };
  int arr2[5][5] = {0};
  Transpose_MAT(arr1, arr2);
  Print_MAT(arr1);
  cout << endl;
  Print_MAT(arr2);

  return 0;
}