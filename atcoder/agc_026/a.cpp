// A. 

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	int prev = -1, cnt = 0, ans = 0;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		if (prev == a) {
			++cnt;
		} else {
			ans += cnt / 2;
			cnt = 1;
		}
		prev = a;
	}
	ans += cnt / 2;
	cout << ans << endl;
	return 0;
}
