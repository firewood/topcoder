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

class BIT {
	std::vector<int64_t> bit;
	int64_t size;
public:
	BIT() { }
	BIT(int64_t sz) { init(sz); }
	void init(int64_t sz) {
		bit = std::vector<int64_t>((size = sz) + 1);
	}
	int64_t sum(int64_t i) {
		int64_t s = 0;
		while (i > 0) {
			s += bit[i];
			i -= i & -i;
		}
		return s;
	}
	void add(int64_t i, int64_t x) {
		while (i <= size) {
			bit[i] += x;
			i += i & -i;
		}
	}
};

int solve(int N, const vector<int> &P) {
	int ans = 0;

	vector<int> ord(N);
	for (int i = 0; i < N; i++) {
		ord[P[i]] = i;
	}

	BIT bit(N + 2);
	for (int i = 0; i < N; ++i) {
		int x = ord[i] + 1;
		ans += (bit.sum(N + 1) - bit.sum(x)) == 0;
		bit.add(x, 1);
	}
	return ans;
}

int main() {
	int T, N;
	cin >> T;
	for (int tt = 0; tt < T; ++tt) {
		cin >> N;
		vector<int> P(N);
		for (int i = 0; i < N; i++) {
			cin >> P[i];
			--P[i];
		}
		cout << solve(N, P) << endl;
	}
	return 0;
}
