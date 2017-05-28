// B.

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[])
{
	string s;
	cin >> s;
	LL n = s.length(), ans = 0;
	for (LL i = 0; i < n; ++i) {
		if (s[i] == 'U') {
			ans += (n - i - 1);
			ans += i * 2;
		} else {
			ans += (n - i - 1) * 2;
			ans += i;
		}
	}
	cout << ans << endl;
	return 0;
}
