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

const int64_t INF = 1LL << 60;

int64_t solve2(int64_t a, int64_t b, int64_t c) {
	int64_t d = c - b;
	if (d >= 0 && (d % 3) == 0) {
		return b + d;
	}
	return INF;
}

int64_t solve1(int64_t A, int64_t B, int64_t C) {
	int64_t ans = INF;
	vector<int64_t> seq = { A, B, C };
	sort(seq.begin(), seq.end());
	do {
		ans = min(ans, solve2(seq[0], seq[1], seq[2]));
	} while (next_permutation(seq.begin(), seq.end()));
	return ans;
}

int main() {
	int64_t T, R, G, B;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		cin >> R >> G >> B;
		int64_t ans = solve1(R, G, B);
		cout << (ans < INF ? ans : -1) << endl;
	}
	return 0;
}
