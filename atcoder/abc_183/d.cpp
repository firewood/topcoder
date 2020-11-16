#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;

typedef long long LL;
static const LL INF = 1LL << 60;

class BIT {
	std::vector<long long> bit;
	long long size;
public:
	BIT() { }
	BIT(long long sz) { init(sz); }
	void init(long long sz) {
		bit = std::vector<long long>((size = sz) + 1);
	}
	long long sum(long long i) {
		LL s = 0;
		while (i > 0) {
			s += bit[i];
			i -= i & -i;
		}
		return s;
	}
	void add(long long i, long long x) {
		while (i <= size) {
			bit[i] += x;
			i += i & -i;
		}
	}
};

bool solve(long long N, long long W, std::vector<long long> &S, std::vector<long long> &T, std::vector<long long> &P) {
	BIT bit(200004);
	for (int i = 0; i < N; i++) {
		bit.add(S[i] + 1, P[i]);
		bit.add(T[i] + 1, -P[i]);
	}
	for (int i = 0; i <= 200000; ++i) {
		if (bit.sum(i + 1) > W) return false;
	}
	return true;
}

int main() {
    long long N, W;
	std::cin >> N >> W;
	std::vector<long long> S(N), T(N), P(N);
	for (int i = 0; i < N; i++) {
		std::cin >> S[i] >> T[i] >> P[i];
	}
	bool ans = solve(N, W, S, T, P);
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}
