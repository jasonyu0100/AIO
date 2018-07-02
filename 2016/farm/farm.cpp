#include <iostream>
#include <fstream>
#include <set>
using namespace std;
int fenceDivider(int fencePositions[],int fenceNum);

int main() {
  ifstream in("farmin.txt");
  ofstream out("farmout.txt");
  int size,curr;
  in >> size;
  int list[size];
  for(int i=0;i<size;i++){
    in >> curr;
    list[i] = curr;
  }
  int count = fenceDivider(list,size);
  cout << count << endl;
  out << count;
  in.close();
  out.close();
}

int fenceDivider(int fencePositions[],int fenceNum) {
  int count = 0;
  int size = 0;
  int fencePosition = 0;
  int left,right;
  set <int> fencePositionSet;
  for(int i=0;i<fenceNum;i++){
    size += fencePositions[i];
    if (i != fenceNum - 1) {
      fencePositionSet.insert(size);
    }
  }
  for(int i=0;i<fenceNum;i++){
    fencePosition += fencePositions[i];
    left = fencePosition;
    right = size - fencePosition;
    if (fencePositionSet.count(left)>0 && fencePositionSet.count(right)==0){
      count ++;
    } else if (fencePositionSet.count(right)>0 && fencePositionSet.count(left)==0) {
      count ++;
    }
  }

  return count;
}
