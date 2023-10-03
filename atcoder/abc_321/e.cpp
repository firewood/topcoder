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

int main() {
	int64_t T;
	cin >> T;
	for (int tt = 0; tt < T; ++tt) {
		int64_t N, X, K, ans = 0, prev_x = -1;
		cin >> N >> X >> K;

		for (int64_t up = 0; up <= K; ++up) {
			int64_t left = X, right = X;
			for (int64_t i = up; i < K; ++i) {
				left *= 2;
				right = right * 2 + 1;
				if (left == prev_x) {
					++left;
				}
				if (right == prev_x) {
					--right;
				}
				if (left > N) {
					break;
				}
			}

			if (left <= N) {
				ans += max(int64_t(0), min(N, right) - left + 1);
			}

			prev_x = X;
			X /= 2;
			if (X <= 0) break;
		}

		cout << ans << endl;
	}
	return 0;
}
