// C.

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[])
{
	map<long long, int> m;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		long long a;
		cin >> a;
		m[a] += 1;
	}
	LL ans = 0;
	vector<long long> v;
	for (auto &kv : m) {
		if (kv.second >= 4) {
			ans = max(ans, kv.first * kv.first);
		}
		if (kv.second >= 2) {
			v.push_back(kv.first);
		}
	}
	if (v.size() >= 2) {
		ans = max(ans, v[v.size() - 2] * v[v.size() - 1]);
	}
	cout << ans << endl;
	return 0;
}
