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
	LL N, K;
	cin >> N >> K;
	LL ans = 0, cnt = 0, sum = 0, a[100000];
	for (LL i = 0; i < N; ++i) {
		cin >> a[i];
		sum += a[i];
		++cnt;
		if (cnt > K) {
			sum -= a[i - K];
			--cnt;
		}
		if (cnt == K) {
			ans += sum;
		}
	}
	cout << ans << endl;
	return 0;
}
