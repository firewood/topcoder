#include <iostream>
#include <algorithm>
using namespace std;

static const int MOD = 1000000007;

int N;
int H[2][100002];
int mm[100002];
int mx[100002];

int solve() {
	if (H[0][N - 1] != H[1][0]) {
		return 0;
	}
	mm[0] = H[0][0];
	mx[0] = H[0][0];
	for (int i = 1; i < N; ++i) {
		mm[i] = 1;
		mx[i] = min(H[0][i], H[1][i]);
		if (H[0][i] < H[0][i - 1]) {
			return 0;
		}
		if (H[0][i] > H[0][i - 1]) {
			mm[i] = max(mm[i], H[0][i]);
			mx[i] = min(mx[i], H[0][i]);
		}
	}
	mm[N - 1] = H[1][N - 1];
	mx[N - 1] = H[1][N - 1];
	for (int i = 0; i < N - 1; ++i) {
		if (H[1][i] < H[1][i + 1]) {
			return 0;
		}
		if (H[1][i] > H[1][i + 1]) {
			mm[i] = max(mm[i], H[1][i]);
			mx[i] = min(mx[i], H[1][i]);
		}
	}
	int ans = 1;
	for (int i = 1; i < N; ++i) {
		long long d = max(0, mx[i] - mm[i] + 1);
		ans = (int)((ans * d) % MOD);
	}
	return ans;
}

int main(int argc, char *argv[])
{
	cin >> N;
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> H[i][j];
		}
	}
	cout << solve() << endl;
	return 0;
}
