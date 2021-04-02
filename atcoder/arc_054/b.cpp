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

LD solve(long double P) {
	auto cost = [&](LD t) {
		return t + P / pow(2.0, t / 1.5);
	};
	LD left = 0, right = 100;
	for (int t = 0; t < 100; ++t) {
		if (cost((left * 2 + right) / 3) < cost((left + right * 2) / 3)) {
			right = (left + right * 2) / 3;
		} else {
			left = (left * 2 + right) / 3;
		}
	}
	return cost(left);
}

int main() {
	cout.precision(20);
    long double P;
	std::cin >> P;
	cout << solve(P) << endl;
	return 0;
}
