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

typedef long long LL;

LL solve(int R, int C, int K, int N, std::vector<LL> &r, std::vector<LL> &c) {
	LL ans = 0;
	vector<LL> hsum(C), hcount(N + 1), vsum(R), vcount(N + 1);
	for (int i = 0; i < N; i++) {
		hsum[c[i]] += 1;
		vsum[r[i]] += 1;
	}
	for (int i = 0; i < C; i++) {
		hcount[hsum[i]] += 1;
	}
	for (int i = 0; i < R; i++) {
		vcount[vsum[i]] += 1;
	}
	for (int h = 0; h <= K; ++h) {
		ans += hcount[h] * vcount[K - h];
	}
	for (int i = 0; i < N; i++) {
		ans -= hsum[c[i]] + vsum[r[i]] == K;
		ans += hsum[c[i]] + vsum[r[i]] == K + 1;
	}
	return ans;
}

int main() {
	LL R, C, K, N;
	std::cin >> R >> C >> K >> N;
	std::vector<LL> r(N), c(N);
	for (int i = 0; i < N; i++) {
		std::cin >> r[i] >> c[i];
		--r[i]; --c[i];
	}
	cout << solve(R, C, K, N, r, c) << endl;
	return 0;
}
