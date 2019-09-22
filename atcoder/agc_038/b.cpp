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
		vector<int> p(n + 1, n), conseq(n);
		for (int i = 0; i < n; ++i) {
			cin >> p[i];
		}
		int cnt = 0, ans = 0;
		for (int i = n - 1; i >= 0; --i) {
			if (p[i] >= p[i + 1]) {
				cnt = 0;
			}
			conseq[i] = ++cnt;
			if (conseq[i] >= k) {
				ans = 1;
			}
		}
		set<int> s(p.begin(), p.begin() + k);
		ans += conseq[0] < k;
		for (int i = k; i < n; ++i) {
			int low = *(s.begin());
			s.erase(p[i - k]);
			int high = *(s.rbegin());
			if ((low != p[i - k]) || (p[i] < high)) {
				ans += conseq[i - k + 1] < k;
			}
			s.insert(p[i]);
		}
		cout << ans << endl;
	}
	return 0;
}
