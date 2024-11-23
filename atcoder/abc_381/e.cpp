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

typedef long double LD;
typedef pair<int64_t, int64_t> II;
typedef pair<int64_t, II> III;

static const int64_t INF = 1LL << 60;

int main() {
	int N, Q, L, R;
	cin >> N >> Q;
	string S;
	cin >> S;

	vector<int> one_pos(100002, -1), one_cnt(100002), two_pos(100002, -1), two_cnt(100002);
	set<int> slash_pos;
	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		if (S[i] == '1') {
			one_pos[++cnt] = i;
		}
		if (S[i] == '/') {
			slash_pos.insert(i);
		}
		one_cnt[i + 1] = cnt;
	}
	cnt = 0;
	for (int i = N - 1; i >= 0; --i) {
		if (S[i] == '2') {
			two_pos[++cnt] = i;
		}
		two_cnt[i + 1] = cnt;
	}
	slash_pos.insert(N);

	for (int q = 0; q < Q; ++q) {
		int ans = 0;
		cin >> L >> R;
		--L;
		if (*slash_pos.lower_bound(L) < R) {
			int left = 0, right = R - L;
			auto possible = [&](int t) -> bool {
				int left_pos = one_pos[one_cnt[L] + t];
				if (left_pos >= 0) {
					int right_pos = two_pos[two_cnt[R + 1] + t];
					return *slash_pos.lower_bound(left_pos) < right_pos;
				}
				return false;
			};
			while (right - left > 1) {
				int mid = (left + right) / 2;
				if (possible(mid)) {
					left = mid;
				} else {
					right = mid;
				}
			}
			ans = left * 2 + 1;
		}
		cout << ans << endl;
	}
	return 0;
}
