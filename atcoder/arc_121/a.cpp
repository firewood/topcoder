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

typedef long long LL;

LL solve(LL N, vector <LL> &X, vector <LL> &Y) {
	set<int> s;
	auto build = [&](const vector<LL>& v) {
		vector<int> seq(N);
		iota(seq.begin(), seq.end(), 0);
		sort(seq.begin(), seq.end(), [&](int lhs, int rhs) {
			return v[lhs] < v[rhs];
		});
		s.insert(seq[0]);
		s.insert(seq[1]);
		s.insert(seq[N - 2]);
		s.insert(seq[N - 1]);
	};
	build(X);
	build(Y);
	vector<LL> ans;
	for (auto a : s) {
		for (auto b : s) {
			if (a < b) {
				ans.emplace_back(max(abs(X[a] - X[b]), abs(Y[a] - Y[b])));
			}
		}
	}
	sort(ans.rbegin(), ans.rend());
	return ans[1];
}

int main() {
	LL N;
	cin >> N;
	std::vector<long long> X(N), Y(N);
	for (int i = 0; i < N; i++) {
		std::cin >> X[i] >> Y[i];
	}
	cout << solve(N, X, Y) << endl;
	return 0;
}
