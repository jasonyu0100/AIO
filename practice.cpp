#include <iostream>
#include <fstream>
#include <map>
using namespace std;
int fibonacii(int x);

int main(int argc, char const *argv[]) {
  map <int,int> cache;
  for(int i=0;i<10;i++) {
    cout << fibonacii(x,cache) << endl;
  }
  return 0;
}

int fibonacii(int x,map <int,int> cache) {
  if (cache.count(x) > 0) {
    return cache[x];
  } else if (x == 0 || x == 1) {
    return 1;
  } else {
    int value = fibonacii(x-1) + fibonacii(x-2);
    cache[x] = value;
    return value;
  }
}
