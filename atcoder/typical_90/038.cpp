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

string solve(int64_t A, int64_t B) {
	int64_t g = gcd(A, B);
	B /= g;
	int64_t ans = A * B;
	if (ans < A || ans < B || ans / B != A || ans > 1000000000000000000LL) {
		return "Large";
	}
	return to_string(ans);
}

int main() {
	int64_t A, B;
	std::cin >> A >> B;
	cout << solve(A, B) << endl;
	return 0;
}
