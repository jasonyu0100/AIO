#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <iterator>

using namespace std;

int main() {
	int lines,a,b;
	ifstream in("listin.txt");
	ofstream out("listout.txt");
	map<int, vector<int> > l;
	in >> lines;
	for(int i=0;i<lines;i++) {
		in >> a >> b;
		if (l.count(a) == 0) {
			vector<int> friends;
			l.insert(pair <int,vector<int> > (a,friends));
		} else {
			l[a].push_back(b);
		}

		if (l.count(b) == 0) {
			vector<int> friends;
			l.insert(pair <int,vector<int> > (b,friends));
		} else {
			l[b].push_back(a);
		}
	}
	vector<int> ids;
	int max = 0;
	int friendCount;
	map<int, vector<int> >::iterator i;
	for (i=l.begin();i != l.end();i++) {
		friendCount = i->second.size();
		if (friendCount == max) {
			ids.push_back(i->first);
		} else if (friendCount > max) {
			ids.clear();
			ids.push_back(i->first);
			max = friendCount;
		}
	}

	vector<int>::iterator j;
	for(j=ids.begin();j<ids.end();j++) {
		out << (*j) << endl;
	}
	in.close();
	out.close();
}