// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef long long LL;

int main(int argc, char* argv[]) {
	int n, ans = 0;
	cin >> n;
	vector<int> cnt(n + 1);
	for (int a = 1; a <= 100; ++a) {
		for (int b = 1; b <= 100; ++b) {
			for (int c = 1; c <= 100; ++c) {
				int d = a * a + b * b + c * c + a * b + b * c + c * a;
				if (d <= n) {
					cnt[d] += 1;
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		cout << cnt[i] << endl;
	}
	return 0;
}
