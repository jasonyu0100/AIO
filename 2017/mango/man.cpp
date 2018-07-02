#include <iostream>
#include <fstream>

using namespace std;

int main() {
	int a,b,am,bm;
	ifstream in("manin.txt");
	ofstream out("manout.txt");
	in >> a >> b >> am >> bm;
	if (a+am == b+bm) {
		out << a+am;
	} else if (a-am == b+bm) {
		out << a-am;
	} else if (a+am==b-bm) {
		out << a+am;
	} else if (a-am==b-bm) {
		out << a-am;
	}

	in.close();
	out.close();
}