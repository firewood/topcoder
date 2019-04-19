// D.

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <bitset>

using namespace std;

int main(int argc, char *argv[]) {
	int N, K;
	cin >> N >> K;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	int left = -1, right = N;
	while (right - left > 1) {
		int mid = (left + right) / 2;
		bitset<5001> sum;
		sum[0] = 1;
		for (int i = 0; i < N; ++i) {
			if (i != mid) {
				sum |= sum << A[i];
			}
		}
		int nes = A[mid] >= K;
		for (int i = K - A[mid]; !nes && i < K; ++i) {
			if (sum[i]) {
				nes = 1;
			}
		}
		if (nes) {
			right = mid;
		} else {
			left = mid;
		}
	}
	int ans = left + 1;
	cout << ans << endl;
	return 0;
}
