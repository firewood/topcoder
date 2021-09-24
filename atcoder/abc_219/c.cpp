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

vector<string> solve(std::string X, int64_t N, std::vector<std::string> S) {
	char table[256] = {};
	for (int i = 0; i < X.length(); ++i) {
		table[X[i]] = i;
	}
	vector<pair<string, string>> v;
	for (int i = 0; i < N; ++i) {
		string x;
		for (auto c : S[i]) {
			x += char('a' + table[c]);
		}
		v.emplace_back(make_pair(x, S[i]));
	}
	sort(v.begin(), v.end());
	vector<string> ans;
	for (int i = 0; i < N; ++i) {
		ans.emplace_back(v[i].second);
	}
	return ans;
}

int main() {
	std::string X;
	int64_t N;
	std::cin >> X >> N;
	std::vector<std::string> S(N);
	for (int i = 0; i < N; i++) {
		std::cin >> S[i];
	}
	vector<string> ans = solve(X, N, S);
	for (auto s : ans) {
		cout << s << endl;
	}
	return 0;
}
