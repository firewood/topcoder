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

const int INF = 1 << 30;

vector<int> solve(int N, int K) {
	vector<int> ans;
	set<int> s;
	for (int i = 1; i <= N; ++i) {
		s.insert(i);
	}
	for (int i = 1; i <= N; ++i) {
		int j = i + K;
		if (s.find(j) != s.end() && j > N - K) {
			;
		} else {
			j = INF;
			if (abs(*(s.begin()) - i) >= K) {
				j = min(j, *(s.begin()));
			}
			auto it = s.lower_bound(i + K);
			if (it != s.end()) {
				j = min(j, *it);
			}
			if (j >= INF) {
				return {};
			}
		}
		s.erase(j);
		ans.emplace_back(j);
	}
	return ans;
}

int main() {
	int N, K;
	std::cin >> N >> K;
	vector<int> ans = solve(N, K);
	if (!ans.empty()) {
		for (size_t i = 0; i < ans.size(); ++i) {
			if (i) cout << " ";
			cout << ans[i];
		}
		cout << endl;
	} else {
		cout << -1 << endl;
	}
	return 0;
}
