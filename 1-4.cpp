// Complexity O(n)

#include <algorithm>
#include <cstring>
#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <cctype>

#include <stdlib.h>

using namespace std;



bool hasPalindrome(string s) {
  map<char,int> letters;
  bool onlyOne = false;


  for (int i=0; i<s.size(); i++) {
    if (s[i] == ' ') continue;
    
    if (letters.find(s[i]) == letters.end()) {
      letters[ tolower(s[i]) ] = 1;
    } else {
      letters[ tolower(s[i]) ]++;
    }
  }

  map<char,int>::iterator it;
  for (it = letters.begin(); it != letters.end(); it++) {
    cout << it->first << " " << it->second << endl;
    if (it->second % 2 != 0 && !onlyOne) {
      onlyOne = true;
    } else if (it->second % 2 != 0) {
      return false;
    }
  }

  return true;
}

int main() {
  string s;
  getline(cin, s);

  cout << hasPalindrome(s) << endl;

  return 0;
}
