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

int main() {
	int N, Q, t, x, y;
	cin >> N >> Q;
	std::vector<int> prev(N + 1, -1), next(N + 1, -1);
	for (int i = 0; i < Q; i++) {
		cin >> t >> x;
		if (t == 1) {
			cin >> y;
			next[x] = y;
			prev[y] = x;
		}
		if (t == 2) {
			cin >> y;
			next[x] = -1;
			prev[y] = -1;
		}
		if (t == 3) {
			vector<int> ans;
			while (prev[x] >= 0) {
				x = prev[x];
			}
			while (x >= 0) {
				ans.emplace_back(x);
				x = next[x];
			}
			cout << ans.size();
			for (auto x : ans) {
				cout << " " << x;
			}
			cout << endl;
		}
	}
	return 0;
}
