#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

int solve(int N, int M, std::vector<int> &A, std::vector<int> &B, std::vector<char> &C) {
	vector<vector<pair<int, char>>> edges(N);
	for (int i = 0; i < M; i++) {
		edges[A[i]].emplace_back(make_pair(B[i], C[i]));
		edges[B[i]].emplace_back(make_pair(A[i], C[i]));
	}
	vector<pair<int, string>> fq, rq;
	fq.emplace_back(make_pair(0, ""));
	rq.emplace_back(make_pair(N - 1, ""));
	unordered_set<string> prev;
	prev.insert("");
	for (int i = 0; i < N * 2; ++i) {
		vector<pair<int, string>> nfq, nrq;
		unordered_set<string> next_fs, next_rs;
		vector<unordered_set<string>> m(N);
		for (auto kv : fq) {
			if (prev.find(kv.second) == prev.end()) continue;
			for (auto next : edges[kv.first]) {
				string s = kv.second + next.second;
				next_fs.insert(s);
				m[next.first].insert(s);
				nfq.emplace_back(make_pair(next.first, kv.second + next.second));
			}
		}
		for (auto kv : rq) {
			if (prev.find(kv.second) == prev.end()) continue;
			for (auto next : edges[kv.first]) {
				string s = kv.second + next.second;
				if (next_fs.find(s) == next_fs.end()) continue;
				if (m[kv.first].find(s) != m[kv.first].end()) {
					return s.length() * 2 - 1;
				}
				next_rs.insert(s);
				nrq.emplace_back(make_pair(next.first, kv.second + next.second));
				if (m[next.first].find(s) != m[next.first].end()) {
					return s.length() * 2;
				}
			}
		}
		fq = nfq;
		rq = nrq;
		prev = next_rs;
	}
	return -1;
}

int main() {
    int N, M;
	std::cin >> N >> M;
	std::vector<int> A(M), B(M);
	std::vector<char> C(M);
	for (int i = 0; i < M; i++) {
		std::cin >> A[i] >> B[i] >> C[i];
		--A[i], --B[i];
	}
	cout << solve(N, M, A, B, C) << endl;
	return 0;
}
