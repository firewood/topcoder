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

typedef pair<int64_t, int64_t> II;

int64_t solve(int64_t N, std::vector<int64_t> x, std::vector<int64_t> y) {
	int64_t ans = 0;
	set<II> p;
	for (int i = 0; i < N; ++i) {
		p.insert(II(x[i], y[i]));
	}
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			if (x[i] == x[j] || y[i] == y[j]) continue;
			ans += p.find(II(x[i], y[j])) != p.end() && p.find(II(x[j], y[i])) != p.end();
		}
	}
	return ans / 2;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> x(N), y(N);
	for (int i = 0; i < N; i++) {
		std::cin >> x[i] >> y[i];
	}
	cout << solve(N, x, y) << endl;
	return 0;
}
