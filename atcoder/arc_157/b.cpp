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

int solve(int N, int K, std::string S) {
	int ans = 0;
	int xcnt = count(S.begin(), S.end(), 'X'), ycnt = N - xcnt;
	if (xcnt <= 0) {
		return max(0, N - 1 - K);
	}
	if (K <= xcnt) {
		int prev = -1, yc = 0;
		bool in_y = false;
		vector<int> v;
		for (char c : S) {
			if (c == 'X') {
				if (in_y) {
					++yc;
				}
			} else {
				if (in_y && yc > 0) {
					v.emplace_back(yc);
				}
				in_y = true;
				yc = 0;
				if (prev == 'Y') {
					++ans;
				}
			}
			prev = c;
		}
		sort(v.begin(), v.end());
		for (int c : v) {
			if (c > K) {
				break;
			}
			K -= c;
			ans += c + 1;
		}
		if (ycnt <= 0) {
			--K;
		}
		ans += max(0, K);
	} else {
		K -= xcnt;
		int left = 0, right = N - 1, dc = 0;
		while (S[left] == 'Y') {
			++dc;
			++left;
			if (left >= N) {
				break;
			}
		}
		while (S[right] == 'Y') {
			++dc;
			--right;
			if (right < 0) {
				break;
			}
		}

		if (dc >= K) {
			ans = max(0, right - left) + dc - K;
			return ans;
		}

		K -= dc;

		int prev = -1, xc = 0;
		bool in_x = false;
		vector<int> v;
		for (int i = left; i <= right; ++i) {
			int c = S[i];
			if (c == 'Y') {
				if (in_x) {
					++xc;
				}
			} else {
				if (in_x && xc > 0) {
					v.emplace_back(xc);
				}
				in_x = true;
				xc = 0;
				if (prev == 'X') {
					++ans;
				}
			}
			prev = c;
		}
		if (K <= 0) {
			return ans;
		}
		sort(v.rbegin(), v.rend());

		ans = right - left;

		for (int c : v) {
			--ans;
			int d = min(c, K);
			ans -= d;
			K -= d;
			if (K <= 0) {
				break;
			}
		}
	}
	return ans;
}

int main() {
	int N, K;
	std::string S;
	std::cin >> N >> K >> S;
	//	vector<int64_t> ans = solve(N, K, S);
	cout << solve(N, K, S) << endl;
	return 0;
}
