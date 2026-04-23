#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int64_t solve(int64_t N, std::vector<std::string> S) {
	vector<int> cnt(26);
	for (const auto &s : S) {
		cnt[s[0] - 'a'] += 1;
	}
	return *(max_element(cnt.begin(), cnt.end()));
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<std::string> S(N);
	for (int64_t i = 0; i < N; ++i) {
		std::cin >> S[i];
	}
	auto ans = solve(N, std::move(S));
	cout << ans << endl;
}
