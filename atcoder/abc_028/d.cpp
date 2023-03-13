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

typedef long double LD;

LD solve(LD N, LD K) {
	return ((N - K) * (K - 1) * 6 + (N - 1) * 3 + 1) / (N * N * N);
}

int main() {
	cout.precision(20);
	int64_t N, K;
	std::cin >> N >> K;
	cout << solve(N, K) << endl;
	return 0;
}
