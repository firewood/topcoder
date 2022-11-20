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
	int64_t N, Q, t, a, b;
	cin >> N >> Q;
	map<int, set<int>> m;
	for (int i = 0; i < Q; ++i) {
		cin >> t >> a >> b;
		--a;
		--b;
		if (t == 1) {
			m[a].insert(b);
		}
		if (t == 2) {
			if (m.find(a) != m.end()) {
				m[a].erase(b);
			}
		}
		if (t == 3) {
			bool both = m.find(a) != m.end() && m.find(b) != m.end() &&
				m[a].find(b) != m[a].end() && m[b].find(a) != m[b].end();
			cout << (both ? "Yes" : "No") << endl;
		}
	}
	return 0;
}
