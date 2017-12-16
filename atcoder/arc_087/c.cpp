// C.

#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<int, int> II;

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	map<int, int> m;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		m[a] += 1;
	}
	int ans = 0;
	for (auto kv : m) {
		if (kv.first > kv.second) {
			ans += kv.second;
		} else if (kv.first < kv.second) {
			ans += kv.second - kv.first;
		}
	}
	cout << ans << endl;
	return 0;
}
