// D,

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[]) {
  LL n, ans = 0;
  cin >> n;
  vector<LL> p, c, d;
  ans = 0;
  LL r = sqrt(n), x = n;
  for (LL i = 2; i <= r; ++i) {
    if ((x % i) == 0) {
      LL cnt = 0;
      while ((x % i) == 0) {
        x /= i;
        ++cnt;
      }
      p.push_back(i);
      c.push_back(cnt);
    }
  }
  if (x > 1 || p.empty()) {
    p.push_back(x);
    c.push_back(1);
  }
  d.resize(c.size());

  x = 1;
  int i;
  do {
    LL m = n / x - 1;
    if (x < m) {
      ans += m;
    }
    for (i = 0; i < (int)d.size(); ++i) {
      if (++d[i] <= c[i]) {
        x *= p[i];
        break;
      }
      d[i] = 0;
      for (int j = 0; j < c[i]; ++j) {
        x /= p[i];
      }
    }
  } while (i < (int)d.size());
  cout << ans << endl;
  return 0;
}
