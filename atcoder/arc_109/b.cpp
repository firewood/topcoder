#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>

using namespace std;

typedef long long LL;

LL solve(long long n) {
	LL x = sqrt(n * 2) - 1;
	while ((((x + 1) * (x + 2)) / 2 - 1) <= n) {
		++x;
	}
	return n - x + 1;
}

int main() {
    long long n;
	std::cin >> n;
	cout << solve(n) << endl;
	return 0;
}
