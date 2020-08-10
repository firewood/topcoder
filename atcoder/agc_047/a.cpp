// A.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

typedef long long LL;

int main(int argc, char* argv[]) {
	LL n, ans = 0;
	cin >> n;
	vector<vector<int>> sum(20, vector<int>(20));
	vector<int> two(n), five(n);
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		bool p = false;
		LL x = 0;
		for (char c : s) {
			if (c == '.') {
				p = true;
			} else {
				x = (x * 10) + c - '0';
				two[i] -= p;
				five[i] -= p;
			}
		}
		while (x % 2 == 0) {
			++two[i];
			x /= 2;
		}
		while (x % 5 == 0) {
			++five[i];
			x /= 5;
		}
	}
#if 0
	for (int i = 0; i < n; ++i) {
		sum[min(two[i], 9) + 10][min(five[i], 9) + 10] += 1;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = -10; j < 10; ++j) {
			for (int k = -10; k < 10; ++k) {
				if (j + two[i] >= 0 && k + five[i] >= 0) {
					ans += sum[j + 10][k + 10];
				}
			}
		}
		ans -= two[i] >= 0 && five[i] >= 0;
	}
#else
	for (int i = 0; i < n; ++i) {
		sum[10 - min(two[i], 10)][10 - min(five[i], 10)] += 1;
	}
	for (int i = 0; i < 20; ++i) {
		for (int j = 1; j < 20; ++j) {
			sum[i][j] += sum[i][j - 1];
		}
	}
	for (int i = 1; i < 20; ++i) {
		for (int j = 0; j < 20; ++j) {
			sum[i][j] += sum[i - 1][j];
		}
	}
	for (int i = 0; i < n; ++i) {
		ans += sum[min(9, two[i]) + 10][min(9, five[i]) + 10];
		ans -= two[i] >= 0 && five[i] >= 0;
	}
#endif
	cout << ans / 2 << endl;
	return 0;
}
