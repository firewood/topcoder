// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

int main(int argc, char* argv[]) {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  double ans = v.front();
  for (int i = 1; i < n; ++i) {
    ans = (ans + v[i]) / 2;
  }
  cout << ans << endl;
  return 0;
}

