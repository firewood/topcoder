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

int solve(int N, std::vector<int> &A) {
	int ans = 1 << 30;
	for (int b = 0; b < (1 << N); ++b) {
		int sum = 0, c = 0, prev = 0;
		for (int i = 0; i < N; ++i) {
			int bit = ((1 << i) & b) != 0;
			if (prev != bit) {
				sum ^= c;
				c = 0;
			}
			c |= A[i];
			prev = bit;
		}
		sum ^= c;
		ans = min(ans, sum);
	}
	return ans;
}

int main() {
    int N;
	std::cin >> N;
	std::vector<int> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	cout << solve(N, A) << endl;
	return 0;
}
