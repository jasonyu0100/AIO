#include <iostream>
#include <fstream>
#include <cmath>
 
using namespace std;

int main() {
	int x1,y1,x2,y2,d1,d2;
	ifstream in("cocoin.txt");
	ofstream out("cocoout.txt");
	in >> x1 >> y1 >> d1 >> x2 >> y2 >> d2;
	double distance = sqrt(pow(x1-x2,2) + pow(y1-y2,2));
	double distanceDif = abs(d1-d2);
	// cout << distance << endl;
	// cout << distanceDif << endl;
	// cout << d1 +d2 << endl;
	if (distance <= (d1 + d2) && distance >= distanceDif){
		out << "yes";
	} else {
		out << "no";
	}
	in.close();
	out.close();
}