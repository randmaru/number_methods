#include "v11-lib.cpp"
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <functional>

using namespace std;

#define N 2
#define N1 N+1

double first[N][N1] {
    {2, 1, 30},
    {1, 3, 40}
    };

int main() {
 	double** matrix = generate(N, [first](int i, int j) { return first[i][j]; });
 	showMatrix(matrix, N, N1);
 	cout << endl;
	double* x = gaus(matrix, N);
	showMatrix(x, N);
 	cout << endl;
 	cout << endl;

	return 0;
}
