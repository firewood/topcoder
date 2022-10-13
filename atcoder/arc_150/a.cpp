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

bool solve(int N, int K, string s) {
	int left = 1 << 30, right = -1;
	for (int i = 0; i < N; ++i) {
		if (s[i] == '1') {
			left = min(left, i);
			right = max(right, i);
		}
	}
	if (right >= 0) {
		for (int i = left; i <= right; ++i) {
			if (s[i] == '0') return false;
		}
		if ((right - left + 1) == K) {
			return true;
		}
		if ((right - left + 1) > K) {
			return false;
		}
		while (left > 0 && s[left - 1] == '?') {
			--left;
		}
		while (right < (N - 1) && s[right + 1] == '?') {
			++right;
		}
		if ((right - left + 1) == K) {
			return true;
		}
		if ((right - left + 1) < K) {
			return false;
		}
		if (s[left] != s[right]) {
			return true;
		}
		return false;
	}

	int tot = 0, cnt = 0;
	for (int i = 0; i < N; ++i) {
		if (s[i] == '?') {
			++cnt;
			if (cnt > K) return false;
			if (cnt == K) {
				++tot;
				if (tot >= 2) return false;
			}
		} else {
			cnt = 0;
		}
	}
	return tot == 1;
}

int main() {
	int T, N, K;
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
