#include <iostream>
using namespace std;

#define MAX_ELEMENTS 8

struct Element {
    int row;
    int col;
    int value;
};

// 구조체 S_A 생성
struct Element S_A[MAX_ELEMENTS] = {{6,6,7},{0,2,6},{1,0,5},{1,4,7},{2,3,3},{4,0,8},{4,1,9},{5,3,2}};

// 희소행렬의 전치행렬을 생성하는 함수
Element* Transpose_Triple1(Element S_a[]) {
    int row = S_a[0].row;
    int col = S_a[0].col;
    int no = S_a[0].value;

    // S_b 생성
    Element* S_b = new Element[MAX_ELEMENTS];
    S_b[0].row = col;
    S_b[0].col = row;
    S_b[0].value = no;

    if (no > 0) {     
        int current = 1;  
        for (int i = 0; i < S_a[0].col; i++) {
            for (int j = 1; j < no; j++) {
                if (S_a[j].col == i) {
                    S_b[current].row = S_a[j].col;
                    S_b[current].col = S_a[j].row;
                    S_b[current].value = S_a[j].value;
                    current++;
                }
            }
        }
    }
    return S_b; 
}

// 배열 출력 함수
void Print_Sparse_Mat(Element arr[]) {
    int row = arr[0].row;
    int col = arr[0].col;
    int no = arr[0].value;
    int current = 1; 
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if ((arr[current].row == i) && (arr[current].col == j)) {
                cout << arr[current].value << " ";
                current++;
            }
            else {
                cout << 0 << " "; 
            }
        }
        cout << endl;
    }
    cout << endl;
}


int main() {
    cout<<"희소 행렬 : "<< endl;
    Print_Sparse_Mat(S_A);
    Element* S_B = Transpose_Triple1(S_A);
    cout<<"전치 행렬 : "<< endl;
    Print_Sparse_Mat(S_B);

    return 0;
}