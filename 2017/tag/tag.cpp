#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

// int checkMembership(vector <int> team,int value);

int main() {
	int players,numTags,tagger,tagee;
	set <int> redTeam;
	set <int> blueTeam;
	blueTeam.insert(2);
	redTeam.insert(1);
	ifstream in("tagin.txt");
	ofstream out("tagout.txt");
	in >> players >> numTags;
	for (int i=0;i<numTags;i++) {
		in >> tagger >> tagee;
		if (blueTeam.count(tagger) > 0) {
			blueTeam.insert(tagee);
		} else {
			redTeam.insert(tagee);
		}
	}
	out << redTeam.size() << " " << blueTeam.size();
	in.close();
	out.close();
}

// int checkMembership(vector <int> team,int value) {
// 	vector <int>::iterator i = team.begin();
// 	while(i!=team.end()) {
// 		if (value == *i) {
// 			return true;
// 		}
// 		i++;
// 	}
// 	return false;
// }