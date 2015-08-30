#include <iostream>
#include <algorithm>
#include <sstream>
#include <numeric>

using namespace std;

int main(int argc, char *argv[])
{
	int N[2];
	int W[2][1000] = {};
	cin >> N[0];
	for (int i = 0; i < N[0]; ++i) {
		cin >> W[0][i];
	}
	cin >> N[1];
	for (int i = 0; i < N[1]; ++i) {
		cin >> W[1][i];
	}
	sort(W[0], W[0] + N[0]);
	sort(W[1], W[1] + N[1]);
	int ans = 1;
	for (int i = 0; i < 2; ++i) {
		int cnt = 0;
		int len = 0;
		int index[2] = { 0, 0 };
		int next = i;
		while (1) {
			for (; index[next] < N[next]; ++index[next]) {
				if (W[next][index[next]] > len) {
					break;
				}
			}
			if (index[next] >= N[next]) {
				break;
			}
			++cnt;
			len = W[next][index[next]];
			next ^= 1;
		}
		ans = max(ans, cnt);
	}
	cout << ans << endl;
	return 0;
}
