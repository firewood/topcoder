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

bool solve(int64_t N, std::vector<int64_t> X, std::vector<int64_t> Y, std::string S) {
	map<int64_t, set<int64_t>> left;
	for (int i = 0; i < N; ++i) {
		if (S[i] == 'L') {
			left[Y[i]].insert(X[i]);
		}
	}
	for (int i = 0; i < N; ++i) {
		if (S[i] == 'R') {
			if (left[Y[i]].lower_bound(X[i]) != left[Y[i]].end()) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	int64_t N;
	std::string S;
	std::cin >> N;
	std::vector<int64_t> X(N), Y(N);
	for (int i = 0; i < N; i++) {
		std::cin >> X[i] >> Y[i];
	}
	std::cin >> S;
	cout << (solve(N, X, Y, S) ? "Yes" : "No") << endl;
	return 0;
}
