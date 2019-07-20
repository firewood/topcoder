// E.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	map<int, int> m;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		if (m.size()) {
			map<int, int>::iterator it = m.lower_bound(a);
			if (it != m.begin()) {
				--it;
				if (it->second >= 2) {
					it->second--;
				} else {
					m.erase(it);
				}
			}
		}
		m[a] += 1;
	}
	int ans = 0;
	for (auto kv : m) {
		ans += kv.second;
	}
	cout << ans << endl;
	return 0;
}
