// B.

#include <iostream>
#include <sstream>
#include <set>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = 0;
	for (int i = 1; i < n; ++i) {
		set<int> x, y;
		int cnt[256] = {};
		for (int j = 0; j < n; ++j) {
			if (j < i) {
				x.insert(s[j]);
			} else if (x.find(s[j]) != x.end()) {
				y.insert(s[j]);
			}
		}
		ans = max(ans, (int)y.size());
	}
	cout << ans << endl;
	return 0;
}
