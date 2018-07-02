#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

vector <int> findPossiblePositions(int precedences[],int storeNum);
void getStartEnd(int first,int second,int array[]);

int main() {
	int storeNum,length,currPos,precedence;
	ifstream in("lscin.txt");
	ofstream out("lscout.txt");
	in >> storeNum >> length;
	int stores[storeNum];
	int precedences[storeNum];
	for(int i=0;i<storeNum;i++) {
		in >> currPos;
		stores[i] = currPos;
	}

	in >> precedence;
	int value = stores[precedence-1];
	precedences[0] = value;
	int previousMin = value;
	int previousMax = value;
	int flag = 0;
	for(int i=1;i<storeNum;i++) {
		// cout << previousMin << " " << previousMax << endl;
		in >> precedence;
		value = stores[precedence-1];
		if (value > previousMax) {
			previousMax = value;
		} else if (value < previousMin) {
			previousMin = value;
		} else {
			flag = 1;
			break;
		}
		precedences[i] = value;
	}
	if (storeNum == 0) {
		for (int i = 1;i<=length;i++) {
			out << i << endl;
		} 
	} else if (storeNum == 1) {
		for (int i = 1;i<=length;i++) {
			if (i != stores[0]) {
				out << i << endl;
			}
		} 
	} else if (storeNum == 2) {
		int min,max;
		if (stores[0] < stores[1]) {
			min = stores[0];
			max = stores[1];
		} else {
			min = stores[1];
			max = stores[0];
		}
		for (int i = min+1;i<max;i++) {
			out << i << endl;
		} 
	} else if (flag == 1) {
		out << -1;
	} else {
		vector <int> possiblePositions = findPossiblePositions(precedences,storeNum);
		if (possiblePositions.size() == 0) {
			out << -1;
		} else {
			for (int possible : possiblePositions) {
				out << possible << endl;
			}
		}
	}
	in.close();
	out.close();
}

vector <int> findPossiblePositions(int precedences[],int storeNum) {
	int first = precedences[0];
	int second = precedences[1];
	int third = precedences[2];
	vector <int> possiblePositions;
	int rangeOne[2];
	getStartEnd(first,second,rangeOne);
	int start = rangeOne[0];
	int end = rangeOne[1];
	int rangeTwo[2];
	getStartEnd(second,third,rangeTwo);
	int start2 = rangeTwo[0];
	int end2 = rangeTwo[1];

	printf("range: %d %d range 2: %d %d\n", start,end,start2,end2);
	// cout << start << " " << end << endl;
	int prevDistance;
	int flag;
	int checkPos;
	for(int position=start;position<=end;position++){
		prevDistance = 0;
		flag = 0;
		for (int index=0;index<storeNum;index++) {
			checkPos = precedences[index];
			if (abs(position-checkPos) < prevDistance) {
				flag = 1;
				break;
			}
			prevDistance = abs(position-checkPos);
		}
		if (flag == 0) {
			possiblePositions.push_back(position);
		}
	}
	return possiblePositions;
}

void getStartEnd(int first,int second,int array[2]) {
	int start,end;
	if (first < second) {
		// first -> mid
		start = first + 1;
		end = first + ((second - first) / 2);
	} else {
		// mid -> first
		start = second + ((first - second) / 2);
		end = first - 1;
	}
	array[0] = start;
	array[1] = end;
}