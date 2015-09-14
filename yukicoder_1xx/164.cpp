#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>

using namespace std;
typedef long long LL;

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	int N = atoi(s.c_str());
	LL ans = (1LL << 63) - 1;
	for (int i = 0; i < N; ++i) {
		getline(cin, s);
		char m = *max_element(s.begin(), s.end());
		LL x = m - '0' + 1;
		if (x > 10) {
			x = m - 'A' + 11;
		}
		LL v = 0;
		for (char c : s) {
			v *= x;
			LL a = c - '0';
			if (a > 9) {
				a = c - 'A' + 10;
			}
			v += a;
		}
		ans = min(ans, v);
	}
	cout << ans << endl;
	return 0;
}
