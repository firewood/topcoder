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

static const int64_t INF = 1LL << 60;

int main() {
	int64_t N, Q, t, x, y, default_value = 0;
	cin >> N;
	map<int64_t, int64_t> m;
	for (int i = 0; i < N; i++) {
		cin >> x;
		m[i + 1] = x;
	}
	cin >> Q;
	for (int tt = 0; tt < Q; ++tt) {
		cin >> t >> x;
		if (t == 1) {
			m.clear();
			default_value = x;
		}
		if (t == 2) {
			cin >> y;
			y += m.find(x) == m.end() ? default_value : m[x];
			m[x] = y;
		}
		if (t == 3) {
			y = m.find(x) == m.end() ? default_value : m[x];
			cout << y << endl;
		}
	}
	return 0;
}
