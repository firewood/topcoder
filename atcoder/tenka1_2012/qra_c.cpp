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

int solve(int N, int M, std::vector<int> a, std::vector<int> b, std::string s) {
	int ans = 0;
	vector<int> f;
	while (!s.empty()) {
		int b = s.back() == 'w';
		while (s.back() == 'w') {
			s = s.substr(0, s.length() - 1);
		}
		f.emplace_back(b);
		if (s.back() == '\"') {
			s = s.substr(1, s.length() - 2);
		} else {
			break;
		}
	}
	reverse(f.begin(), f.end());

	vector<vector<int>> edges(N);
	for (int i = 0; i < M; ++i) {
		edges[b[i]].emplace_back(a[i]);
	}

	vector<int> q;
	q.emplace_back(stoi(s.substr(5)) - 1);
	for (auto x : f) {
		vector<int> cnt(N), nq;
		for (auto y : q) {
			for (auto next : edges[y]) {
				cnt[next] += 1;
			}
		}
		for (int i = 0; i < N; ++i) {
			if (x) {
				if (cnt[i]) {
					nq.emplace_back(i);
				}
			} else {
				if (cnt[i] < q.size()) {
					nq.emplace_back(i);
				}
			}
		}
		q = nq;
	}
	return q.size();
}

int main() {
	int N, M;
	std::string s;
	std::cin >> N >> M;
	std::vector<int> a(M), b(M);
	for (int i = 0; i < M; i++) {
		std::cin >> a[i] >> b[i];
		--a[i]; --b[i];
	}
	std::cin >> s;
	cout << solve(N, M, a, b, s) << endl;
	return 0;
}
