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

static const LL INF = 1LL << 60;

LL solve(std::string S) {
	LL ans = 0;
	vector<LL> cnt(26);
	int prev = -1;
	for (LL i = S.length() - 1; i >= 0; --i) {
		int c = S[i] - 'a';
		if (prev == c) {
			LL sum = accumulate(cnt.begin(), cnt.end(), 0LL);
			ans += sum - cnt[c];
			cnt = vector<LL>(26);
			cnt[c] = sum;
		}
		cnt[c] += 1;
		prev = c;
	}
	return ans;
}

int main() {
	std::string S;
	std::cin >> S;
	cout << solve(S) << endl;
	return 0;
}
