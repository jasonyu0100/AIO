#include <iostream>
#include <fstream>
// #include <list>
#include <vector>
#include <iterator>

using namespace std;

int main() {
	vector<int> lineList;
	int lines,value;
	ifstream in("tripin.txt");
	ofstream out("tripout.txt");
	in >> lines;
	for(int lineNumber=1;lineNumber<lines+1;lineNumber++) {
		in >> value;
		if (value % 3 == 0) {
			lineList.push_back(lineNumber);
		}
	}
	if (lineList.size() == 0) {
		out << "Nothing here!";
	} else {
		out << lineList.size() << endl;
		vector<int>::iterator thing;
		for(thing=lineList.begin();thing<lineList.end();thing++) {
			out << *thing << " ";
		}
	}

	in.close();
	out.close();
}