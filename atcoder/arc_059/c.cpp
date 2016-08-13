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
	int N, sum[202] = {};
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int a;
		cin >> a;
		for (int j = -100; j <= 100; ++j) {
			sum[j + 100] += (a - j) * (a - j);
		}
	}
	int ans = 1 << 30;
	for (int j = -100; j <= 100; ++j) {
		ans = min(ans, sum[j + 100]);
	}
	cout << ans << endl;
	return 0;
}
