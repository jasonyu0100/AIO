#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream input("countin.txt");
	ofstream output("countout.txt");
	int max;
	input >> max;

	for(int i=1;i<=max;i++){
		output << i << endl;
	}

	input.close();
	output.close();
}