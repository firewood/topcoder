// A. 

#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main(int argc, char *argv[])
{
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	bool ans = false;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i] == k) {
			ans = true;
		}
	}
	sort(a.begin(), a.end());
	if (n == 1) {
		ans = a[0] == k;
	} else if (!ans) {
		int g = a[1] - a[0];
		for (int i = 2; i < n; ++i) {
			g = gcd(g, a[i] - a[i-1]);
		}
		for (int i = 0; i < n; ++i) {
			if (a[i] > g && a[i] > k && ((a[i] - k) % g) == 0) {
				ans = true;
				break;
			}
		}
	}
	cout << (ans ? "POSSIBLE" : "IMPOSSIBLE") << endl;
	return 0;
}
