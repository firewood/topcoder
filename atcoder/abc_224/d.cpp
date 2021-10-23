#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

int64_t solve(int64_t M, std::vector<int64_t> u, std::vector<int64_t> v, std::vector<int64_t> p) {
	const size_t N = 9;
	vector<vector<int>> d(N, vector<int>(N));
	for (int i = 0; i < u.size(); ++i) {
		d[u[i]][v[i]] = 1;
		d[v[i]][u[i]] = 1;
	}
	string st = string(N, '0');
	for (int i = 0; i < p.size(); ++i) {
		st[p[i]] = char('1' + i);
	}
	unordered_map<string, int> m;
	m[st] = 0;
	vector<string> q;
	q.emplace_back(st);
	for (int cost = 1; !q.empty(); ++cost) {
		vector<string> nq;
		for (auto s : q) {
			size_t pos = s.find('0');
			for (int i = 0; i < N; ++i) {
				if (d[pos][i]) {
					string next = s;
					swap(next[pos], next[i]);
					if (m.find(next) == m.end()) {
						m[next] = cost;
						nq.emplace_back(next);
					}
				}
			}
		}
		q = nq;
	}
	const string goal = "123456780";
	return m.find(goal) == m.end() ? -1 : m[goal];
}

int main() {
	int64_t M;
	std::cin >> M;
	std::vector<int64_t> u(M), v(M);
	for (int i = 0; i < M; i++) {
		std::cin >> u[i] >> v[i];
		--u[i];
		--v[i];
	}
	std::vector<int64_t> p(8);
	for (int i = 0; i < 8; i++) {
		std::cin >> p[i];
		--p[i];
	}
	cout << solve(M, u, v, p) << endl;
	return 0;
}
