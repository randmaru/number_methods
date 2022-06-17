#pragma once
#include <iostream> 
#include <stdio.h> 
#include <math.h> 
#include <stdlib.h> 
#include <functional>

void showMatrix(double** matrix, int n, int n1, std::function<void(int, int, double)> func = [](int i, int j, double e) { std::cout << "|" << e; }) {
	for (int i=0 ;i<n; i++) { 
		for (int j=0; j<n1; j++) func(i, j, matrix[i][j]);
		std::cout << std::endl;
	} 
}

void showMatrix(double* matrix, int n, std::function<void(int, double)> func = [](int i, double e) { std::cout << e << std::endl; }) {
	for (int i=0 ;i<n; i++) { 
		func(i, matrix[i]);
	} 
}

double* gaus(double** matrix, int n) {
	int n1 = n + 1;
	double tmp; 
	double* xx = new double[n]; 
	int i, j, k;
	for (i=0; i<n; i++) { 
		tmp=matrix[i][i]; 
		for (j = n; j>=i; j-- ) matrix[i][j] /= tmp; 
		for (j = i+1; j<n; j++) { 
			tmp = matrix[j][i]; 
			for (k = n; k >= i; k--) matrix[j][k] -= tmp * matrix[i][k]; 
		} 
	}
	xx[n-1] = matrix[n-1][n]; 
	for (i=n-2; i>=0; i--) { 
		xx[i] = matrix[i][n]; 
		for (j = i+1; j < n; j++) xx[i] -= matrix[i][j] * xx[j]; 
	}
	return xx;
}

double** generate(int n, std::function<double(int, int)> func) {
	double** matrix = new double*[n];
	int n1 = n + 1;
 	for (int i = 0; i < n; i++) {
 		matrix[i] = new double[n1];
 		for (int j = 0; j < n1; j++) {
 			matrix[i][j] = func(i, j);
 		}
 	}
 	return matrix;
}

double** strangeGenerate(double h, int n) {
	double qh = h * h;
	double** matrix = new double*[n];
	for (int i = 0; i < n; ++i) {
		matrix[i] = new double[n + 1];
		for (int j = 0; j <= n; ++j) {
			matrix[i][j] = 0;
		}
	}
	matrix[0][0] = 1;
	for (int i = 1; i < (n - 1); ++i) {
		matrix[i][i] = -2 / qh;
		matrix[i][i - 1] = 1 / qh;
		matrix[i][i + 1] = 1 / qh;
	} 
	matrix[n - 1][n - 1] = 1;
	for (int i = 1; i < (n - 1); ++i) {
		matrix[i][n] = 1; 
	}
	matrix[n - 1][n] = 3.0 / 2;
	return matrix;
}

double** strangeGenerate2(double h, int n) {
	double qh = h * h;
	double** matrix = new double*[n];
	for (int i = 0; i < n; ++i) {
		matrix[i] = new double[n + 1];
		for (int j = 0; j <= n; ++j) {
			matrix[i][j] = 0;
		}
	}
	matrix[0][0] = 1;
	for (int i = 1; i < (n - 1); ++i) {
		matrix[i][i] = 1 - (2 / qh);
		matrix[i][i - 1] = 1 / qh;
		matrix[i][i + 1] = 1 / qh;
	} 
	matrix[n - 1][n - 1] = 1;
	for (int i = 1; i < (n - 1); ++i) {
		matrix[i][n] = 1; 
	}
	return matrix;
}

double** strangeGenerate3(double h, int n) {
	double qh = h * h;
	double** matrix = new double*[n];
	for (int i = 0; i < n; ++i) {
		matrix[i] = new double[n + 1];
		for (int j = 0; j <= n; ++j) {
			matrix[i][j] = 0;
		}
	}
	matrix[0][0] = 1;
	for (int i = 1; i < (n - 1); ++i) {
		matrix[i][i] = -1 - (2 / qh);
		matrix[i][i - 1] = 1 / qh;
		matrix[i][i + 1] = 1 / qh;
	} 
	matrix[n - 1][n - 1] = 1;
	for (int i = 1; i < (n - 1); ++i) {
		matrix[i][n] = 2 * i * h; 
	}
	matrix[n - 1][n] = -1;
	return matrix;
}

double** strangeGenerate4(double h, int n) {
	double qh = h * h;
	double** matrix = new double*[n];
	for (int i = 0; i < n; ++i) {
		matrix[i] = new double[n + 1];
		for (int j = 0; j <= n; ++j) {
			matrix[i][j] = 0;
		}
	}
	matrix[0][0] = -1;
	matrix[0][1] = 1;
	for (int i = 1; i < (n - 1); ++i) {
		matrix[i][i] = -2 / qh;
		matrix[i][i - 1] = (1 / qh) - (1 / (2 * h));
		matrix[i][i + 1] = (1 / qh) + (1 / (2 * h));
	} 
	matrix[n - 1][n - 1] = 1;
	for (int i = 1; i < (n - 1); ++i) {
		matrix[i][n] = 1; 
	}
	return matrix;
}

double** strangeGenerate5(double h, int n) {
	double qh = h * h;
	double** matrix = new double*[n];
	for (int i = 0; i < n; ++i) {
		matrix[i] = new double[n + 1];
		for (int j = 0; j <= n; ++j) {
			matrix[i][j] = 0;
		}
	}
	matrix[0][0] = 1;
	for (int i = 1; i < (n - 1); ++i) {
		matrix[i][i] = -2 / qh;
		matrix[i][i - 1] = (1 / qh) + (1 / (2 * h));
		matrix[i][i + 1] = (1 / qh) - (1 / (2 * h));
	} 
	matrix[n - 1][n - 2] = (-1 / h);
	matrix[n - 1][n - 1] = (1 / h) - 1;
	
	matrix[0][n] = -1;
	matrix[n - 1][n] = 2;
	return matrix;
}

double** generateWithX(int n, std::function<double(int, int)> func, std::function<double(int)> funcX) {
	double** matrix = new double*[n];
	int n1 = n + 1;
 	for (int i = 0; i < n; i++) {
 		matrix[i] = new double[n1];
 		for (int j = 0; j < n; j++) {
 			matrix[i][j] = func(i, j);
 		}
 		matrix[i][n] = funcX(i);
 	}
 	return matrix;
}
