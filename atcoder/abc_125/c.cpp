// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main(int argc, char *argv[]) {
  int n, ans = 0;
  cin >> n;
  vector<int> a(n), fwd(n + 1), rev(n + 1);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    fwd[i + 1] = gcd(fwd[i], a[i]);
  }
  for (int i = n - 1; i >= 0; --i) {
    rev[i] = gcd(rev[i + 1], a[i]);
  }
  for (int i = 0; i < n; ++i) {
    ans = max(ans, gcd(fwd[i], rev[i + 1]));
  }
  cout << ans << endl;
  return 0;
}
