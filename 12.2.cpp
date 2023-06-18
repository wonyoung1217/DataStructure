#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#define MAX_STD 20

struct Student { // 학생 정보
  int no;        // 학번
  char name[50]; // 이름
  char tel[50];  // 전화번호
};

int Hash_Function(int key, int Hash_Size) {
  // 해시 함수 구현
  std::string str_key = std::to_string(key);
  int len = str_key.length();
  int sum = 0;

  for (int i = 0; i < len; i++) {
    sum += str_key[i];
  }

  int hash_addr = sum % Hash_Size;
  return hash_addr;
}

void SInfo_Create(Student *students, const char *file_name, int Hash_Size) {
  std::ifstream file(file_name);
  if (file.is_open()) {
    std::string line;
    while (std::getline(file, line)) {
      int no;
      char name[50];
      char tel[50];

      sscanf(line.c_str(), "%d %s %s", &no, name, tel);

      int hash_addr = Hash_Function(no, Hash_Size);
      int index = hash_addr;

      while (students[index].no != -1) {
        if (students[index].no == no) {
          std::cout << "Error: 중복된 키입니다." << std::endl;
          return;
        }

        index = (index + 1) % Hash_Size; // 선형 탐사법
        if (index == hash_addr) {
          std::cout << "Error: 해시 테이블이 가득 찼습니다." << std::endl;
          return;
        }
      }

      students[index].no = no;
      strcpy(students[index].name, name);
      strcpy(students[index].tel, tel);
    }

    file.close();
  }
}

int Hash_Search(Student *students, int key, int Hash_Size) {
  int hash_addr = Hash_Function(key, Hash_Size);
  int index = hash_addr;

  while (true) {
    if (students[index].no == key) {
      return index;
    }

    if (students[index].no == -1) {
      break;
    }

    index = (index + 1) % Hash_Size; // 선형 탐사법

    if (index == hash_addr) {
      break;
    }
  }

  return -1;
}
int main() {
  Student students[MAX_STD];
  const char *fName = "student_info.txt";

  for (int i = 0; i < MAX_STD; i++) { // students 해시 테이블 초기화
    students[i].no = -1;
    memset(students[i].name, 0, sizeof(students[i].name));
    memset(students[i].tel, 0, sizeof(students[i].tel));
  }

  SInfo_Create(students, fName, MAX_STD);

  std::cout << "218 위치는 해시 테이블 " << Hash_Search(students, 218, MAX_STD)
            << "에 존재합니다." << std::endl
            << std::endl;
  std::cout << "##해시 테이블##" << std::endl;
  for (int i = 0; i < MAX_STD; i++) { // students 해시 테이블 출력
    std::cout << "[" << i << "]: " << students[i].no << " " << students[i].name
              << " " << students[i].tel << std::endl;
  }

  return 0;
}