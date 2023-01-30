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

vector<int> solve(int N, int M, std::vector<int> A, std::vector<int> B) {
	vector<int> ans(N);
	vector<vector<int>> f(N, vector<int>(N));
	for (int i = 0; i < M; ++i) {
		f[A[i]][B[i]] = f[B[i]][A[i]] = 1;
	}
	for (int i = 0; i < N; ++i) {
		int cnt = 0;
		for (int j = 0; j < N; ++j) {
			bool ff = false;
			if (i != j && !f[i][j]) {
				for (int k = 0; k < N; ++k) {
					if (i != k && j != k && f[i][k] && f[k][j]) {
						ff = true;
					}
				}
			}
			cnt += ff;
		}
		ans[i] = cnt;
	}
	return ans;
}

int main() {
	int N, M;
	std::cin >> N >> M;
	std::vector<int> A(M), B(M);
	for (int i = 0; i < M; i++) {
		std::cin >> A[i] >> B[i];
		--A[i]; --B[i];
	}
	vector<int> ans = solve(N, M, A, B);
	for (size_t i = 0; i < ans.size(); ++i) {
		cout << ans[i] << endl;
	}
	return 0;
}
