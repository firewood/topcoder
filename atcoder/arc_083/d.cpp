// D.

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	long long d[300][300], w[300][300];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> d[i][j];
			w[i][j] = d[i][j];
		}
	}
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
			}
		}
	}
	long long ans = 0;
	for (int i = 0; ans >= 0 && i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (w[i][j] < d[i][j]) {
				ans = -1;
				break;
			}
			bool e = false;
			for (int k = 0; k < n; ++k) {
				if (i != k && j != k && w[i][k] + w[k][j] == d[i][j]) {
					e = true;
					break;
				}
			}
			if (!e) {
				ans += d[i][j];
			}
		}
	}
	cout << ans << endl;
}
