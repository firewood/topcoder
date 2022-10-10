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

vector<vector<int>> solve(int N, int M) {
	vector<vector<int>> ans(N, vector<int>(N, -1));
	vector<II> mv, q;
	for (int i = -N; i <= N; ++i) {
		for (int j = -N; j <= N; ++j) {
			if (i * i + j * j == M) {
				mv.emplace_back(II(i, j));
			}
		}
	}
	ans[0][0] = 0;
	q.emplace_back(II(0, 0));
	for (int cnt = 1; !q.empty(); ++cnt) {
		vector<II> nq;
		for (const auto kv : q) {
			int y = kv.first, x = kv.second;
			for (auto z : mv) {
				int ny = y + z.first, nx = x + z.second;
				if (ny >= 0 && ny < N && nx >= 0 && nx < N && ans[ny][nx] < 0) {
					ans[ny][nx] = cnt;
					nq.emplace_back(II(ny, nx));
				}
			}
		}
		q = nq;
	}
	return ans;
}

int main() {
	int N, M;
	std::cin >> N >> M;
	vector<vector<int>> ans = solve(N, M);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (j)cout << " ";
			cout << ans[i][j];
		}
		cout << endl;
	}
	return 0;
}
