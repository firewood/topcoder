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
#include <atcoder/modint>

using namespace std;

using mint = atcoder::modint998244353;

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

void solve(int N, std::vector<int> A) {
	BIT bcnt(200002);
	BIT bsum(200002);
	mint ans = 0, sum = 0;
	for (int i = 0; i < N; ++i) {
		ans *= i;
		ans *= i;
		ans += A[i];
		ans += 2 * (sum - bsum.sum(A[i] - 1) + bcnt.sum(A[i] - 1) * A[i]);
		ans /= (i + 1);
		ans /= (i + 1);
		cout << ans.val() << endl;
		bcnt.add(A[i], 1);
		bsum.add(A[i], A[i]);
		sum += A[i];
	}
}

int main() {
	int N;
	std::cin >> N;
	std::vector<int> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	solve(N, A);
	return 0;
}
