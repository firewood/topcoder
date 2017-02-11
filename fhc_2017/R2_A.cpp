//
// Facebook Hacker Cup 2017 Round 2
// A. Subtle Sabotage
//

/*
Constraints

1 <= T <= 10,000
1 <= N, M, K <= 800,000

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

LL solve(int N, int M, int K) {
	int a = min(N, M), b = max(N, M);
	if (a <= K || b < (K * 2 + 3)) {
		return -1;
	}
	int ans = (a + K - 1) / K;
	if (a >= (K * 2 + 1)) {
		ans = min(ans, 2 + (K + 2 + K - 1) / K);
	}
	return ans;
}

int main(int argc, char *argv[])
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int N, M, K;
		cin >> N >> M >> K;
		LL ans = solve(N, M, K);
		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}
