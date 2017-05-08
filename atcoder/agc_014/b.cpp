// B.

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	int n, m;
	cin >> n >> m;
	int cnt[100001] = {};
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		cnt[a]++;
		cnt[b]++;
	}
	bool ans = true;
	for (int i = 1; i <= n; ++i) {
		if (cnt[i] % 2) {
			ans = false;
		}
	}
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}
