// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<int> a(n);
  double m = 1;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    m *= a[i];
  }
  double s = 0;
  for (int i = 0; i < n; ++i) {
    s += m / a[i];
  }
  double ans = m / s;
  cout << ans << endl;
  return 0;
}
