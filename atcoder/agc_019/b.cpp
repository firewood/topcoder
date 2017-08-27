// B.

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
	string s;
	cin >> s;
	int cnt[256] = {};
	long long ans = 1, len = (int)s.length();
	for (int i = 0; i < len; ++i) {
		int c = s[i];
		ans += i - cnt[c];
		cnt[c] += 1;
	}
	cout << ans << endl;
	return 0;
}
