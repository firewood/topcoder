// A. 

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;

int memo[102][102][102];

int win(int l, int m, int r) {
	int &ret = memo[l][m][r];
	if (!ret) {
		if (m == 1 && r == 0) {
			ret = 1;
			return ret;
		}
		if (l == 0 && m == 0) {
			ret = 3;
			return ret;
		}
		ret = 2;
		if (m > 0) {
			int x = win(r, m - 1, l + 1);
			if (x == 1) {
				ret = 3;
			}
			if (x == 3) {
				ret = 1;
				return ret;
			}
		}
		if (l > 0) {
			int x = win(r, m + 1, l - 1);
			if (x == 1) {
				ret = 3;
			}
			if (x == 3) {
				ret = 1;
				return ret;
			}
		}
	}
	return ret;
}

int main(int argc, char *argv[])
{
	memset(memo, 0, sizeof(memo));
	int n, a, b;
	cin >> n >> a >> b;
	if (a > b) {
		a = n - a + 1;
		b = n - b + 1;
	}
	int l = a - 1;
	int m = b - a - 1;
	int r = n - b;
	int ans = win(l, m, r);
	const char *res[] = { "", "Alice", "Draw", "Borys" };
	cout << res[ans] << endl;
	return 0;
}
