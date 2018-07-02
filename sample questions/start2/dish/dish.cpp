#include <iostream>
#include <fstream>

using namespace std;

int averageVal(int array[], int n);
int minVal(int array[], int n);
int maxVal(int array[],int n);

int main() {
	int count,currVal;
	ifstream in("dishin.txt");
	ofstream out("dishout.txt");

	in >> count;
	int values[count];
	for(int i=0;i<count;i++) {
		in >> currVal;
		values[i] = currVal;
	}

	out << minVal(values,count) << " " << maxVal(values,count) << " " << averageVal(values,count);

	in.close();
	out.close();
}

int averageVal(int array[],int n) {
	int total = 0;
	for (int i=0;i<n;i++) {
		total += array[i];
	}
	return total / n;
}
int minVal(int array[],int n) {
	int min = array[0];
	for (int i=1;i<n;i++) {
		if (array[i] < min) {
			min = array[i];
		}
	}
	return min;
}
int maxVal(int array[],int n) {
	int max = array[0];
	for (int i=1;i<n;i++) {
		if (array[i] > max) {
			max = array[i];
		}
	}
	return max;
}

