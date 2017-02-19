// B.

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[])
{
	LL st, ed, t, left, ans, w = 1e13;
	cin >> st >> ed >> t;
	int N;
	cin >> N;
	left = st;
	for (int i = 0; i < N; ++i) {
		LL a;
		cin >> a;
		if (a > left && left <= (ed - t)) {
			ans = left;
			break;
		}
		LL d = left - a + 1;
		if (d < w) {
			ans = a - 1;
			w = d;
		}
		left += t;
	}
	if (left <= (ed - t)) {
		ans = left;
	}
	cout << ans << endl;
	return 0;
}
