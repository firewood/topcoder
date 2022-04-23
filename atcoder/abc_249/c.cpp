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

int solve(int N, int K, std::vector<std::string> S) {
	int ans = 0;
	for (int b = 1; b < (1 << N); ++b) {
		vector<int> cnt(26);
		for (int i = 0; i < N; ++i) {
			if (b & (1 << i)) {
				for (auto c : S[i]) {
					cnt[c - 'a'] += 1;
				}
			}
		}
		ans = max(ans, int(count(cnt.begin(), cnt.end(), K)));
	}
	return ans;
}

int main() {
	int N, K;
	std::cin >> N >> K;
	std::vector<std::string> S(N);
	for (int i = 0; i < N; i++) {
		std::cin >> S[i];
	}
	cout << solve(N, K, S) << endl;
	return 0;
}
