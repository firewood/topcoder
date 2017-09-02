// C.

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	map<int, int> m;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		m[a - 1] += 1;
		m[a] += 1;
		m[a + 1] += 1;
	}
	int ans = 0;
	for (auto kv : m) {
		ans = max(ans, kv.second);
	}
	cout << ans << endl;
	return 0;
}
