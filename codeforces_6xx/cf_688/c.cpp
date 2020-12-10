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

typedef long long LL;
const LL INF = 1LL << 60;

vector <string> rotate(vector <string>& a) {
	if (a.empty()) {
		return a;
	}
	int h = a.size(), w = a[0].length();
	vector <string> r(w);
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			r[j] += a[i][j];
		}
	}
	return r;
}

int main() {
	LL T, n, x;
	cin >> T;
	for (int tt = 0; tt < T; ++tt) {
		cin >> n;
		vector<string> b(n);
		for (LL i = 0; i < n; ++i) {
			cin >> b[i];
		}
		vector<string> c = rotate(b);

		vector<LL> left(10, INF), right(10, -1), top(10, INF), bottom(10, -1);
		for (LL i = 0; i < n; ++i) {
			for (LL j = 0; j < n; ++j) {
				int d = b[i][j] - '0';
				left[d] = min(left[d], j);
				right[d] = max(right[d], j);
				top[d] = min(top[d], i);
				bottom[d] = max(bottom[d], i);
			}
		}

		for (int d = 0; d <= 9; ++d) {
			LL ans = 0;
			for (LL i = 0; i < n; ++i) {
				LL pos = b[i].find(char('0' + d));
				if (pos != string::npos) {
					LL rpos = b[i].rfind(char('0' + d));
					LL a[3] = { pos, n - 1 - pos, rpos };
					for (LL x : a) {
						ans = max(ans, x * abs(top[d] - i));
						ans = max(ans, x * abs(bottom[d] - i));
					}
				}
			}

			for (LL i = 0; i < n; ++i) {
				LL pos = c[i].find(char('0' + d));
				if (pos != string::npos) {
					LL rpos = c[i].rfind(char('0' + d));
					LL a[3] = { pos, n - 1 - pos, rpos };
					for (LL x : a) {
						ans = max(ans, x * abs(left[d] - i));
						ans = max(ans, x * abs(right[d] - i));
					}
				}
			}

			if (d) cout << " ";
			cout << ans;
		}
		cout << endl;
	}
	return 0;
}
