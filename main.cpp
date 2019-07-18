#include <iostream>

using namespace std;

void printArray(int** A, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << A[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

void setZeros(int** matrix, int n, int m) {
	int size = n;
	 bool* row = new bool[n];
	 bool* column = new bool[m];
	 for (int i = 0; i < size; i++) {
		 for (int j = 0; j < size;j++) {
			 if (matrix[i][j] == 0) {
				 row[i] = true;
				 column[j] = true;
			 }
		 }
	 }

	 for (int i = 0; i < size; i++) {
		 for (int j = 0; j < size; j++) {
			 if (row[i] || column[j]) {
			 	matrix[i][j] = 0;       //set the elements of the matrix to zero
			 }
		 }
	 }
	delete [] row;
	delete [] column;   //deallocate, as they were allocated with "new"
 }

int main(void){
	int** matrix = new int*[3]; //initialize the outer array-"array of arrays"-to form the matrix

	for(int i = 0; i <3; i++){  //||    ||      inner array...
	    matrix[i] = new int[3];     //so we will have a 3x3 matrix
	}
	//populate the matrix
	matrix[0][0] = 0;
	matrix[1][0] = 4;
	matrix[2][0] = 6;
	matrix[0][1] = 7;
	matrix[1][1] = 6;
	matrix[2][1] = 8;
	matrix[0][2] = 0;
	matrix[1][2] = 2;
	matrix[2][2] = 7;

	printArray(matrix, 3, 3);   //print the matrix...

	setZeros(matrix, 3, 3);

	printArray(matrix, 3, 3);

	for(int i = 0; i < 3; i ++){
		delete [] matrix[i];
	}
	delete[] matrix;

	return 0;
}

