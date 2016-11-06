// C.

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long LL;

int main(int argc, char *argv[])
{
	string s;
	cin >> s;
	int ans = 0;
	for (int i = 1; i != s.length(); ++i) {
		ans += s[i - 1] != s[i];
	}
	cout << ans << endl;
	return 0;
}
