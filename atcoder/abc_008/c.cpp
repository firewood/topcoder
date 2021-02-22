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
typedef long double LD;

LD solve(long long N, std::vector<long long> &C) {
	LD ans = 0;
	for (int i = 0; i < N; i++) {
		int c = 0;
		for (int j = 0; j < N; ++j) {
			c += (C[i] % C[j]) == 0;
		}
		if (c % 2) {
			ans += (c + 1.0) / c / 2.0;
		} else {
			ans += 0.5;
		}
	}
	return ans;
}

int main() {
	cout.precision(20);
    long long N;
	std::cin >> N;
	std::vector<long long> C(N);
	for (int i = 0; i < N; i++) {
		std::cin >> C[i];
	}
	cout << solve(N, C) << endl;
	return 0;
}
