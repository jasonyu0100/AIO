#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main() {
	map <int,int> dictionary;
	int keyPairs,translations;
	int key,value;
	ifstream in("dictin.txt");
	ofstream out("dictout.txt");
	in >> keyPairs >> translations;
	for (int i=0;i<keyPairs;i++){
		in >> key >> value;
		dictionary.insert(pair <int,int> (key,value));
	}

	for(int i=0;i<translations;i++) {
		in >> key;
		if(dictionary.count(key)) {
			out << dictionary[key] << endl;
		} else {
			out << "C?" << endl;
		}
	}

	in.close();
	out.close();
}