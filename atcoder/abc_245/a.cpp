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

bool solve(int64_t A, int64_t B, int64_t C, int64_t D) {
	return A < C || (A == C && B <= D);
}

int main() {
	int64_t A, B, C, D;
	std::cin >> A >> B >> C >> D;
	cout << (solve(A, B, C, D) ? "Takahashi" : "Aoki") << endl;
	return 0;
}
