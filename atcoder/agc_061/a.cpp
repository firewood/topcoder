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

void shuffle(int64_t L, int64_t R, vector<int>& a) {
	if (L >= R) return;
	if (L + 1 == R) {
		swap(a[L], a[R]);
	} else {
		shuffle(L, R - 1, a);
		shuffle(L + 1, R, a);
	}
}

int64_t solve2(int64_t N, int64_t K) {
	vector<int> a(N);
	iota(a.begin(), a.end(), 0);
	shuffle(0, N - 1, a);
	return a[K];
}

int64_t solve(int64_t N, int64_t K) {
	if (K == 0) {
		return 1;
	} else if (N & 1) {
		if (K == N - 2) {
			return N - 1;
		}
		return solve(N - 1, solve(N - 1, K - 1) + 1);
	} else {
		if ((((N - 2) / 2) & (K / 2)) == K / 2) {
			return K ^ 1;
		} else {
			return K;
		}
	}
}

int main() {
	int64_t T, N, K;
	cin >> T;
	for (int tt = 0; tt < T; ++tt) {
		cin >> N >> K;
		--K;
		cout << (solve(N, K) + 1) << endl;
	}
	return 0;
}
