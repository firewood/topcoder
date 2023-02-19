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

int64_t solve(int64_t N, int64_t M, std::vector<int64_t> A, std::vector<int64_t> B) {
	int64_t ans = 0;
	for (auto b : B) {
		ans += A[b];
	}
	return ans;
}

int main() {
	int64_t N, M;
	std::cin >> N >> M;
	std::vector<int64_t> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	std::vector<int64_t> B(M);
	for (int i = 0; i < M; i++) {
		std::cin >> B[i];
		--B[i];
	}
	cout << solve(N, M, A, B) << endl;
	return 0;
}
