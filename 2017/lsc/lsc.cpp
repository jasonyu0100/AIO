#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int checkOrder(int sortedStores[],int storeCount);
// void getRanges(int first,int second,int array[2]);

int main() {
	int storeCount,length;
	ifstream in("lscin.txt");
	ofstream out("lscout.txt");
	in >> storeCount >> length;
	// printf("store num: %d length: %d \n",storeCount,length);
	int stores[storeCount];
	int sortedStores[storeCount];
	int storePos,storeIndex;
	for(int i=0;i<storeCount;i++) {
		in >> storePos;
		stores[i] = storePos;
	}
	for(int i=0;i<storeCount;i++) {
		in >> storeIndex;
		sortedStores[i] = stores[storeIndex-1];
		// cout << sortedStores[i] << endl;
	}
	vector <int> possiblePositions;
	if (storeCount == 0) {
		for(int i=1;i<=length;i++) {
			possiblePositions.push_back(i);
		}
	} else if (storeCount == 1) {
		for(int i=1;i<=length;i++) {
			if (i != stores[0]) possiblePositions.push_back(i);
		}
	// } else if (checkOrder(sortedStores,storeCount) == 1) {

	} else {
		int first,second,min,max;
		first = sortedStores[0];
		second = sortedStores[1];
		if (first < second) {
			min = first;
			max = second;
		} else {
			min = second;
			max = first;
		}
		int distance,flag,index,compPos;
		for(int position=min+1;position<max;position++){
			distance = 0;
			flag = 0;
			for(index=0;index<storeCount;index++) {
				compPos = sortedStores[index];
				if (abs(position-compPos) < distance) {
					flag = 1;
					break;
				}
				distance = abs(position-compPos);
			}
			if (flag == 0) {
				possiblePositions.push_back(position);
				// cout << position << endl;
			} else {
				break;
			}
		}
	}
	if (possiblePositions.size() == 0) {
		out << -1;
	} else {
		vector <int>::iterator position;
		for(position=possiblePositions.begin();position != possiblePositions.end();position++) {
			out << *position << endl;
		}
	}

	in.close();
	out.close();
}

// void getRanges(int first,int second,int array[2]) {
// 	int start,end;
// 	if (first < second) {
// 		start = first + 1;
// 		end = first + (second - first) / 2;
// 	} else {
// 		start = second + (first - second) / 2;
// 		end = first - 1;
// 	}
// 	array[0] = start;
// 	array[1] = end;
// }

int checkOrder(int sortedStores[],int storeCount) {
	int previousMin = sortedStores[0];
	int previousMax = sortedStores[0];
	int flag = 0;
	int currPosition;
	for(int i=1;i<storeCount;i++) {
		currPosition = sortedStores[i];
		if (currPosition > previousMax) {
			previousMax = currPosition;
		} else if (currPosition < previousMin) {
			previousMin = currPosition;
		} else {
			flag = 1;
			break;
		}
	}
	return flag;
}