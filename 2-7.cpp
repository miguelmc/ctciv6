// O(n)

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

// Returns refernce of element that intersects, l1.end() otherwise
list<int>::iterator intersection(list<int> l1, list<int> l2) {
  set<list<int>::iterator> nodes;

  list<int>::iterator it;
  for (it = l1.begin(); it != l1.end(); it++) {
    nodes.insert(it);
  }
  
  for (it = l1.begin(); it != l1.end(); it++) {
    if (nodes.find(it) != nodes.end()) {
      return it;
    }
  }
  
  return l1.end();
}

int main() {
  // Mucho rollo

  return 0;
}
