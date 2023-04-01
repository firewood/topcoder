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

bool solve(int64_t N, int64_t X, std::vector<int64_t> A) {
	set<int64_t> s(A.begin(), A.end());
	for (auto x : A) {
		if (s.find(x + X) != s.end()) {
			return true;
		}
	}
	return false;
}

int main() {
	int64_t N, X;
	std::cin >> N >> X;
	std::vector<int64_t> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	cout << (solve(N, X, A) ? "Yes" : "No") << endl;
	return 0;
}
