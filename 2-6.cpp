// Complexity O(n)

#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <set>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void printList(list<char> l) {
  list<char>::iterator it;
  for(it = l.begin(); it != l.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
}

bool listIsPalindrome(string s) {
  list<char> left;
  int start;
  
  for (int i=0; i<s.size()/2; i++) {
    left.push_front(s[i]);
  }
  printList(left);

  start = (s.size() % 2 == 0 ? (s.size() / 2) : (s.size() / 2) + 1);
  for (int i=start; i<s.size(); i++) {
    if (s[i] != left.front()) return false;
    left.pop_front();
  }

  if (left.size() > 0) return false;
  return true;
}

int main() {

  string s;
  cin >> s;
  cout << listIsPalindrome(s) << endl;

  return 0;
}
