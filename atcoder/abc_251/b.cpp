#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

int solve(int N, int W, std::vector<int> A) {
	vector<int> good(W + 1);
	for (int i = 0; i < N; ++i) {
		int a = A[i];
		if (a <= W) {
			good[a] = 1;
		}
		for (int j = i + 1; j < N; ++j) {
			int b = A[j];
			if (a + b <= W) {
				good[a + b] = 1;
			}
			for (int k = j + 1; k < N; ++k) {
				int c = A[k];
				if (a + b + c <= W) {
					good[a + b + c] = 1;
				}
			}
		}
	}
	return accumulate(good.begin(), good.end(), 0);
}

int main() {
	int N, W;
	std::cin >> N >> W;
	std::vector<int> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	cout << solve(N, W, A) << endl;
	return 0;
}
