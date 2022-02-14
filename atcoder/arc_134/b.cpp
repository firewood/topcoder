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

string solve(int64_t N, std::string s) {
	string ans = s;
	vector<vector<int>> p(26);
	for (int i = 0; i < 26; ++i) {
		p[i].emplace_back(-1);
	}
	for (int i = 0; i < N; ++i) {
		p[s[i] - 'a'].emplace_back(i);
	}
	for (int i = 0; i < 26; ++i) {
		p[i].emplace_back(N + 1);
	}
	int right = N;
	for (int i = 0; i < right; ++i) {
		int c = s[i] - 'a';
		bool done = false;
		for (int j = 0; j < c; ++j) {
			int k = lower_bound(p[j].begin(), p[j].end(), right) - p[j].begin();
			int l = p[j][k - 1];
			if (l > i) {
				done = true;
				swap(ans[i], ans[l]);
				right = l;
				break;
			}
		}
	}
	return ans;
}

int main() {
	int64_t N;
	std::string s;
	std::cin >> N >> s;
	cout << solve(N, s) << endl;
	return 0;
}
