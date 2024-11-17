

#include<bits/stdc++.h>
using namespace std;
int** initialize(int n) {
int **mat = new int*[n];
for (int i = 0; i < n; i++) {
mat[i] = new int[n];
}
return mat;
}
int** add(int** m1, int** m2, int n) {
int **res = initialize(n);
for (int i = 0; i < n; i++)
for (int j = 0; j < n; j++)
res[i][j] = m1[i][j] + m2[i][j];
return res;
}
int** sub(int** m1, int** m2, int n) {
int **res = initialize(n);
for (int i = 0; i < n; i++)
for (int j = 0; j < n; j++)
res[i][j] = m1[i][j] - m2[i][j];
return res;
}
int** strassen(int** a, int** b, int n) {
if (n == 1) {
int **c = initialize(1);
c[0][0] = a[0][0] * b[0][0];
return c;
}
int k = n / 2;
int **a11 = initialize(k), **a12 = initialize(k), **a21 = initialize(k), **a22 = initialize(k);
int **b11 = initialize(k), **b12 = initialize(k), **b21 = initialize(k), **b22 = initialize(k);
for (int i = 0; i < k; i++) {
for (int j = 0; j < k; j++) {
a11[i][j] = a[i][j];
a12[i][j] = a[i][j + k];
a21[i][j] = a[i + k][j];
a22[i][j] = a[i + k][j + k];
b11[i][j] = b[i][j];
b12[i][j] = b[i][j + k];
b21[i][j] = b[i + k][j];
b22[i][j] = b[i + k][j + k];
}
}
int **p1 = strassen(a11, sub(b12, b22, k), k);
int **p2 = strassen(add(a11, a12, k), b22, k);
int **p3 = strassen(add(a21, a22, k), b11, k);
int **p4 = strassen(a22, sub(b21, b11, k), k);
int **p5 = strassen(add(a11, a22, k), add(b11, b22, k), k);
int **p6 = strassen(sub(a12, a22, k), add(b21, b22, k), k);
int **p7= strassen(sub(a11,a21,k),add(b11,b12,k),k);
int **c11 = add(sub(add(p5, p4, k), p2, k), p6, k);
int **c12 = add(p1, p2, k);
int **c21 = add(p3, p4, k);
int **c22 = sub(sub(add(p1, p5, k), p3, k), p7, k);
int **c = initialize(n);
for (int i = 0; i < k; i++)
    { for (int j = 0; j < k; j++)
    { c[i][j] = c11[i][j];
      c[i][j + k] = c12[i][j];
      c[i + k][j] = c21[i][j];
      c[i + k][j + k] = c22[i][j];
      }
      }return c;
      }
int main()
{ int n;

cout << "Enter the size of the matrices (n x n): ";
cin >> n;
int **A = initialize(n);
int **B = initialize(n);
cout << "Enter elements of matrix A:\n";
for (int i = 0; i < n; i++)
    { for (int j = 0; j < n; j++)
    { cin >> A[i][j];
} }
cout << "Enter elements of matrix B:\n";
for (int i = 0; i < n; i++)
    { for (int j = 0; j < n; j++)
     { cin >> B[i][j]; } }
int **C = strassen(A, B, n);
cout << "Resultant matrix C:\n";
for (int i = 0; i < n; i++)
    { for (int j = 0; j < n; j++)
    { cout << C[i][j] << " ";
    }
cout << endl;
}
return 0;
}
