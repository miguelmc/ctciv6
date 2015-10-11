// Complexity O(n)


#include <algorithm>
#include <cstring>
#include <iostream>
#include <limits>
#include <map>
#include <set>

#include <stdlib.h>

using namespace std;

void URLify(string &s, int trueSize) {
  int realSize = s.size();
  int insertionPtr = realSize-1;

  for (int i=trueSize-1; i>=0; i--) {
    if (s[i] == ' ') {
      s[insertionPtr--] = ' ';
      s[insertionPtr--] = ' ';
      s[insertionPtr--] = ' ';
    } else {
      s[insertionPtr--] = s[i];
    }
  }


  for (int i=0; i<realSize; i++) {
    
    if (s[i] == ' ') {
      s[i++] = '%';
      s[i++] = '2';
      s[i] = '0';
    }
  }

}


int main() {

  string s;
  getline (cin, s);
  int trueSize = s.size();
  for (int i=0; i<trueSize; i++) {
    if (s[i] == ' ') {
      s += "  ";
    }
  }
  URLify(s, trueSize);
  cout << s << endl;

  return 0;
}
