// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	int n, k;
	cin >> n >> k;
  static int f[4000][4000];
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    char c;
    cin >> c;
    if (c == 'B') {
      x += k;
    }
    for (int p = 0; p < 4; ++p) {
      for (int q = 0; q < 2; ++q) {
        f[(y + p * k) % (4 * k)][(x + ((p % 2) + q * 2) * k) % (4 * k)] += 1;
      }
    }
  }

  static int sum[4000][4000];
  for (int i = 0; i < 4 * k; ++i) {
    int t = 0;
    for (int j = 0; j < 4 * k; ++j) {
      t += f[i][j];
      sum[i][j] = t + (i == 0 ? 0 : (sum[i-1][j]));
    }
  }
  int ans = 0;
  for (int i = 0; i <= 3 * k; ++i) {
    for (int j = 0; j <= 3 * k; ++j) {
      int t = sum[i + k - 1][j + k - 1];
      if (i) {
        t -= sum[i - 1][j + k - 1];
      }
      if (j) {
        t -= sum[i + k - 1][j - 1];
      }
      if (i && j) {
        t += sum[i - 1][j - 1];
      }
      ans = max(ans, t);
    }
  }
  cout << ans << endl;
  return 0;
}
