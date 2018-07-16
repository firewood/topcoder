// C.

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <numeric>
#include <map>

using namespace std;

typedef long long LL;
typedef pair<string, string> SS;

static inline int popcount(unsigned int b) {
#ifdef __GNUC__
	return __builtin_popcount(b);
#elif _MSC_VER >= 1400
	return __popcnt(b);
#else
	b = (b & 0x55555555) + (b >> 1 & 0x55555555);
	b = (b & 0x33333333) + (b >> 2 & 0x33333333);
	b = (b & 0x0F0F0F0F) + (b >> 4 & 0x0F0F0F0F);
	b += b >> 8;
	return (b + (b >> 16)) & 0x3F;
#endif
}

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int bm = 1 << n;
	map<SS, LL> m[19];
	for (int b = 0; b < bm; ++b) {
		string x[2];
		for (int i = 0, j = 1; i < n; ++i, j <<= 1) {
			if (j & b) {
				x[0] += s[i];
			} else {
				x[1] = s[i] + x[1];
			}
		}
		m[popcount(b)][SS(x[0], x[1])] += 1;
	}
	LL ans = 0;
	for (int b = 0; b < bm; ++b) {
		string x[2];
		for (int i = 0, j = 1; i < n; ++i, j <<= 1) {
			if (j & b) {
				x[0] += s[2 * n - i - 1];
			} else {
				x[1] = s[2 * n - i - 1] + x[1];
			}
		}
		ans += m[popcount(b)][SS(x[0], x[1])];
	}
	cout << ans << endl;
}
