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

int64_t solve(int64_t N, std::vector<int64_t> H) {
	int64_t ans = 0, h = -INF;
	for (int i = 0; i < N; ++i) {
		if (H[i] > h) {
			h = H[i];
			ans = i + 1;
		}
	}
	return ans;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> H(N);
	for (int i = 0; i < N; i++) {
		std::cin >> H[i];
	}
	cout << solve(N, H) << endl;
	return 0;
}
