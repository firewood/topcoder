#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int T, n, m, x;
	cin >> T;
	for (int tt = 0; tt < T; ++tt) {
		int ans = 0;
		cin >> n >> m;
		set<int> s;
		for (int i = 0; i < n; ++i) {
			cin >> x;
			s.insert(x);
		}
		for (int i = 0; i < m; ++i) {
			cin >> x;
			ans += s.find(x) != s.end();
		}
		cout << ans << endl;
	}
	return 0;
}
