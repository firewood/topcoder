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

static const int INF = 1 << 30;

int main() {
	int N;
	cin >> N;
	vector<int> A(N), B(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i] >> B[i];
	}

	int sum = accumulate(B.begin(), B.end(), 0), ans = INF;
	if ((sum % 3) == 0) {
		vector<vector<int>> dp(502, vector<int>(502, INF));
		dp[0][0] = 0;
		for (int i = 0; i < N; i++) {
			vector<vector<int>> next(502, vector<int>(502, INF));
			for (int a = 0; a <= 500; ++a) {
				for (int b = 0; b <= 500; ++b) {
					if (dp[a][b] >= INF) continue;
					if (a + B[i] <= 500) {
						next[a + B[i]][b] = min(next[a + B[i]][b], dp[a][b] + (A[i] != 1));
					}
					if (b + B[i] <= 500) {
						next[a][b + B[i]] = min(next[a][b + B[i]], dp[a][b] + (A[i] != 2));
					}
					next[a][b] = min(next[a][b], dp[a][b] + (A[i] != 3));
				}
			}
			dp = next;
		}
		ans = dp[sum / 3][sum / 3];
	}

	cout << (ans < INF ? ans : -1) << endl;
	return 0;
}
