// D.

#include <sstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[])
{
  int n;
  LL w, w0;
  cin >> n >> w;
  vector<int> v[4];
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    int index = 0;
    if (i == 0) {
      w0 = a;
    } else {
      index = a - w0;
    }
    v[index].push_back(b);
  }
  for (int i = 0; i < 4; ++i) {
    sort(v[i].rbegin(), v[i].rend());
  }
  int ans = 0;
  for (int a = 0; a <= v[0].size(); ++a) {
    LL aw = a * w0;
    for (int b = 0; b <= v[1].size(); ++b) {
      LL bw = b * (w0 + 1);
      for (int c = 0; c <= v[2].size(); ++c) {
        LL cw = c * (w0 + 2);
        for (int d = 0; d <= v[3].size(); ++d) {
          LL dw = d * (w0 + 3);
          if (aw + bw + cw + dw > w) break;
          int sum = accumulate(v[0].begin(), v[0].begin() + a, 0)
                  + accumulate(v[1].begin(), v[1].begin() + b, 0)
                  + accumulate(v[2].begin(), v[2].begin() + c, 0)
                  + accumulate(v[3].begin(), v[3].begin() + d, 0);
          ans = max(ans, sum);
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
