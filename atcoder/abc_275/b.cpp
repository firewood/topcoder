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

using mint = atcoder::modint998244353;

mint solve(int64_t A, int64_t B, int64_t C, int64_t D, int64_t E, int64_t F) {
	return mint(A) * B * C - mint(D) * E * F;
}

int main() {
	int64_t A, B, C, D, E, F;
	std::cin >> A >> B >> C >> D >> E >> F;
	cout << solve(A, B, C, D, E, F).val() << endl;
	return 0;
}
