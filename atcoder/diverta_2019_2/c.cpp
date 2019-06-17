// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;
typedef pair<LL, LL> II;

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	vector<II> ans;
	if (n == 2) {
		LL a, b;
		cin >> a >> b;
		if (a - b > b - a) {
			ans.push_back(II(a, b));
		} else {
			ans.push_back(II(b, a));
		}
	} else {
		vector<LL> a, b;
		for (int i = 0; i < n; ++i) {
			LL x;
			cin >> x;
			if (x < 0) {
				a.push_back(x);
			} else {
				b.push_back(x);
			}
		}
		sort(a.rbegin(), a.rend());
		sort(b.begin(), b.end());
		if (b.empty()) {
			ans.push_back(II(a.front(), a.back()));
			LL prev = a.front() - a.back();
			for (int i = 1; i < (int)a.size() - 1; ++i) {
				ans.push_back(II(prev, a[i]));
				prev = prev - a[i];
			}
		} else if (a.empty()) {
			ans.push_back(II(b.front(), b[b.size() - 2]));
			LL prev = b.front() - b[b.size() - 2];
			for (int i = 1; i < (int)b.size() - 2; ++i) {
				ans.push_back(II(prev, b[i]));
				prev = prev - b[i];
			}
			ans.push_back(II(b.back(), prev));
		} else {
			for (int i = 0; i < (int)b.size() - 1; ++i) {
				ans.push_back(II(a[0], b[i]));
				a[0] = a[0] - b[i];
			}
			int prev = b.back();
			for (int i = 0; i < (int)a.size(); ++i) {
				ans.push_back(II(prev, a[i]));
				prev = prev - a[i];
			}
		}
	}
	cout << (ans.back().first - ans.back().second) << endl;
	for (auto kv : ans) {
		cout << kv.first << " " << kv.second << endl;
	}
	return 0;
}
