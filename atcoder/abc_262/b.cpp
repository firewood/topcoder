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

int solve(int N, int M, std::vector<int> U, std::vector<int> V) {
	int ans = 0;
	vector<vector<int>> edge(N, vector<int>(N));
	for (int i = 0; i < M; ++i) {
		edge[U[i]][V[i]] = edge[V[i]][U[i]] = 1;
	}
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			for (int k = j + 1; k < N; ++k) {
				ans += edge[i][j] & edge[j][k] & edge[k][i];
			}
		}
	}
	return ans;
}

int main() {
	int N, M;
	std::cin >> N >> M;
	std::vector<int> U(M), V(M);
	for (int i = 0; i < M; i++) {
		std::cin >> U[i] >> V[i];
		--U[i];
		--V[i];
	}
	cout << solve(N, M, U, V) << endl;
	return 0;
}
