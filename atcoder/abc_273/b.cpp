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

int64_t solve(int64_t X, int64_t K) {
	int64_t b = 1;
	for (int i = 0; i < K; ++i) {
		X = (X / b + 5) / 10 * 10 * b;
		b *= 10;
	}
	return X;
}

int main() {
	int64_t X, K;
	std::cin >> X >> K;
	cout << solve(X, K) << endl;
	return 0;
}
