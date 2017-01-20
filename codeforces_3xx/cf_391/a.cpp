// A. 

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

int main(int argc, char *argv[])
{
	string s;
	cin >> s;
	int cnt[256] = {};
	for (char c : s) {
		cnt[c] += 1;
	}
	const char *a = "au";
	const char *b = "Blbsr";
	int ans = 1 << 30;
	for (int i = 0; i != 3; ++i) {
		ans = min(ans, cnt[a[i]] / 2);
	}
	for (int i = 0; i != 4; ++i) {
		ans = min(ans, cnt[b[i]]);
	}
	cout << ans << endl;
	return 0;
}
