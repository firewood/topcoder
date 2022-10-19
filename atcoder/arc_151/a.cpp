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

string solve(int64_t N, string S, string T) {
	string ans = "-1";
	int cnt = 0, same = 0, diff = 0;
	for (int i = 0; i < N; ++i) {
		cnt += S[i] != T[i];
	}
	if ((cnt % 2) == 0) {
		ans = string(N, '0');
		for (int i = 0; i < N; ++i) {
			if (S[i] != T[i]) {
				if (same * 2 == cnt) {
					ans[i] = S[i] ^ 1;
				} else if (diff * 2 == cnt) {
					ans[i] = S[i];
				} else if (S[i] == '0') {
					++same;
				} else {
					++diff;
				}
			}
		}
	}
	return ans;
}

int main() {
	int64_t N;
	std::string S, T;
	std::cin >> N >> S >> T;
	cout << solve(N, S, T) << endl;
	return 0;
}
