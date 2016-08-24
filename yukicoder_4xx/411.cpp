#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	int N, K;
	cin >> N >> K;
	int ans = 0, st = 1 << (N - K), ed = st * 2 - 1;
	for (int b = st; b <= ed; ++b) {
		int c = ((1 << N) - 1) ^ b;
		int mx, mn;
		for (mx = 0; mx < N; ++mx) {
			if ((1 << mx) & b) {
				break;
			}
		}
		for (mn = N - 1; mn >= 0; --mn) {
			if ((1 << mn) & c) {
				break;
			}
		}
		ans += mx < mn;
	}
	cout << ans << endl;
	return 0;
}
