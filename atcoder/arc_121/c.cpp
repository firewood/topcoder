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

vector<int> solve(int N, vector<int> p) {
	vector<int> ans;
	auto operate = [&](int op) {
		swap(p[op], p[op + 1]);
		ans.emplace_back(op + 1);
	};
	int t = 0;
	if (N <= 2) {
		if (p[0] != 0) {
			operate(0);
		}
	} else {
		for (int i = N - 1; i >= 3; --i) {
			int pos = find(p.begin(), p.end(), i) - p.begin();
			if (pos == i) continue;
			if (t % 2 != pos % 2) {
				if (pos == 2) {
					operate(1);
					operate(2);
					operate(1);
					t += 3;
				} else {
					operate(pos > 2 ? (t % 2) : (pos + 1));
					++t;
				}
			}
			while (pos < i) {
				operate(pos);
				++t;
				++pos;
			}
		}
		while (p[0] != 0 || p[1] != 1) {
			operate(t % 2);
			++t;
		}
	}
/*
	for (int i = 0; i < p.size(); ++i) {
		if (i) cerr << " ";
		cerr << p[i];
	}
	cerr << endl;
*/
	return ans;
}

int main() {
/*
	const int n = 7;
	vector<int> seq(n);
	iota(seq.begin(), seq.end(), 0);
	do {
		vector<int> ans = solve(n, seq);
	} while (next_permutation(seq.begin(), seq.end()));
*/
	int T, N;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		cin >> N;
		vector<int> p(N);
		for (int i = 0; i < N; ++i) {
			cin >> p[i];
			--p[i];
		}
		vector<int> ans = solve(N, p);
		cout << ans.size() << endl;
		if (!ans.empty()) {
			for (int i = 0; i < ans.size(); ++i) {
				if (i) cout << " ";
				cout << ans[i];
			}
			cout << endl;
		}
	}
	return 0;
}
