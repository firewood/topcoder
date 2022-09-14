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

int64_t gcd(int64_t a, int64_t b) { return b ? gcd(b, a % b) : a; }

int64_t solve(int64_t N, std::vector<int64_t> A) {
	int64_t lowest = *min_element(A.begin(), A.end());
	for (int i = 0; i < N; ++i) {
		A[i] -= lowest;
	}
	sort(A.rbegin(), A.rend());
	int64_t g = A[0];
	for (int i = 1; i < N; ++i) {
		if (A[i] > 0) {
			g = gcd(g, A[i]);
		}
	}
	return g == 1 ? 2 : 1;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	cout << solve(N, A) << endl;
	return 0;
}
