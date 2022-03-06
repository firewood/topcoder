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

LD solve(int64_t A, int64_t B, int64_t C, int64_t X) {
	if (X <= A) {
		return 1.0;
	}
	if (X > B) {
		return 0;
	}
	return LD(C) / LD(B - A);
}

int main() {
	cout.precision(20);
	int64_t A, B, C, X;
	std::cin >> A >> B >> C >> X;
	cout << solve(A, B, C, X) << endl;
	return 0;
}
