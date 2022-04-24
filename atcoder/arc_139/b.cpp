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

int64_t solve(int64_t N, int64_t B, int64_t C, int64_t X, int64_t Y, int64_t Z) {
	int64_t ans = N * X;
	if (Y * C < Z * B) {
		swap(B, C);
		swap(Y, Z);
	}
	for (int64_t b = 0; b < 100000; ++b) {
		int64_t r = N - b * B;
		if (r < 0) break;
		ans = min(ans, r * X + b * Y);
		int64_t c = r / C;
		ans = min(ans, (r - c * C) * X + b * Y + c * Z);
	}
	return ans;
}

int main() {
	int64_t T, N, A, B, X, Y, Z;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		cin >> N >> A >> B >> X >> Y >> Z;
		cout << solve(N, A, B, X, Y, Z) << endl;
	}
	return 0;
}
