# DataStructure

1. 실습과제 1.1
- nXn 행렬인 A행렬이 주어졌을 때 A행렬의 전치행렬 B을 구하는 알고리즘을 의사코드로 구현하기.
Algorithm Transpose_MAT(A, n)
Input  : nXn 크기를 갖는 2차원 행렬 A
Output : 행렬 A의 전치행렬 B
for i <- 0 to n-1 do
  for j <- 0 to n-1 do
    B[j,i] <- A[i,j]
return B

- 위 알고리즘의 시간 복잡도를 계산하여 빅오 표기법으로 표현
중첩 for문이 나오므로 : O(n^2)

2. 실습과제 1.2
Transpose.cpp
