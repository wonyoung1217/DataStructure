#include <iostream>
using namespace std;

#define NO_OF_TERMS 20

struct Term {
  int coef;
  int expon;
};

int Cs;
int Ce;

void insert(Term poly[], int avail, int coef, int expon) {
  poly[avail].coef = coef;
  poly[avail].expon = expon;
}

int compare(int As, int Ae) {
  if(As > Ae)
    return 0;
  else if (As == Ae)
    return 1;
  else if (As < Ae)
    return 2;
}

void Poly_Add(Term poly[], int As, int Ae, int Bs, int Be, int* avail) {
  Cs = *avail;
  while (As <= Ae && Bs <= Be) {
    switch (compare(poly[As].expon, poly[Bs].expon)) {
      case 0: 
        insert(poly, *avail, poly[As].coef, poly[As].expon);
        As++;
        break;
      case 1:{ 
        int sumCoef = poly[As].coef + poly[Bs].coef;
        if (sumCoef)
          insert(poly, *avail, sumCoef, poly[As].expon); 
        else
          (*avail)--;
        As++;
        Bs++;
        break;}
      case 2: 
        insert(poly, *avail, poly[Bs].coef, poly[Bs].expon);
        Bs++;
        break;
    }
    (*avail)++;
  }
  
  for (int i = As; i <= Ae; i++){
    insert(poly, *avail, poly[i].coef, poly[i].expon);
    (*avail)++;
  }
  for (int i = Bs; i <= Be; i++){
    insert(poly, *avail, poly[i].coef, poly[i].expon);
    (*avail)++;
  }
  Ce = (*avail) - 1;
}

void Print_Poly(Term ploy[], int As, int Ae, int Bs, int Be, int avail) {
  for(int i = 0 ; i < avail; i++){
    if(i == As)  
      cout << "Polynomial A: ";
    else if(i == Bs) 
      cout << "Polynomial B: ";
    else if(i == Cs)  
      cout << "Polynomial C: ";

    cout << ploy[i].coef << "*x^" << ploy[i].expon;
    if (i == Ae || i == Be || i == Ce) 
      cout << endl << endl;
    else 
      cout << " + ";
  }
}

int main (void) {
  Term poly[NO_OF_TERMS] = {{3,5},{2,3},{2,0},{4,4},{5,3},{2,1}};
  int As = 0;
  int Ae = 2;
  int Bs = 3;
  int Be = 5;
  int avail = 6;
  Poly_Add(poly, As, Ae, Bs, Be, &avail);
  Print_Poly(poly, As, Ae, Bs, Be, avail);
  return 0;
}
