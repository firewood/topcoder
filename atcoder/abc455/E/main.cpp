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

using namespace std;

typedef pair<int64_t, int64_t> II;

int64_t solve(int64_t N, std::string S) {
	int64_t ans = N * (N + 1) / 2;
	map<int64_t, int64_t> mab, mbc, mca;
	map<II, int64_t> mabc;
	int64_t ab = 0, bc = 0, ca = 0;
	for (int64_t i = 0; i < N; ++i) {
		mab[ab] += 1;
		mbc[bc] += 1;
		mca[ca] += 1;
		mabc[II(ab, bc)] += 2;
		if (S[i] == 'A') {
			++ab;
			--ca;
		}
		if (S[i] == 'B') {
			--ab;
			++bc;
		}
		if (S[i] == 'C') {
			--bc;
			++ca;
		}
		ans -= mab[ab];
		ans -= mbc[bc];
		ans -= mca[ca];
		ans += mabc[II(ab, bc)];
	}
	return ans;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::string S;
	std::cin >> S;
	auto ans = solve(N, S);
	cout << ans << endl;
}
