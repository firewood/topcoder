// A.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  int n, m, a;
  cin >> n >> m;
  vector<pair<int, int> > v(n);
  for (int i = 0; i < n; ++i) {
    v[i] = make_pair(i + 1, i + 1);
  }
  for (int i = 0; i < m; ++i) {
    cin >> a;
    v[a - 1].first = -i;
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; ++i) {
    cout << v[i].second << endl;
  }
	return 0;
}
