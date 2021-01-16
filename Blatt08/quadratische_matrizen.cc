#include "fcpp.hh"
#include <string>

// Fixe Größe der Matrizen
const short SIZE = 3;

// Datentyp für Matrizen dieser Größe
struct matrix {
  int vals[SIZE][SIZE];
};

// a)
matrix matrix_zero() {
  matrix zeromatrix;
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      zeromatrix.vals[i][j] = 0;
    }
  }
  return zeromatrix;
}

matrix matrix_id() {
  matrix idmatrix;
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      if (i==j)
      {
        idmatrix.vals[i][j]=1;
      }
      else
      {
        idmatrix.vals[i][j]=0;
      }     
    }
  }
  return idmatrix;
}

// b)
matrix matrix_add(matrix left, matrix right) {
  matrix sum;
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      sum.vals[i][j]=left.vals[i][j]+right.vals[i][j];
    }
  }
  return sum;
}

// c)
matrix matrix_mult(matrix left, matrix right) {
  matrix mult;
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      int s = 0;
      for (int k = 0; k < SIZE; k++)
      {
        s += left.vals[i][k] * right.vals[k][j];
      }
      mult.vals[i][j] = s;
    } 
  }
  return mult;
}

// Konstruktion eines mehrzeiligen Strings, der die Einträge einer Matrix darstellt
std::string to_string(matrix m) {
  std::string str = "";
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      str += std::to_string(m.vals[i][j]) + "  ";
    }
    str += "\n";
  }
  return str;
}

// d)
int main(int argc, char *argv[]) {
  // Initialisiere Matrizen
  matrix A = {
    {
      {2, 5, 4},
      {3, 2, 4},
      {1, 1, 9}
    }
  };
  matrix B = {
    {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9}
    }
  };
  // print(to_string(matrix_zero()));
  // print(to_string(matrix_id()));
  // print(to_string(matrix_add(A,B)));
  print(to_string(matrix_mult(A,B)));
  return 1;
}
