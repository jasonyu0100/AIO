#include <iostream>
#include <fstream>
 
using namespace std;

int main() {
	int size;

	ifstream in("chimin.txt");
	ofstream out("chimout.txt");

	in >> size;
	char wordOne[size];
	char wordTwo[size];
	char wordGoal[size];
	
	in >> wordOne >> wordTwo >> wordGoal;
	int flag = 0;
	char gchar,onechar,twochar;
	int count = 0;
	int currentWord = -1;
	for(int i=0;i<size;i++) {
		gchar = wordGoal[i];
		onechar = wordOne[i];
		twochar = wordTwo[i];
		if (onechar != gchar && twochar != gchar) {
			flag = 1;
			break;
		} else if (onechar == gchar && twochar == gchar) {

		} else if (onechar == gchar) {
			if (currentWord == 1) {
				count += 1;
			}
			currentWord = 0;
		} else if (twochar == gchar) {
			if (currentWord == 0) {
				count += 1;
			}
			currentWord = 1;
		}
		cout << count << endl;
	}
	if (flag == 1) {
		out << "PLAN FOILED";
	} else {
		out << "SUCCESS" << endl;
		out << count;
	}
	// cout << wordOne << wordTwo << wordGoal;
	in.close();
	out.close();
}