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

typedef pair<int64_t, int64_t> II;

int main() {
	deque<II> q;
	int64_t Q, t, x, c;
	cin >> Q;
	while (Q-- > 0) {
		cin >> t;
		if (t == 1) {
			cin >> x >> c;
			q.emplace_back(II(x, c));
		} else {
			cin >> c;
			int64_t ans = 0;
			while (c > 0) {
				x = min(c, q.front().second);
				c -= x;
				ans += x * q.front().first;
				q.front().second -= x;
				if (q.front().second <= 0) {
					q.pop_front();
				}
			}
			cout << ans << endl;
		}
	}
	return 0;
}
