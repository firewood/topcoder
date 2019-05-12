// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  int n, ans = 0, a = 0, b = 0, c = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < (int)s.length() - 1; ++j) {
      if (s[j] == 'A' && s[j + 1] == 'B') {
        ++ans;
      }
    }
    if (s.back() == 'A' && s[0] == 'B') {
      ++c;
    } else {
      if (s.back() == 'A') {
        ++a;
      } 
      if (s[0] == 'B') {
        ++b;
      }
    }
  }
  b += a ? c : max(0, c - 1);
  a += c;
  ans += min(a, b);
  cout << ans << endl;
  return 0;
}
