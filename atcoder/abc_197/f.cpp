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

typedef pair<int, int> II;

int solve(int N, int M, std::vector<int>& A, std::vector<int>& B, std::vector<char>& C) {
	vector<vector<pair<int, char>>> edges(N);
	for (int i = 0; i < M; i++) {
		edges[A[i]].emplace_back(make_pair(B[i], C[i]));
		edges[B[i]].emplace_back(make_pair(A[i], C[i]));
	}
	vector<vector<int>> visited(N, vector<int>(N));
	vector<II> q;
	q.emplace_back(II(0, N - 1));
	int ans = 1 << 30;
	for (int c = 2; !q.empty(); c += 2) {
		vector<II> nq;
		for (auto f : q) {
			int f_from = f.first;
			int r_from = f.second;
			for (auto fe : edges[f_from]) {
				int f_to = fe.first;
				int f_color = fe.second;
				if (f_to == r_from) {
					ans = min(ans, c - 1);
				}
				for (auto re : edges[r_from]) {
					int r_to = re.first;
					int r_color = re.second;
//					if (f_from == r_to) {
//						ans = min(ans, c - 1);
//					}
					if (f_color != r_color) continue;
					if (f_to == r_to) {
						ans = min(ans, c);
					}
					II key(f_to, r_to);
					if (!visited[f_to][r_to]) {
						visited[f_to][r_to] = 1;
						nq.emplace_back(II(f_to, r_to));
					}
				}
			}
		}
		if (ans < 1 << 30) return ans;
		q = nq;
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
