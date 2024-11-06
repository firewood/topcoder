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

typedef long double LD;
typedef pair<int64_t, int64_t> II;
typedef pair<int64_t, II> III;

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

int main() {
	int64_t N, M, ans = 0, sum = 0;
	cin >> N >> M;

	vector<int64_t> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		A[i] %= M;
	}

	BIT bit(400004);
	int offset = 0;

	for (int i = 0; i < N; ++i) {
		int r = A[i];
		int right = ((M - offset) % M);
		int left = max(0, right - r);

		sum -= (bit.sum(right) - bit.sum(left)) * M;
		r -= right - left;
		if (r > 0) {
			sum -= (bit.sum(M) - bit.sum(M - r)) * M;
		}

		bit.add(right + 1, 1);
		offset = (offset + A[i]) % M;
		sum += A[i] * (i + 1);
		ans += sum;
	}

	cout << ans << endl;
	return 0;
}
