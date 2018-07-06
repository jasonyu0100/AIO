#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Structure {
	public:


};

int main() {
	int blocks,periods,width,height;
	ifstream in("artin.txt");
	ofstream out("artout.txt");
	in >> blocks;
	Structure structure;
	for(int i=0;i<blocks;i++){
		in >> periods >> width >> height;
		printf("periods:%d width:%d height%d\n",periods,width,height);
	}
	in.close();
	out.close();
}

