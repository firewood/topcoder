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
int64_t lcm(int64_t a, int64_t b) { return (a / gcd(a, b)) * b; }

int64_t calc(int64_t N, int64_t x) {
	int64_t c = N / x;
	return (c + 1) * c / 2 * x;
}

int64_t solve(int64_t N, int64_t A, int64_t B) {
	return calc(N, 1) - calc(N, A) - calc(N, B) + calc(N, lcm(A, B));
}

int main() {
	int64_t N, A, B;
	std::cin >> N >> A >> B;
	cout << solve(N, A, B) << endl;
	return 0;
}
