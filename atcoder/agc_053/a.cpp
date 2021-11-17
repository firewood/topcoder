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

typedef pair<int, int> II;

void solve(long long N, std::string S, std::vector<int>& A) {
	vector<int> left(N + 1, 0), right(N + 1, 0), m(N + 1);
	for (int i = 0; i < N; ++i) {
		if (S[i] == '<') {
			left[i + 1] = left[i] + 1;
		}
	}
	for (int i = N - 1; i >= 0; --i) {
		if (S[i] == '>') {
			right[i] = right[i + 1] + 1;
		}
	}
	for (int i = 0; i <= N; ++i) {
		m[i] = max(left[i], right[i]);
	}

	vector<vector<int>> ans;
	ans.emplace_back(A);

	int ll = 1, rr = 10001;
	auto build = [&](int div) -> vector<vector<int>> {
		vector<vector<int>> res(div, vector<int>(N + 1));
		priority_queue<II> q;
		for (int i = 0; i <= N; ++i) {
			q.emplace(II(m[i], i));
		}
		while (!q.empty()) {
			II top = q.top();
			q.pop();
			int i = top.second;
			bool lg = i > 0 && S[i - 1] == '>';
			bool rg = i < N && S[i] == '<';
			int r = A[i];
			for (int j = 0; j < div; ++j) {
				res[j][i] = A[i] / div;
				r -= A[i] / div;
			}
			if (r > 0) {
				for (int j = 0; r > 0 && j < div; ++j) {
					int mx = 1 << 30;
					if (lg) {
						mx = min(mx, res[j][i - 1] - 1);
					}
					if (rg) {
						mx = min(mx, res[j][i + 1] - 1);
					}
					int rd = min(1, mx - res[j][i]);
					res[j][i] += rd;
					r -= rd;
				}
				if (r > 0) {
					return {};
				}
			}
			for (int j = 0; j < div; ++j) {
				if (lg && res[j][i - 1] <= res[j][i]) {
					return {};
				}
				if (rg && res[j][i] >= res[j][i + 1]) {
					return {};
				}
			}
		}
		return res;
	};
	while (rr - ll > 1) {
		int mid = (ll + rr) / 2;
		vector<vector<int>> res = build(mid);
		if (!res.empty()) {
			ll = mid;
		} else {
			rr = mid;
		}
	}

	if (ll > 1) {
		ans = build(ll);
	}

	cout << ans.size() << endl;
	for (auto a : ans) {
		for (int i = 0; i <= N; ++i) {
			if (i) cout << " ";
			cout << a[i];
		}
		cout << endl;
	}
}

int main() {
	long long N;
	std::string S;
	std::cin >> N >> S;
	std::vector<int> A(N + 1);
	for (int i = 0; i < N + 1; i++) {
		std::cin >> A[i];
	}
	solve(N, S, A);
	return 0;
}
