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

int64_t f(int64_t N) {
	int64_t ans = 0;
	string s = to_string(N);
	int len = int(s.length());
	auto gen = [&](int64_t x) {
		string xs = to_string(x), s;
		while (s.length() < len) {
			s += xs;
		}
		int64_t a = stoll(s);
		if (a <= N) {
			ans = max(ans, a);
		}
	};
	for (int i = 1; i <= len / 2; ++i) {
		if ((len % i) == 0) {
			int64_t x = stoll(s.substr(0, i));
			gen(x);
			if (x > 1) {
				gen(x - 1);
			}
		}
	}
	return ans;
}

int64_t solve(int64_t N) {
	return max(f(N), stoll(string(to_string(N).length() - 1, '9')));
}

int main() {
	int64_t T, N;
	cin >> T;
	for (int tt = 0; tt < T; ++tt) {
		cin >> N;
		int64_t ans = solve(N);
		cout << ans << endl;
	}
	return 0;
}
