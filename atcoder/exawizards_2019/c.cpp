// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	vector<int> kind(q), dir(q);
	for (int i = 0; i < q; ++i) {
		string t, d;
		cin >> t >> d;
		kind[i] = t[0];
		dir[i] = d[0] == 'L' ? -1 : 1;
	}

	int left = 0, right = n;
	while ((right - left) > 1) {
		int mid = (left + right) / 2;
		int pos = mid;
		bool f = true;
		for (int i = 0; i < q; ++i) {
			if (s[pos] == kind[i]) {
				pos += dir[i];
				if (pos >= n) {
					break;
				}
				if (pos < 0) {
					f = false;
					break;
				}
			}
		}
		if (f) {
			right = mid;
		} else {
			left = mid;
		}
	}
	int leftmost = right;

	left = 0, right = n;
	while ((right - left) > 1) {
		int mid = (left + right) / 2;
		int pos = mid;
		bool f = true;
		for (int i = 0; i < q; ++i) {
			if (s[pos] == kind[i]) {
				pos += dir[i];
				if (pos < 0) {
					break;
				}
				if (pos >= n) {
					f = false;
					break;
				}
			}
		}
		if (f) {
			left = mid;
		} else {
			right = mid;
		}
	}
	int rightmost = left;

	int ans = rightmost - leftmost + 1;
	cout << ans << endl;
	return 0;
}
