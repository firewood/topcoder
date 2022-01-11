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

int64_t solve(int64_t N, std::vector<int64_t> B) {
	int64_t ans = 0;
	BIT bit(N);
	vector<int> pos(N + 1);
	for (int i = 0; i < N; ++i) {
		bit.add(i + 1, 1);
		pos[B[i]] = i + 1;
	}
	for (int i = 1; i <= N; ++i) {
		bit.add(pos[i], -1);
		int left = bit.sum(pos[i]), right = bit.sum(N) - left;
		ans += min(left, right);
	}
	return ans;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> B(N);
	for (int i = 0; i < N; i++) {
		std::cin >> B[i];
	}
	cout << solve(N, B) << endl;
	return 0;
}
