#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

typedef long long LL;

int main(int argc, char* argv[]) {
	int n, k;
	cin >> n >> k;
	vector<int> ex(n), ey(n), ehp(n), ax(k), ay(k), aw(k), ah(k), ad(k);
	for (int i = 0; i < n; ++i) {
		cin >> ex[i] >> ey[i] >> ehp[i];
		ex[i] += 500;
		ey[i] += 500;
	}
	for (int i = 0; i < k; ++i) {
		cin >> ax[i] >> ay[i] >> aw[i] >> ah[i] >> ad[i];
		ax[i] += 500;
		ay[i] += 500;
	}
	// imos
	vector<vector<LL>> sum(1002, vector<LL>(1002));
	for (int i = 0; i < k; ++i) {
		int left = ax[i], right = min(1000, ax[i] + aw[i]) + 1;
		int top = ay[i], bottom = min(1000, ay[i] + ah[i]) + 1;
		sum[top][left] += ad[i];
		sum[top][right] -= ad[i];
		sum[bottom][left] -= ad[i];
		sum[bottom][right] += ad[i];
	}
	for (int y = 0; y <= 1001; ++y) {
		for (int x = 1; x <= 1001; ++x) {
			sum[y][x] += sum[y][x - 1];
		}
	}
	for (int y = 1; y <= 1001; ++y) {
		for (int x = 0; x <= 1001; ++x) {
			sum[y][x] += sum[y - 1][x];
		}
	}
	LL ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += max(0LL, ehp[i] - sum[ey[i]][ex[i]]);
	}
	cout << ans << endl;
	return 0;
}
