#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif

#include <algorithm>
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

void solve(long long N, std::vector<std::vector<long long>>& D) {
	bool ans = false;
	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		if (D[i][0] == D[i][1]) {
			++cnt;
			if (cnt == 3) ans = true;
		} else {
			cnt = 0;
		}
	}
	cout << (ans ? "Yes" : "No") << endl;
}

int main() {
    long long N;
	std::cin >> N;
	std::vector<std::vector<long long>> D(N, std::vector<long long>(2));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2; j++) {
			std::cin >> D[i][j];
		}
	}
	solve(N, D);
	return 0;
}
