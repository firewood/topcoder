#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <atcoder/modint>

using namespace std;
const int64_t MOD = 998244353;
using mint = atcoder::modint998244353;

mint solve(string S) {
	mint ans = 0;
	vector<mint> cnt(3);
	for (char c: S) {
		int x = c - 'a';
		mint y = cnt[0] + cnt[1] + cnt[2] - cnt[x] + 1;
		ans += y;
		cnt[x] += y;
	}
	return ans;
}

int main() {
	string S;
	cin >> S;
	auto ans = solve(S);
	cout << ans.val() << endl;
}
