// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
	while (true) {
		int n = -1, k = -1;
		cin >> n >> k;
		if (n <= 0 || k <= 0) break;
		vector<int> p(n), g(n);
		for (int i = 0; i < n; ++i) {
			cin >> p[i];
		}
		int last = 1 << 30, cnt = 0;
		for (int i = n - 1; i >= 0; --i) {
			if (p[i] < last) {
				++cnt;
			} else {
				cnt = 1;
			}
			g[i] = cnt;
			last = p[i];
		}
		set<int> s;
		s.insert(p[0]);
		int ans = 0;
		for (int i = 1; i < k; ++i) {
			s.insert(p[i]);
		}
		ans += g[0] < k;
		int sf = g[0] >= k;
		for (int i = k; i < n; ++i) {
			int low = *(s.begin());
			s.erase(p[i - k]);
			int high = *(s.rbegin());
			if ((low != p[i - k]) || (p[i] < high)) {
				if (g[i - k + 1] < k) {
					++ans;
				} else {
					sf = 1;
				}
			}
			s.insert(p[i]);
		}
		ans += sf;
		cout << ans << endl;
	}
	return 0;
}
