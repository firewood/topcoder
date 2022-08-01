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

int64_t solve(int64_t N, int64_t A, int64_t B) {
	if (N < A) {
		return 0;
	}
	if (A <= B) {
		return N - (A - 1);
	}
	int64_t c = N / A;
	return c + (B - 1) * (c - 1) + min(N - c * A, B - 1);
}

int main() {
	int64_t N, A, B;
	std::cin >> N >> A >> B;
	cout << solve(N, A, B) << endl;
	return 0;
}
