// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

int main(int argc, char* argv[]) {
	LL n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<int> first(200002, -1), next(200002, -1), vis(n, -1);
	for (int i = n - 1; i >= 0; --i) {
		next[i] = first[a[i]];
		first[a[i]] = i;
	}
	bool skipped = false;
	int pos = 0;
	vector<int> ans;
	for (LL i = 0; i < k; ++i) {
		while (pos < n) {
			if (!skipped && vis[pos] >= 0) {
				skipped = true;
				LL t = i - vis[pos];
				i += (max(0LL, (k - i - 3) / t)) * t;
			} else {
				vis[pos] = i;
			}
			int next_pos = next[pos];
			if (next_pos < 0) {
				if (i == k - 1) {
					ans.push_back(a[pos++]);
				} else {
					pos = first[a[pos]] + n + 1;
				}
			} else {
				pos = next_pos + 1;
			}
		}
		pos -= n;
	}
	for (auto x : ans) {
		cout << " " << x;
	}
	cout << endl;
	return 0;
}
