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

int solve(int N, std::vector<int> a) {
	int ans = -1e9;
	for (int i = 0; i < N; ++i) {
		int amx = -1e9, bmx = -1e9;
		for (int j = 0; j < N; ++j) {
			if (i == j) continue;
			int st = min(i, j), ed = max(i, j), asum = 0, bsum = 0;
			for (int k = st; k <= ed; ++k) {
				(((k - st) % 2) ? bsum : asum) += a[k];
			}
			if (bsum > bmx) {
				amx = asum;
				bmx = max(bmx, bsum);
			}
		}
		ans = max(ans, amx);
	}
	return ans;
}

int main() {
	int N;
	std::cin >> N;
	std::vector<int> a(N);
	for (int i = 0; i < N; i++) {
		std::cin >> a[i];
	}
	cout << solve(N, a) << endl;
	return 0;
}
