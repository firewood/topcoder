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

LL solve(long long N, long long M) {
	LL x = 10, y = 1, m2 = M * M;
	for (LL i = 0, b = 1; i < 60; ++i, b *= 2) {
		if (N & b) {
			y = (y * x) % m2;
		}
		x = (x * x) % m2;
	}
	return y / M;
}

int main() {
    long long N;
	std::cin >> N;
	long long M;
	std::cin >> M;
	cout << solve(N, M) << endl;
	return 0;
}
