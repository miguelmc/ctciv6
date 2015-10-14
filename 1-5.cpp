// Complexity looks 3^n, but it's O(n). This is because the path with 3 recursion
// calls will only be called once. This would make it at maximum 3n time.

#include <algorithm>
#include <cctype>
#include <math.h>
#include <cstring>
#include <iostream>
#include <limits>
#include <map>
#include <set>

#include <stdlib.h>

using namespace std;

bool oneAway(string s1, string s2, int n1, int n2, int diff) {
  cout << n1 << " " << n2 << " " << diff << endl;
  if (n1 == s1.size() && n2 == s2.size()) return true;
  if (n1 == s1.size() || n2 == s2.size()) return (diff == 0 ? true : false);

  if (s1[n1] == s2[n2]) return oneAway(s1,s2,n1+1,n2+1,diff);
  if (s1[n1] != s2[n2] && diff == 0) {
    return oneAway(s1,s2,n1+1,n2+1,1) ||
           oneAway(s1,s2,n1+1,n2,1) ||
           oneAway(s1,s2,n1,n2+1,1);
  }

  return false;
}

bool oneAwayWrapper(string s1, string s2) {
  // Conditions that make us know right away.
  if (s1 == s2) return true;
  if (fabs(s1.size() - s2.size()) > 1) return false;

  return oneAway(s1, s2, 0, 0, 0);
}

int main() {

  string s1, s2;

  cin >> s1 >> s2;

  cout << oneAwayWrapper(s1, s2) << endl;

  return 0;
}
