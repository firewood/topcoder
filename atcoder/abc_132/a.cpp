// A.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
  char cnt[256] = {};
  string s;
  cin >> s;
  for (char c : s) {
    cnt[c] += 1;
  }
  bool ok = true;
  for (int i = 'A'; i <= 'Z'; ++i) {
    if (cnt[i] != 0 && cnt[i] != 2) {
      ok = false;
    }
  }
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}
