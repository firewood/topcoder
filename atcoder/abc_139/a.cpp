// A.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
  string s, t;
  cin >> s >> t;
  int ans = 0;
  for (int i = 0; i < 3; ++i) {
    ans += s[i] == t[i];
  }
  cout << ans << endl;
  return 0;
}
