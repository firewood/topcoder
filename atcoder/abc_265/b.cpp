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

bool solve(int64_t N, int64_t M, int64_t T, std::vector<int64_t> A, std::vector<int64_t> X, std::vector<int64_t> Y) {
	vector<int64_t> b(N);
	for (int i = 0; i < M; ++i) {
		b[X[i]] += Y[i];
	}
	for (int i = 0; i < N - 1; ++i) {
		T += b[i];
		if (T <= A[i]) return false;
		T -= A[i];
	}
	return true;
}

int main() {
	int64_t N, M, T;
	std::cin >> N >> M >> T;
	std::vector<int64_t> A(N - 1);
	for (int i = 0; i < N - 1; i++) {
		std::cin >> A[i];
	}
	std::vector<int64_t> X(M), Y(M);
	for (int i = 0; i < M; i++) {
		std::cin >> X[i] >> Y[i];
		--X[i];
	}
	cout << (solve(N, M, T, A, X, Y) ? "Yes" : "No") << endl;
	return 0;
}
