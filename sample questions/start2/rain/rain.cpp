#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream in("rainin.txt");
	ofstream out("rainout.txt");

	int count,max,curr,currTotal,days;
	currTotal = 0;
	in >> count >> max;
	for(days=1;days<count;days++) {
		in >> curr;
		currTotal += curr;
		if (currTotal >= max) {
			break;
		}
	}

	out << days;

	in.close();
	out.close();
}