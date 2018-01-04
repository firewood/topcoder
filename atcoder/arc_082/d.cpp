// D.

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
	int n, ans = 0;
	cin >> n;
	int a[100001];
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		if (a[i] == i) {
			++ans;
			if (i == n || (i > 1 && a[i - 1] == i - 1)) {
				swap(a[i - 1], a[i]);
			} else {
				swap(a[i], a[i + 1]);
			}
		}
	}
	cout << ans << endl;
}
