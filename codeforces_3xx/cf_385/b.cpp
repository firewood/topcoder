// B. 

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long LL;

int main(int argc, char *argv[])
{
	int h, w;
	cin >> h >> w;
	string a[505];
	int left = 1 << 30, right = -1, top = 1 << 30, bottom = -1;
	for (int i = 0; i < h; ++i) {
		string s;
		cin >> s;
		a[i] = s;
		int pos = s.find("X");
		if (pos >= 0) {
			left = min(left, pos);
			top = min(top, i);
		}
		pos = s.rfind("X");
		if (pos >= 0) {
			right = max(right, pos);
			bottom = max(bottom, i);
		}
	}
	bool ans = true;
	for (int i = top; i <= bottom; ++i) {
		for (int j = left; j <= right; ++j) {
			if (a[i][j] != 'X') {
				ans = false;
			}
		}
	}
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}
