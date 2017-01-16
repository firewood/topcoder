//
// Facebook Hacker Cup 2017 Round 1
// A. Pie Progress
//

/*
Constraints

1 <= T <= 100
1 <= N, M <= 300
1 <= Ci,j <= 1,000,000

*/

#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <cassert>

using namespace std;

typedef long long LL;
typedef vector<LL> LLVec;

LL solve(int N, int M, vector <LLVec> &C) {
	for (LLVec &c : C) {
		sort(c.begin(), c.end());
	}
	vector<LLVec> dp(N + 1, LLVec(N + 1, 1LL << 60));
	dp[0][0] = 0;
	for (int day = 0; day < N; ++day) {
		int low = day, high = min(N, day * M);
		for (int j = low; j <= high; ++j) {
			dp[day + 1][j] = dp[day][j];
		}
		LL tot = 0;
		for (int i = 0; i < M; ++i) {
			tot += C[day][i];
			for (int j = low; j <= high && (i + j + 1) <= N; ++j) {
				dp[day + 1][i + j + 1] = min(dp[day + 1][i + j + 1], dp[day][j] + tot + (i + 1) * (i + 1));
			}
		}
	}
	return dp[N][N];
}

int main(int argc, char *argv[])
{
#ifdef _DEBUG
	{
		vector <LLVec> C;
		int N = 300, M = 300;
		for (int i = 0; i < N; ++i) {
			LLVec c(M, 1000000);
			C.push_back(c);
		}
		assert(solve(N, M, C) == 1000000 * 300 + 300);
	}
#endif

	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int N, M;
		cin >> N >> M;
		vector <LLVec> C;
		for (int i = 0; i < N; ++i) {
			LLVec c(M);
			for (int j = 0; j < M; ++j) {
				cin >> c[j];
			}
			C.push_back(c);
		}
		LL ans = solve(N, M, C);
		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}
