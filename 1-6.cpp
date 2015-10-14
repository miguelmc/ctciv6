// ~O(n) complexity, assuming string concatenation
//    Always expands by doubling its size.
// Could be made more efficient knowing the final string
// length from the beggining.
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

int getLengthInt(int n) {
  int res=1, i=1;
  while(n/(10*i)) {
    res++;
    i*=10;
  }
  return res;
}

string compress(string s) {
  if (s.size() <= 2) return s;
  
  string res = "";
  char currC = s[0];
  int l, err=0, currN = 1;

  for (int i=1; i<s.size(); i++) {
    if (currC != s[i]) {
      l = getLengthInt(currN);
      char buff[l];
      err = sprintf(buff, "%d", currN);
      assert(err > 0);

      res += currC;
      res += buff;

      currC = s[i];
      currN = 1;
    } else {
      currN++;
    }
  }

  // Add the last sequence to string.
  l = getLengthInt(currN);
  char buff[l];
  err = sprintf(buff, "%d", currN);
  res += currC;
  res += buff;

  // Return the min
  return (res.size() < s.size() ? res : s);
}

int main() {
  string s;

  cin >> s;

  cout << compress(s) << endl;

  return 0;
}
