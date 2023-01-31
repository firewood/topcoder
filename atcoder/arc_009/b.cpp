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

vector<string> solve(std::vector<int64_t> b, int64_t N, std::vector<string> a) {
	vector<int> rev(10);
	for (int i = 0; i < 10; ++i) {
		rev[b[i]] = i;
	}
	vector<pair<int, int>> v;
	for (int i = 0; i < N; ++i) {
		int n = 0;
		for (char c : a[i]) {
			n = n * 10 + rev[c - '0'];
		}
		v.emplace_back(n, i);
	}
	sort(v.begin(), v.end());
	vector<string> ans(N);
	for (int i = 0; i < N; ++i) {
		ans[i] = a[v[i].second];
	}
	return ans;
}

int main() {
	int64_t N;
	std::vector<int64_t> b(10);
	for (int i = 0; i < 10; i++) {
		std::cin >> b[i];
	}
	std::cin >> N;
	std::vector<string> a(N);
	for (int i = 0; i < N; i++) {
		std::cin >> a[i];
	}
	vector<string> ans = solve(b, N, a);
	for (size_t i = 0; i < ans.size(); ++i) {
		cout << ans[i] << endl;
	}
	return 0;
}
