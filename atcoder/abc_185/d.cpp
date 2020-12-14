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

int solve(int N, int M, std::vector<int> &A) {
	int ans = 0;
	sort(A.begin(), A.end());
	A.insert(A.begin(), 0);
	A.emplace_back(N + 1);
	int m = 1 << 30;
	for (int i = 1; i <= M + 1; ++i) {
		int d = A[i] - A[i - 1] - 1;
		if (d > 0) m = min(m, d);
	}
	for (int i = 1; i <= M + 1; ++i) {
		int d = max(0, A[i] - A[i - 1] - 1);
		ans += (d + m - 1) / m;
	}
	return ans;
}

int main() {
	int N, M;
	std::cin >> N >> M;
	std::vector<int> A(M);
	for (int i = 0; i < M; i++) {
		std::cin >> A[i];
	}
	cout << solve(N, M, A) << endl;
	return 0;
}
