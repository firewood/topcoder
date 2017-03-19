// D.

#include <iostream>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main(int argc, char *argv[]) {
	int N, K;
	cin >> N >> K;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int ans = 0;
	if (K <= 400) {
		for (int i = 0; i < N; ++i) {
			int f[2][400] = { 1 };
			int p = 0, q = 1;
			for (int j = 0; j < N; ++j) {
				if (i == j) {
					continue;
				}
				int m = K - A[j];
				for (int k = 0; k < K; ++k) {
					if (f[p][k]) {
						f[q][k] = 1;
						if (k < m) {
							f[q][k + A[j]] = 1;
						}
					}
				}
				p = !p, q = !q;
			}
			int u = accumulate(&(f[p][0]) + max(0, K - A[i]), &(f[p][0]) + K, 0);
			if (!u) {
				++ans;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
