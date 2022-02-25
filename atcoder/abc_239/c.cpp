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

bool solve(std::vector<int64_t> x, std::vector<int64_t> y) {
	auto g = [&](int64_t x, int64_t y) {
		set<II> s;
		for (int64_t i = -2; i <= 2; ++i) {
			for (int64_t j = -2; j <= 2; ++j) {
				if (abs(i * j) == 2) {
					s.insert(II(x + i, y + j));
				}
			}
		}
		return s;
	};
	set<II> a = g(x[0], y[0]), b = g(x[1], y[1]);
	for (auto kv : a) {
		if (b.find(kv) != b.end()) {
			return true;
		}
	}
	return false;
}

int main() {
	std::vector<int64_t> x(2), y(2);
	for (int i = 0; i < 2; i++) {
		std::cin >> x[i] >> y[i];
	}
	cout << (solve(x, y) ? "Yes" : "No") << endl;
	return 0;
}
