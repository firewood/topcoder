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

bool solve(int64_t N, std::vector<int64_t> A) {
	vector<int> f(N);
	for (auto x : A) {
		f[x - 1] = 1;
	}
	return accumulate(f.begin(), f.end(), 0) == N;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	cout << (solve(N, std::move(A)) ? "Yes" : "No") << endl;
	return 0;
}
