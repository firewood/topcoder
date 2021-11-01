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

bool solve(int N, int M, vector<vector<int>> b) {
	for (int i = 0; i < N; ++i) {
		for (int j = 1; j < M; ++j) {
			int p = b[i][j - 1], q = b[i][j];
			if (p / 7 != q / 7 || p + 1 != q) {
				return false;
			}
		}
		if (i > 0 && b[i - 1][0] + 7 != b[i][0]) {
			return false;
		}
	}
	return true;
}

int main() {
	int64_t N, M;
	cin >> N >> M;
	vector<vector<int>> b(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> b[i][j];
			b[i][j] -= 1;
		}
	}
	bool ans = solve(N, M, b);
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}
