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

vector<int64_t> solve(int64_t N, std::vector<int64_t> a) {
	vector<int64_t> ans;
	int64_t cnt = 0;
	vector<II> q;
	for (auto x : a) {
		if (q.empty() || q.back().first != x) {
			q.emplace_back(II(x, 0));
		}
		cnt += 1;
		q.back().second += 1;
		if (q.back().first == q.back().second) {
			cnt -= x;
			q.pop_back();
		}
		ans.emplace_back(cnt);
	}
	return ans;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> a(N);
	for (int i = 0; i < N; i++) {
		std::cin >> a[i];
	}
	vector<int64_t> ans = solve(N, a);
	for (size_t i = 0; i < ans.size(); ++i) {
		cout << ans[i] << endl;
	}
	return 0;
}
