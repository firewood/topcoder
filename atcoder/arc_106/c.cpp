#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif

#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

void solve(int N, int M) {
	if (M < 0 || (M != 0 && M >= N - 1)) {
		cout << -1 << endl;
	} else {
		for (int i = 1; i <= N; ++i) {
			if (M > 0 && i < N - M) {
				cout << i * 2 << " " << 1000000 - i << endl;
			} else {
				cout << i * 2 << " " << i * 2 + 1 << endl;
			}
		}
	}
}

int main() {
	int N, M;
	std::cin >> N >> M;
	solve(N, M);
	return 0;
}
