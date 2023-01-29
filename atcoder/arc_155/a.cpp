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

bool solve(int64_t N, int64_t K, string s) {
	for (int len = N / 2; len >= 1; --len) {
		int k = N / len;
		if (k * len != N) continue;
		if ((k % 2) == 1) {
			string f = s.substr(0, len);
			string r = f;
			reverse(r.begin(), r.end());
			bool ok = true;
			for (int i = 1; i < k; ++i) {
				if (i % 2) {
					if (s.substr(i * len, len) != r) {
						ok = false;
						break;
					}
				} else {
					if (s.substr(i * len, len) != f) {
						ok = false;
						break;
					}
				}
			}
			if (ok) {
				s = f;
				N = len;
			}
		} else {
			string f = s.substr(0, len);
			string r = f;
			reverse(r.begin(), r.end());
			bool ok = true;
			if (f == r) {
				for (int i = 1; i < k; ++i) {
					if (s.substr(i * len, len) != f) {
						ok = false;
						break;
					}
				}
				if (ok) {
					s = f;
					N = len;
				}
			}
		}
	}

	if (count(s.begin(), s.end(), s[0]) == s.length()) {
		return true;
	}
	bool ans = false;
	string rev = s;
	reverse(rev.begin(), rev.end());
	if ((K % N) == 0) {
		int64_t r = K / N;
		if ((r % 2) == 1) {
			ans = true;
		}
		if (rev == s) {
			ans = true;
		}
	}
	return ans;
}

int main() {
	int64_t T, N, K;
	string s;
	cin >> T;
	for (int tt = 0; tt < T; ++tt) {
		cin >> N >> K;
		cin >> s;
		bool ans = solve(N, K, s);
		cout << (ans ? "Yes" : "No") << endl;
	}
	return 0;
}
