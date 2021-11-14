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

int64_t solve(int64_t N, std::vector<int64_t> S) {
	int64_t ans = 0;
	auto possible = [](int64_t s) {
		for (int64_t a = 1; a * 4 <= s; ++a) {
			for (int64_t b = 1; b * 4 <= s; ++b) {
				if (s == 4 * a * b + 3 * a + 3 * b) {
					return true;
				}
			}
		}
		return false;
	};
	for (auto s : S) {
		if (!possible(s)) {
			++ans;
		}
	}
	return ans;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> S(N);
	for (int i = 0; i < N; i++) {
		std::cin >> S[i];
	}
	cout << solve(N, S) << endl;
	return 0;
}
