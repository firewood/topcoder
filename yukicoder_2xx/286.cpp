#include <iostream>
#include <algorithm>
#include <numeric>
#include <cstring>

using namespace std;

int N;
int M[16];
int memo[1 << 15];

int dfs(int b) {
	int &r = memo[b];
	if (r < 0) {
		r = 0;
		int sum = 0;
		for (int i = 0; i < N; ++i) {
			if (b & (1 << i)) {
				sum += M[i];
			}
		}
		for (int i = 0; i < N; ++i) {
			int a = (b & (1 << i));
			if (a) {
				int c = dfs(b ^ a);
				r = max(r, c + min(M[i], (sum - M[i]) % 1000));
			}
		}
	}
	return r;
}

int main(int argc, char *argv[]) {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> M[i];
	}

	memset(memo, -1, sizeof(memo));
	int discount = dfs((1 << N) - 1);
	int sum = accumulate(M, M + N, 0);
	int ans = sum - discount;
	cout << ans << endl;

	return 0;
}
