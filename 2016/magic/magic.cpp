#include <iostream>
#include <fstream>
#include <set>

using namespace std;

#define MAX 20
#define SIZE 3

int colSum(int grid[SIZE][SIZE],int col);
int rowSum(int grid[SIZE][SIZE],int row);
int solve(int grid[SIZE][SIZE],int sum);
int solved(int grid[SIZE][SIZE],int size);
void displayGrid(int grid[SIZE][SIZE]);
int min(int a,int b);

int main() {
	int A,B,C;
	int grid[SIZE][SIZE] = {0};
	ifstream in("magicin.txt");
	ofstream out("magicout.txt");
	in >> A >> B >> C;
	grid[0][0] = A;
	grid[0][1] = B;
	grid[1][0] = C;
	int minSum = min(A+B,A+C);
	int solved = 0;
	for (int sum=minSum+1;sum<=MAX;sum++) {
		// cout << sum << endl;
		if (solve(grid,sum) == 1) {
			solved = 1;
			break;
		}
	}
	if (solved == 1) {
		displayGrid(grid);
		for (int r=0;r<SIZE;r++) {
			for(int c=0;c<SIZE;c++){
				out << grid[r][c] << " ";
			}
			out << endl;
		}
	}
	in.close();
	out.close();
}

int solve(int grid[SIZE][SIZE],int sum) {
	int solvable;
	for(int r=0;r<SIZE;r++){
		for(int c=0;c<SIZE;c++){
			if (grid[r][c] == 0) {
				solvable = 0;
				for(int value=1;value<MAX;value++) { // Current value range
					if (colSum(grid,c) <= sum && rowSum(grid,r) <= sum) { // if both sums are less than or equal to
						grid[r][c] = value; //temp value
						if (solve(grid,sum) == 1) { // If current path is solvable
							solvable = 1;
							break;
						} else {
							grid[r][c] = 0; // Resets value
						}
					}
				}
				if (solvable == 0) { // Current state cannot be solved
					return 0;
				}
			}
		}
	}
	if (solved(grid,sum) == 1) {
		return 1;
	} else {
		return 0;
	} // Completed
}

int colSum(int grid[SIZE][SIZE],int col) {
	int total = 0;
	for (int r=0;r<SIZE;r++){
		total += grid[r][col];
	}
	return total;
}

int rowSum(int grid[SIZE][SIZE],int row) {
	int total = 0;
	for (int c=0;c<SIZE;c++){
		total += grid[row][c];
	}
	return total;
}

int solved(int grid[SIZE][SIZE],int size) {
	for(int r=0;r<SIZE;r++) {
		if (rowSum(grid,r) != size) {
			return 0;
		}
	}
	for(int c=0;c<SIZE;c++) {
		if (colSum(grid,c) != size) {
			return 0;
		}
	}
	return 1;
}

void displayGrid(int grid[SIZE][SIZE]) {
	for(int r=0;r<SIZE;r++) {
		for (int c=0;c<SIZE;c++) {
			cout << grid[r][c];
		}
		cout << endl;
	}
}

int min(int a,int b){ 
	if (a > b) {
		return b;
	} else {
		return a;
	}
}