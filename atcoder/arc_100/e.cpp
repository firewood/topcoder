// E.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> dp[2];

void update(int a, int b) {
	vector<int> v = { dp[0][a], dp[1][a], dp[0][b], dp[1][b] };
	sort(v.rbegin(), v.rend());
	dp[0][a] = v[0];
	dp[1][a] = v[1];
}

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	int bm = 1 << n;
	dp[0].resize(bm);
	dp[1].resize(bm);
	for (int i = 0; i < bm; ++i) {
		cin >> dp[0][i];
	}
	for (int i = 1; i < bm; i <<= 1) {
		for (int j = 0; j < bm; ++j) {
			if (j & i) {
				update(j, j ^ i);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i < bm; ++i) {
		ans = max(ans, dp[0][i] + dp[1][i]);
		cout << ans << endl;
	}
}
