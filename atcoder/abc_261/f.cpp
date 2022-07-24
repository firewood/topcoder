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

int64_t solve(int64_t N, std::vector<int> C, std::vector<int> X) {
	int64_t same_color = 0, ans = 0, start = 0, cnt = 0;
	BIT bit(300002);
	vector<int> seq(N);
	iota(seq.begin(), seq.end(), 0);
	sort(seq.begin(), seq.end(), [&](int lhs, int rhs) {
		return make_pair(C[lhs], lhs) < make_pair(C[rhs], rhs);
	});
	for (int64_t i = 0; i < N; ++i) {
		same_color += cnt++ - bit.sum(X[seq[i]]);
		bit.add(X[seq[i]], 1);
		// cleanup
		if (i == N - 1 || C[seq[i]] != C[seq[i + 1]]) {
			for (int64_t j = start; j <= i; ++j) {
				bit.add(X[seq[j]], -1);
			}
			start = i + 1;
			cnt = 0;
		}
	}
	for (int64_t i = 0; i < N; ++i) {
		ans += i - bit.sum(X[i]);
		bit.add(X[i], 1);
	}
	return ans - same_color;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int> C(N);
	for (int i = 0; i < N; i++) {
		std::cin >> C[i];
	}
	std::vector<int> X(N);
	for (int i = 0; i < N; i++) {
		std::cin >> X[i];
	}
	cout << solve(N, C, X) << endl;
	return 0;
}
