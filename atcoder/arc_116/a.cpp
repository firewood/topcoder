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

string solve(long long N) {
	switch (N % 4) {
	case 0:
		return "Even";
	case 2:
		return "Same";
	default:
		return "Odd";
	}
}

string solve2(long long N) {
	LL even = 0, odd = 0;
	for (LL i = 1; i <= N; ++i) {
		if ((N % i) == 0) {
			(((i % 2) == 0) ? even : odd) += 1;
		}
	}
	if (even > odd) {
		return "Even";
	}
	if (odd > even) {
		return "Odd";
	}
	return "Same";
}

int main() {
	long long T, N;
	std::cin >> T;
	for (int i = 0; i < T; i++) {
		std::cin >> N;
		cout << solve(N) << endl;
	}
	return 0;
}
