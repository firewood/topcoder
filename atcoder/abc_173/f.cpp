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

int64_t solve(int64_t N, std::vector<int64_t> u, std::vector<int64_t> v) {
	int64_t ans = N * (N + 1) * (N + 2) / 6;
	for (int i = 0; i < u.size(); ++i) {
		ans -= min(u[i], v[i]) * (N - max(u[i], v[i]) + 1);
	}
	return ans;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> u(N-1), v(N-1);
	for (int i = 0; i < N-1; i++) {
		std::cin >> u[i] >> v[i];
	}
	cout << solve(N, u, v) << endl;
	return 0;
}
