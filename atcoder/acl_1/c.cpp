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
#include <atcoder/mincostflow>

using namespace std;

int64_t solve(int64_t N, int64_t M, std::vector<std::string> S) {
	atcoder::mcf_graph<int, int64_t> g(N * M + 2);
	for (int i = 0; i < N; ++i) {
		for (int j = 1; j < M; ++j) {
			if (S[i][j - 1] != '#' && S[i][j] != '#') {
				g.add_edge(i * M + j - 1, i * M + j, 5000, 0);
			}
		}
	}
	for (int i = 1; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (S[i - 1][j] != '#' && S[i][j] != '#') {
				g.add_edge((i - 1) * M + j, i * M + j, 5000, 0);
			}
		}
	}

	int64_t tokens = 0, p = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (S[i][j] == '#') continue;
			if (S[i][j] == 'o') {
				++tokens;
				p += i + j;
				g.add_edge(N * M, i * M + j, 1, 0);
			}
			g.add_edge(i * M + j, N * M + 1, 1, 10000 - i - j);
		}
	}
	auto result = g.flow(N * M, N * M + 1, 5000);
	return tokens * 10000 - result.second - p;
}

int main() {
	int64_t N, M;
	std::cin >> N >> M;
	std::vector<std::string> S(N);
	for (int i = 0; i < N; i++) {
		std::cin >> S[i];
	}
	cout << solve(N, M, S) << endl;
	return 0;
}
