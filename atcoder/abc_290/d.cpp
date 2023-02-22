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

int64_t gcd(int64_t a, int64_t b) { return b ? gcd(b, a % b) : a; }
int64_t lcm(int64_t a, int64_t b) { return (a / gcd(a, b)) * b; }

int64_t solve2(int64_t N, int64_t D, int64_t K) {
	vector<int64_t> f(N);
	int64_t pos = 0;
	f[pos] = 1;
	for (int k = 1; k < K; ++k) {
		pos = (pos + D) % N;
		while (f[pos]) {
			pos = (pos + 1) % N;
		}
		f[pos] = 1;
	}
	return pos;
}

int64_t solve(int64_t N, int64_t D, int64_t K) {
	--K;
	int64_t c = N / gcd(N, D), y = K / c, r = K % c;
	return (D * r + y) % N;
}

int main() {
	int64_t T, N, D, K, ans = 0;
	cin >> T;
	for (int tt = 0; tt < T; ++tt) {
		cin >> N >> D >> K;
		cout << solve(N, D, K) << endl;
	}
	return 0;
}
