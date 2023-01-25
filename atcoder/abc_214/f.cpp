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
#include <atcoder/modint>

using namespace std;

using mint = atcoder::modint1000000007;

mint solve(std::string S) {
	int N = int(S.length());
	mint ans = 0;
	vector<mint> sum(N + 3);
	sum[0] = 0;
	sum[1] = 1;
	sum[2] = 1;
	vector<int> lastPos(256, -1);
	for (int i = 0; i < N; ++i) {
		sum[i + 3] = sum[i + 2] + sum[i + 1] - sum[lastPos[S[i]] + 1];
		lastPos[S[i]] = i;
	}
	return sum[N + 2] - 1;
}

int main() {
	std::string S;
	std::cin >> S;
	cout << solve(S).val() << endl;
	return 0;
}
