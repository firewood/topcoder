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

bool solve(int64_t N, int64_t X, int64_t Y, vector<int64_t>& A) {
	if (!any_of(A.begin(), A.end(), [&](auto a) { return (a % (X + Y)) >= X; })) {
		return false;
	}
	if (X <= Y) {
		return true;
	}
	return !any_of(A.begin(), A.end(), [&](auto a) { return ((a % (X + Y)) % X) >= Y; });
}

int main() {
	int64_t N, X, Y;
	std::cin >> N >> X >> Y;
	std::vector<int64_t> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	cout << (solve(N, X, Y, A) ? "First" : "Second") << endl;
	return 0;
}
