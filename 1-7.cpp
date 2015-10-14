// O(n^2)

#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <stdlib.h>
#include <stdio.h>
#include <cassert>

#include <stdlib.h>

using namespace std;

void printMat(int* M, int n) {
  for(int i = 0; i<n; i++) {
    for(int j = 0; j<n; j++) {
      cout << *(M+j+i*n) << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void rot90Deg(int* M, int n) {
  for(int i = 0; i<n; i++) {
    for(int j = n-i-1; j>=0; j--) {
      // cout << "swapping " << *(M+j+i*n) << " " << *(M+(n-i-1)+(n-j-1)*n) << endl;
      int temp = *(M+j+i*n);
      *(M+j+i*n) = *(M+(n-i-1)+(n-j-1)*n);
      *(M+(n-i-1)+(n-j-1)*n) = temp;
    }
    printMat(M, n);
  }
}

int main() {

  int n;

  cin >> n;

  int* M = (int*)malloc(n*n*sizeof(int));

  for(int i = 0; i<n; i++) {
    for(int j = 0; j<n; j++) {
      cin >> *(M+j+i*n);
    }
  }

  cout << "Before: \n";
  printMat(M, n);

  cout << "After: \n";
  rot90Deg(M, n);
  printMat(M, n);

  return 0;
}
