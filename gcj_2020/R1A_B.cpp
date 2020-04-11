// Google Code Jam 2020 Round 1A
// Problem B.

#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> II;
typedef unordered_map<int, vector<II>> Q;

vector<II> solve(int n) {
	if (n <= 1 || n > 1000) {
		return { {0,0} };
	}
	const size_t M = 100;
	vector<vector<int>> p(M);
	vector<Q> prev_rq(1);
	p[0] = { 1 };
	prev_rq[0][1].push_back(II(0, 0));
	for (int i = 1; i < M; ++i) {
		vector<int>& prev = p[i - 1];
		vector<int>& curr = p[i];
		curr.resize(i + 1);
		for (int j = 0; j <= i; ++j) {
			int a = j > 0 ? prev[j - 1] : 0;
			int b = j < i ? prev[j] : 0;
			if (a < 0 || b < 0 || a + b > 1e9) {
				a = 0, b = -1;
			}
			curr[j] = a + b;
		}
		vector<Q> next_rq(i + 1);
		vector<Q> rrq(i + 1);
		for (int j = 0; j <= i; ++j) {
			if (curr[j] < 0) continue;
			Q& q = next_rq[j];
			if (j > 0) {
				for (auto kv : prev_rq[j - 1]) {
					vector<II> v = kv.second;
					v.emplace_back(II(i, j));
					q[curr[j] + kv.first] = v;
				}
				for (auto kv : next_rq[j - 1]) {
					if (q.find(curr[j] + kv.first) == q.end() || kv.second.size() + 1 < q[curr[j] + kv.first].size()) {
						vector<II> v = kv.second;
						v.emplace_back(II(i, j));
						q[curr[j] + kv.first] = v;
					}
				}
			}
			if (j < i) {
				for (auto kv : prev_rq[j]) {
					if (q.find(curr[j] + kv.first) == q.end() || kv.second.size() + 1 < q[curr[j] + kv.first].size()) {
						vector<II> v = kv.second;
						v.emplace_back(II(i, j));
						q[curr[j] + kv.first] = v;
					}
				}
			}
		}
/*
		for (int j = i; j >= 0; --j) {
			if (curr[j] < 0) continue;
			Q& q = rrq[j];
			if (j > 0) {
				for (auto kv : prev_rq[j - 1]) {
					vector<II> v = kv.second;
					v.emplace_back(II(i, j));
					q[curr[j] + kv.first] = v;
				}
			}
			if (j < i) {
				for (auto kv : prev_rq[j]) {
					if (q.find(curr[j] + kv.first) == q.end() || kv.second.size() + 1 < q[curr[j] + kv.first].size()) {
						vector<II> v = kv.second;
						v.emplace_back(II(i, j));
						q[curr[j] + kv.first] = v;
					}
				}
				for (auto kv : rrq[j + 1]) {
					if (q.find(curr[j] + kv.first) == q.end() || kv.second.size() + 1 < q[curr[j] + kv.first].size()) {
						vector<II> v = kv.second;
						v.emplace_back(II(i, j));
						q[curr[j] + kv.first] = v;
					}
				}
			}
			for (auto kv : q) {
				if (next_rq[j].find(kv.first) == next_rq[j].end() || kv.second.size() < next_rq[j][kv.first].size()) {
					next_rq[j][kv.first] = kv.second;
				}
			}
		}
*/
		for (int j = 0; j <= i; ++j) {
			Q& q = next_rq[j];
			if (q.find(n) != q.end()) {
				return q[n];
			}
		}
		prev_rq = next_rq;
	}
	return {};
}

int main(int argc, char* argv[]) {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int n;
		cin >> n;
		vector<II> ans = solve(n);
		cout << "Case #" << t << ":" << endl;
		for (auto kv : ans) {
			cout << (kv.first + 1) << " " << (kv.second + 1) << endl;
		}
	}
	return 0;
}
