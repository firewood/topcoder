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

typedef long long LL;

LL solve(long long N, long long K, std::vector<long long> &s) {
	LL ans = 0, cnt = 0, prod = 1;
	for (int i = 0; i < N; i++) {
		++cnt;
		prod *= s[i];
		while (prod > K && cnt > 0) {
			prod /= s[i - --cnt];
		}
		ans = max(ans, cnt);
		if (prod == 0) {
			return N;
		}
	}
	return ans;
}

int main() {
#if DEBUG
	freopen("in_1.txt", "r", stdin);
#endif
    long long N, K;
	std::cin >> N >> K;
	std::vector<long long> s(N);
	for (int i = 0; i < N; i++) {
		std::cin >> s[i];
	}
	cout << solve(N, K, s) << endl;
	return 0;
}
