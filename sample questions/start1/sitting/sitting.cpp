#include <iostream>
#include <fstream>

using namespace std;

int main() {
	int rows,cols,total,sitting,standing;
	ifstream inputFile("sitin.txt");
	ofstream outputFile("sitout.txt");
	inputFile >> rows >> cols >> total;
	if (rows*cols < total) {
		sitting = rows * cols;
		standing = total - sitting;
	} else {
		sitting = total;
		standing = 0;
	}	
	outputFile << sitting << ' ' << standing;
	inputFile.close();
	outputFile.close();
}