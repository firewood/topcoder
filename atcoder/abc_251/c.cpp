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

int64_t solve(int64_t N, std::vector<std::string> S, std::vector<int64_t> T) {
	int64_t ans = 0;
	set<string> s;
	for (int i = 0; i < N; ++i) {
		if (s.find(S[i]) == s.end()) {
			s.insert(S[i]);
			if (T[i] > T[ans]) {
				ans = i;
			}
		}
	}
	return ans + 1;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<std::string> S(N);
	std::vector<int64_t> T(N);
	for (int i = 0; i < N; i++) {
		std::cin >> S[i] >> T[i];
	}
	cout << solve(N, S, T) << endl;
	return 0;
}
