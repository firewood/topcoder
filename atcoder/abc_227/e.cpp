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

static const string key = "KEY";
static map<pair<string, int64_t>, int64_t> memo;

int64_t dfs(const string &s, int k) {
	if (k < 0) return 0;
	if (s.empty()) return 1;
	auto it = memo.find({ s, k });
	if (it != memo.end()) return it->second;
	int64_t cnt = 0;
	for (auto c : key) {
		int pos = s.find(c);
		if (pos >= 0) {
			cnt += dfs(s.substr(0, pos) + s.substr(pos + 1), k - pos);
		}
	}
	memo[{ s, k }] = cnt;
	return cnt;
}

int64_t solve(std::string S, int K) {
	return dfs(S, K);
}

int main() {
	std::string S;
	int K;
	std::cin >> S >> K;
	cout << solve(S, K) << endl;
	return 0;
}
