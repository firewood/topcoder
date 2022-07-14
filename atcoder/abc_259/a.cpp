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

int64_t solve(int64_t N, int64_t M, int64_t X, int64_t T, int64_t D) {
	return T - max(int64_t(0), X - M) * D;
}

int main() {
	int64_t N, M, X, T, D;
	std::cin >> N >> M >> X >> T >> D;
	cout << solve(N, M, X, T, D) << endl;
	return 0;
}
