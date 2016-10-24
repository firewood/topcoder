#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char *argv[])
{
	int K, T, m = 0;
	cin >> K >> T;
	for (int i = 0; i < T; ++i) {
		int a;
		cin >> a;
		m = max(m, a);
	}
	int ans = 0;
	if (m > K / 2) {
		int r = K - m;
		int k[10002] = {};
		for (int i = 0; i < r; ++i) {
			k[i * 2 + 1] = 1;
		}
		for (int i = 1; i < K; ++i) {
			ans += k[i - 1] == 0 && k[i] == 0;
		}
	}
	cout << ans << endl;
	return 0;
}
