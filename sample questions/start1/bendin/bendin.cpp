// #include <iostream>
// #include <fstream>

// // using std::ifstream;
// // using std::ofstream;
// using namespace std;

// bool intersection(int x,int y,int x1,int y1,int x2,int y2);

// int main() {
// 	int x1,y1,x2,y2,x3,y3,x4,y4,area;
// 	int totalArea = 0;

// 	ifstream inputFile("bendin.txt");
// 	ofstream outputFile("bendout.txt");
// 	inputFile >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

// 	area = abs(x1-x2) * abs(y1-y2);
// 	totalArea += area;
// 	area = abs(x3-x4) * abs(y3-y4);
// 	totalArea += area;
	
// 	int values1[2];
// 	int flag1 = 0;
// 	if (intersection(x1,y1,x3,y3,x4,y4) == true) {
// 		values1[0] = x1;
// 		values1[1] = y1;
// 		flag1 += 1;
// 	} if (intersection(x2,y2,x3,y3,x4,y4) == true) {
// 		values1[0] = x2;
// 		values1[1] = y2;
// 		flag1 += 1;
// 	}

// 	int values2[2];
// 	int flag2 = 0;
// 	if (intersection(x3,y3,x1,y1,x2,y2) == true) {
// 		values2[0] = x3;
// 		values2[1] = y3;
// 		flag2 += 1;
// 	} if (intersection(x4,y4,x1,y1,x2,y2) == true) {
// 		values2[0] = x4;
// 		values2[1] = y4;
// 		flag2 += 1;
// 	}
// 	if (flag1 == 1 && flag2 == 1) {
// 		// cout << "intersection" << endl;
// 		totalArea -= abs(values1[0] - values2[0]) * abs(values1[1] - values2[1]); // Partial Intersection
// 	} else if (flag1 == 2) {
// 		// cout << "complete intersection first" << endl;
//  		totalArea -= abs(x1-x2) * abs(y1-y2); // Complete intersection of first rectangle
// 	} else if (flag2 == 2) {
// 		// cout << "complete intersection second" << endl;
// 		totalArea -= abs(x3-x4) * abs(y3-y4); // Complete intersection of second rectangle
// 	}
// 	// cout << totalArea << endl;
// 	outputFile << totalArea;

// 	inputFile.close();
// 	outputFile.close();
// 	return 0;
// }

// bool intersection(int x,int y,int x1, int y1,int x2,int y2) {
// 	if (abs(x1-x) + abs(x2-x) == abs(x1-x2)) {
// 		if (abs(y1-y) + abs(y2-y) == abs(y1-y2)) {
// 			return true;
// 		}
// 	}
// 	return false;
// }


#include <cstdio>

int min(int a, int b) {
	//takes two numbers and returns the smaller one
	if (a < b) {
		return a;
	} else {
		return b;
	}
}
int max(int a, int b) {
	//takes two numbers and returns the bigger one
	if (a > b) {
		return a;
	} else {
		return b;
	}
}

int main() {
	int left_1, bottom_1, right_1, top_1;
	int left_2, bottom_2, right_2, top_2;
	int left_intr, bottom_intr, right_intr, top_intr;
	
	int area_1, area_2, area_intr, area_total;

	FILE* inputFile = fopen("bendin.txt","r");
	FILE* outputFile = fopen("bendout.txt","w");
	
	/*Read the input.*/
	fscanf(inputFile,"%d %d %d %d",&left_1,&bottom_1,&right_1,&top_1);
	fscanf(inputFile,"%d %d %d %d",&left_2,&bottom_2,&right_2,&top_2);
	
	/*Calculate the intersection co-ordinates.*/
	left_intr = max(left_1,left_2);
	bottom_intr = max(bottom_1,bottom_2);
	right_intr = min(right_1,right_2);
	top_intr = min(top_1,top_2);
	
	/*Calculate the areas of the rectangles and the intersection.*/
	area_1 = (right_1-left_1) * (top_1-bottom_1);
	area_2 = (right_2-left_2) * (top_2-bottom_2);
	if (left_intr < right_intr && bottom_intr < top_intr) {
		//The intersection makes sense
		area_intr = (right_intr-left_intr) * (top_intr-bottom_intr);
	} else {
		//There doesn't seem to be an intersection
		area_intr = 0;
	}
	area_total = area_1 + area_2 - area_intr;

	/*Write the output.*/
	fprintf(outputFile,"%d\n",area_total);

	/*Clean up!*/
	fclose(inputFile);
	fclose(outputFile);
}



