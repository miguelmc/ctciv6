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

void printList(list<int> l) {
  list<int>::iterator it;
  for(it = l.begin(); it != l.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
}

list<int> sumNum(list<int> l1, list<int> l2) {
  if (l1.size() == 0) return l2;
  if (l2.size() == 0) return l1;
  
  int curr;
  list<int> res, other;

  curr = l1.front() + l2.front();
  l1.pop_front();
  l2.pop_front();

  if (curr/10 > 0) {
    curr = curr%10;

    if (l1.size() > 0) {
      l1.front() += 1;
    } else {
      l1.push_back(1);
    }
  }
  res.push_front(curr);
  other = sumNum(l1,l2);

  res.splice(res.end(), other);
  return res;

}

int main() {
  list<int> l1, l2, res;

  int n1, n2, temp;

  cin >> n1 >> n2;

  for (int i=0; i<n1; i++) {
    cin >> temp;
    l1.push_front(temp);
  }
  for (int i=0; i<n2; i++) {
    cin >> temp;
    l2.push_front(temp);
  }

  res = sumNum(l1, l2);
  printList(res);

  return 0;
}
