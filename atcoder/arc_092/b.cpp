// B.

#include <iostream>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	map<string, int> a, b;
	int n, m;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		a[s] += 1;
	}
	cin >> m;
	for (int i = 0; i < m; ++i) {
		string s;
		cin >> s;
		b[s] += 1;
	}
	int ans = 0;
	for (const auto kv : a) {
		ans = max(ans, kv.second - b[kv.first]);
	}
	cout << ans << endl;
	return 0;
}
