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

void printList(list<int> l) {
  list<int>::iterator it;
  for(it = l.begin(); it != l.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
}

void cortar(list<int> &l, int partition) {
  list<int>::iterator curr;
  list<int>::iterator nextSmall;
  int temp;

  nextSmall = l.end();
  --nextSmall;
  for(curr = l.begin(); curr != nextSmall; curr++) {
    if (*curr >= partition) {
      while(nextSmall != curr && *nextSmall >= 5) {
        --nextSmall;
      }
      if (nextSmall == curr) break;

      temp = *curr;
      *curr = *nextSmall;
      *nextSmall = temp;
    }
  }
}

int main() {
  list<int> l;
  int n, num, partition;

  cin >> n;

  for (int i=0; i<n; i++) {
    cin >> num;
    l.push_back(num);
  }

  cin >> partition;

  printList(l);
  cortar(l, partition);
  printList(l);


  return 0;
}
