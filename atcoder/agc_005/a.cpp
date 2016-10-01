// A. 

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
	int ans = 0, cnt = 0;
	for (char c : s) {
		if (c == 'S') {
			++cnt;
		} else {
			if (cnt > 0) {
				--cnt;
			} else {
				++ans;
			}
		}
	}
	ans += cnt;
	cout << ans << endl;
	return 0;
}
