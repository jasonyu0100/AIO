#include <iostream>
#include <fstream>

using namespace std;

int main() {
	int pages,questions,currWordCount,currPage;
	ifstream in("encyin.txt");
	ofstream out("encyout.txt");
	in >> pages >> questions;
	int wordCounts[pages];
	for(int i=0;i<pages;i++) {
		in >> currWordCount;
		wordCounts[i] = currWordCount;
	}
	for(int i=0;i<questions;i++) {
		in >> currPage;
		out << wordCounts[currPage-1] << endl;
	}
	in.close();
	out.close();
}