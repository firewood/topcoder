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

bool solve(int64_t N, int64_t A, int64_t B, int64_t C, int64_t D) {
	bool ans = false;
	if (abs(B - C) >= 2) return false;
	if (B == 0 && C == 0) {
		if (A > 0 && D > 0) return false;
	}
	return true;
}

int main() {
	int64_t N, A, B, C, D;
	std::cin >> N >> A >> B >> C >> D;
	cout << (solve(N, A, B, C, D) ? "Yes" : "No") << endl;
	return 0;
}
