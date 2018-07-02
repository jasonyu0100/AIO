#include <iostream>
#include <fstream>

using namespace std;

int main() {
	int fruits;
	int cycles = 0;
	ifstream inputFile("taktakin.txt");
	ofstream outputFile("taktakout.txt");
	inputFile >> fruits;
	while ((fruits - 1) % 11 != 0) {
		fruits *= 2;
		cycles += 1;
	}
	outputFile << cycles << " " << fruits;
	inputFile.close();
	outputFile.close();
}