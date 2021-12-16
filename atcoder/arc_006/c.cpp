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

int64_t solve(int64_t N, std::vector<int64_t> w) {
	set<int64_t> s;
	for (int i = N - 1; i >= 0; --i) {
		int64_t x = -w[i];
		auto it = s.lower_bound(x);
		if (it != s.end()) {
			s.erase(it);
		}
		s.insert(x);
	}
	return s.size();
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> w(N);
	for (int i = 0; i < N; i++) {
		std::cin >> w[i];
	}
	cout << solve(N, w) << endl;
	return 0;
}
