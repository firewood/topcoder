// B. 

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long LL;

int main(int argc, char *argv[])
{
	LL N, x, ans = 1LL << 60;
	cin >> N >> x;
	vector<LL> a(N);
	for (LL i = 0; i < N; ++i) {
		cin >> a[i];
	}
	vector<LL> b = a;
	for (LL i = 0; i < N; ++i) {
		LL sum = accumulate(b.begin(), b.end(), x * i);
		ans = min(ans, sum);
		for (LL j = 0; j < N; ++j) {
			int k = (j - i - 1 + 2 * N) % N;
			b[j] = min(b[j], a[k]);
		}
	}
	cout << ans << endl;
	return 0;
}
