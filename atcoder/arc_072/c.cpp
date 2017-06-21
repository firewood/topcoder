// C.

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[])
{
	LL n, a, sum[2] = {}, ans[2] = {};
	cin >> n;
	for (LL i = 0; i < n; ++i) {
		cin >> a;
		for (LL j = 0; j < 2; ++j) {
			sum[j] += a;
			if ((i + j) % 2) {
				if (sum[j] <= 0) {
					ans[j] += (1 - sum[j]);
					sum[j] = 1;
				}
			} else {
				if (sum[j] >= 0) {
					ans[j] += 1 + sum[j];
					sum[j] = -1;
				}
			}
		}
	}
	cout << min(ans[0], ans[1]) << endl;
	return 0;
}
