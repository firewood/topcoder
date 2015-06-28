#include <iostream>
#include <algorithm>
#include <sstream>
#include <numeric>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	stringstream sa(s);
	int Q;
	sa >> Q;
	for (int i = 0; i < Q; ++i) {
		getline(cin, s);
		stringstream sb(s);
		LL x[10001] = {}, N, K, B, y[10001];
		sb >> x[0] >> N >> K >> B;
		for (int j = 1; j <= N; ++j) {
			x[j] = 1 + (x[j - 1] * (x[j - 1] + 12345)) % 100000009;
		}

		LL ans = 1 << 30;
		for (int p = 2; B > 1; ++p) {
			LL f = 0;
			while ((B % p) == 0) {
				++f;
				B /= p;
			}
			if (f > 0) {
				for (int j = 0; j <= N; ++j) {
					int cnt = 0;
					LL n = x[j];
					while ((n % p) == 0) {
						++cnt;
						n /= p;
					}
					y[j] = cnt;
				}
				sort(y, y + N + 1);
				ans = min(ans, accumulate(y, y + K, 0LL) / f);
			}
		}
		cout << ans << endl;
	}

	return 0;
}
