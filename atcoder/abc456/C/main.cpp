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
	set<int> pos;
	for (int64_t i = 1; i < S.length(); ++i) {
		if (S[i - 1] == S[i]) {
			pos.insert(i - 1);
		}
	}
	pos.insert(S.length() - 1);
	for (int64_t i = 0; i < S.length(); ++i) {
		int p = *(pos.lower_bound(i));
		ans += mint(p) - i + 1;
	}
	return ans;
}

int main() {
	string S;
	cin >> S;
	auto ans = solve(S);
	cout << ans.val() << endl;
}
