// C.

#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<int, int> II;

int main(int argc, char *argv[]) {
	int n, k;
	cin >> n >> k;
	map<int, int> m;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		m[a] += 1;
	}
	vector<II> v;
	for (auto kv : m) {
		v.push_back(II(kv.second, kv.first));
	}
	sort(v.begin(), v.end());
	int ans = 0;
	for (int i = 0; i < ((int)v.size() - k); ++i) {
		ans += v[i].first;
	}
	cout << ans << endl;
	return 0;
}
