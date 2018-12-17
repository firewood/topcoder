// B. 

#include <sstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
	map<int, int> m;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		m[a] += 1;
	}
	int ans = 0;
	for (int i = 30; i >= 0; --i) {
		int b = 1 << i;
		for (auto kv : m) {
			if (kv.first == b - kv.first) {
				int cnt = kv.second / 2;
				ans += cnt;
				m[kv.first] -= cnt * 2;
			} else {
				int r = b - kv.first;
				if (r < kv.first) {
					break;
				}
				if (r > 0 && m.find(r) != m.end()) {
					int cnt = min(kv.second, m[r]);
					ans += cnt;
					m[kv.first] -= cnt;
					m[r] -= cnt;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
