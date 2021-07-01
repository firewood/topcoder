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

int64_t gcd(int64_t a, int64_t b) { return b ? gcd(b, a % b) : a; }

int64_t solve(int64_t A, int64_t B, int64_t C) {
    int64_t g = gcd(A, gcd(B, C));
    return A / g + B / g + C / g - 3;
}

int main() {
	int64_t A, B, C;
	std::cin >> A >> B >> C;
	cout << solve(A, B, C) << endl;
	return 0;
}
