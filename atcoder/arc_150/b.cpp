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

static const int64_t INF = 1LL << 60;

int64_t solve(int64_t A, int64_t B) {
	int64_t ans = INF;
	if (B <= A) {
		ans = A - B;
	} else if ((B % A) == 0) {
		ans = 0;
	} else {
		auto update = [&](int64_t c) {
			if (c >= A) {
				ans = min(ans, c - A + (B + c - 1) / c * c - B);
			}
		};
		update(A);
		int64_t cc = B / A, low = cc - min(A, int64_t(100000));
		for (int64_t c = max(int64_t(1), low); c <= cc + 100; ++c) {
			update((B + ((c - 1) % A)) / c);
		}
		for (int64_t c = A; c <= min(A * 2, A + 100000); ++c) {
			update(c);
		}
	}
	return ans;
}

int main() {
	int64_t T, A, B;
	cin >> T;
	for (int tt = 0; tt < T; ++tt) {
		cin >> A >> B;
		cout << solve(A, B) << endl;
	}
	return 0;
}
