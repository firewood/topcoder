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

typedef pair<int64_t, int64_t> II;

static const int64_t INF = 1LL << 60;

int main() {
	int64_t Q, T, X, K, x;
	std::cin >> Q;
	set<II> s;
	for (int i = 0; i < 5; ++i) {
		s.insert(II(-1, i));
		s.insert(II(INF, i));
	}
	for (int t = 0; t < Q; ++t) {
		cin >> T >> X;
		if (T == 1) {
			s.insert(II(X, t));
		} else if (T == 2) {
			cin >> K;
			auto it = s.lower_bound(II(X + 1, 0));
			for (int i = 0; i < K; ++i) {
				--it;
			}
			cout << it->first << endl;
		} else if (T == 3) {
			cin >> K;
			auto it = s.lower_bound(II(X, 0));
			for (int i = 1; i < K; ++i) {
				++it;
			}
			cout << (it->first < INF ? it->first : -1) << endl;
		}
	}
	return 0;
}
