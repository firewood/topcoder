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

int64_t solve(std::vector<int64_t> A) {
	int64_t ans = 0, a = A[0], b = A[1], c = A[2], d = 2 * b - a - c;
	if (d < 0) {
		d = -d / 2 + (-d % 2) * 2;
	}
	ans += d;
	return ans;
}

int main() {
#if DEBUG || _DEBUG
	freopen("in.txt", "r", stdin);
//	freopen("in_1.txt", "r", stdin);
#endif
	std::vector<int64_t> A(3);
	for (int i = 0; i < 3; i++) {
		std::cin >> A[i];
	}
	cout << solve(std::move(A)) << endl;
	return 0;
}
