// A. 

#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;
typedef long long LL;

int main(int argc, char *argv[])
{
	int N, K, L;
	cin >> N >> K >> L;
	int a[1000] = {}, sum[1001] = {};
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}
	sort(a, a + N);
	for (int i = 0; i < N; ++i) {
		sum[i + 1] = sum[i] + a[i];
	}
	LL ans = 1LL << 60;
	for (int i = 1; i <= 1000; ++i) {
		int pos = lower_bound(a, a + N, i + 1) - a;
		LL x = (pos * i) - sum[pos];
		LL y = (sum[N] - sum[pos]) - (N - pos) * i;
		if (x >= y) {
			ans = min(ans, y * K + (x - y) * L);
		}
	}
	cout << ans << endl;
	return 0;
}
