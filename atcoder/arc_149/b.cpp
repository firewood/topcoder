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

int get_lis(const vector<int>& a) {
	size_t N = a.size();
	vector<int> c(N, 1 << 30);
	for (int i = 0; i < N; ++i) {
		*lower_bound(c.begin(), c.end(), a[i]) = a[i];
	}
	return int(lower_bound(c.begin(), c.end(), 1 << 30) - c.begin());
}

int64_t solve(int N, std::vector<int> A, std::vector<int> B) {
	vector<int> seq(N), b(N);
	iota(seq.begin(), seq.end(), 0);
	sort(seq.begin(), seq.end(), [&](int lhs, int rhs) { return A[lhs] < A[rhs]; });
	for (int i = 0; i < N; ++i) {
		b[i] = B[seq[i]];
	}
	return N + get_lis(b);
}

int main() {
	int N;
	std::cin >> N;
	std::vector<int> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	std::vector<int> B(N);
	for (int i = 0; i < N; i++) {
		std::cin >> B[i];
	}
	cout << solve(N, A, B) << endl;
	return 0;
}
