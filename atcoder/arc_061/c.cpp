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
	int N = s.length();
	LL ans = 0;
	for (int i = 0; i < N; ++i) {
		LL a = 0;
		for (int j = 1; i + j <= N; ++j) {
			a = (a * 10) + s[i + j - 1] - '0';
			int b = max(0, i - 1) + max(0, N - i - j - 1);
			ans += a * (1 << b);
		}
	}
	cout << ans << endl;
	return 0;
}
