// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int n, x;
	cin >> n >> x;
	vector<int> ans;
	if (x > 1 && x < 2 * n - 1) {
		if (n == 2) {
			ans = {1, 2, 3};
		} else {
			ans.resize(2 * n - 1);
			if (x == 2) {
				ans[n - 2] = 3;
				ans[n - 1 ] = 1;
				ans[n   ] = 2;
				ans[n + 1] = 4;
			} else {
				ans[n - 2] = x - 1;
				ans[n - 1] = x;
				ans[n    ] = x + 1;
				ans[n + 1] = x - 2;
			}
			set<int> s(ans.begin(), ans.end());
			int seq = 1;
			for (int i = 0; i < 2 * n - 1; ++i) {
				if (!ans[i]) {
					while (s.find(seq) != s.end()) {
						++seq;
					}
					s.insert(seq);
					ans[i] = seq;
				}
			}
		}
	}
	if (ans.empty()) {
		cout << "No" << endl;
	} else {
		cout << "Yes" << endl;
		for (int a : ans) {
			cout << a << endl;
		}
	}
	return 0;
}
