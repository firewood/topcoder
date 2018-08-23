// D.

#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int n, m, q;
  cin >> n >> m >> q;
  static int ep[512][512];
  for (int i = 0; i < m; ++i) {
    int l, r;
    cin >> l >> r;
    for (int j = 1; j <= l; ++j) {
      ep[j][r] += 1;
    }
  }
  for (int i = 0; i < q; ++i) {
    int p, q;
    cin >> p >> q;
    int ans = 0;
    for (int j = p; j <= q; ++j) {
      ans += ep[p][j];
    }
    cout << ans << endl;
  }
  return 0;
}
