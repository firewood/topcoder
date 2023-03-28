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

int64_t solve(int64_t A) {
	for (int64_t i = 1; i <= 10000; ++i) {
		int64_t a = 0;
		for (auto c : to_string(i)) {
			int d = c - '0';
			if (d >= i) {
				a = -1;
				break;
			}
			a = (a * i) + d;
			if (a > A) break;
		}
		if (a == A) {
			return i;
		}
	}
	return -1;
}

int main() {
	int64_t A;
	std::cin >> A;
	cout << solve(A) << endl;
	return 0;
}
