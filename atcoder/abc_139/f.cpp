// F.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

typedef long long LL;
typedef long double LD;

int n;
vector<LD> x, y;
vector<LD> angle;

double calc(LD r) {
  LD xs = 0, ys = 0;
  for (int i = 0; i < n; ++i) {
    if (r - M_PI/2 <= angle[i] && angle[i] <= r + M_PI/2) {
      xs += x[i], ys += y[i];
    }
  }
  return sqrt(xs * xs + ys * ys);
}


int main(int argc, char* argv[]) {
  cout.precision(12);

  cin >> n;
  x.resize(n);
  y.resize(n);
  angle.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
    angle[i] = atan2(y[i], x[i]);
    if (angle[i] < 0) {
      angle[i] += 2 * M_PI;
    }
  }
  LD left = 0, right = 2 * M_PI;

  for (int t = 0; t < 1000; ++t) {
    if (calc((left * 2 + right) / 3) > calc((left + right * 2) / 3)) {
      right = (left + right * 2) / 3;
    } else {
      left = (left * 2 + right) / 3;
    }
  }
  LD ans = calc(left);

  for (int i = 0; i < n; ++i) {
    angle[i] = atan2(x[i], y[i]);
    if (angle[i] < 0) {
      angle[i] += 2 * M_PI;
    }
  }
  left = 0, right = 2 * M_PI;

  for (int t = 0; t < 1000; ++t) {
    if (calc((left * 2 + right) / 3) > calc((left + right * 2) / 3)) {
      right = (left + right * 2) / 3;
    } else {
      left = (left * 2 + right) / 3;
    }
  }
  LD ans2 = calc(left);
  if (ans2 > ans) {
    ans = ans2;
  }

  cout << ans << endl;
  return 0;
}
