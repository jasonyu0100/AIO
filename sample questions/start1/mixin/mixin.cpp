#include <iostream>
#include <fstream>
using std::ifstream;
using std::ofstream;
int main() {
	int numerator,denominator,whole,newNumerator;
	ifstream inputFile("mixin.txt");
	ofstream outputFile("mixout.txt");
	inputFile >> numerator >> denominator;
	whole = numerator / denominator;
	newNumerator = numerator - (denominator * whole);
	if (whole > 0) {
		outputFile << whole;
	}
	if (newNumerator > 0 && whole > 0) {
		outputFile << " " << newNumerator << "/" << denominator;
	} else if (newNumerator > 0) {
		outputFile << newNumerator << "/" << denominator;
	}
	outputFile.close();
	inputFile.close();
	return 0;
}