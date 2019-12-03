// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int a[10] = {};
	int b[100] = {};
	int c[1000] = {};
	for (int i = 0; i < n; ++i) {
		int d = s[i] - '0';
		for (int j = 0; j < 100; ++j) {
			if (b[j]) {
				c[j * 10 + d] = 1;
			}
		}
		for (int j = 0; j < 10; ++j) {
			if (a[j]) {
				b[j * 10 + d] = 1;
			}
		}
		a[d] = 1;
	}
	int ans = 0;
	for (int i = 0; i < 1000; ++i) {
		ans += c[i];
	}
	cout << ans << endl;
	return 0;
}
