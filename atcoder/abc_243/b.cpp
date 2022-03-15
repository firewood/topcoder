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

pair<int64_t, int64_t> solve(int64_t N, std::vector<int64_t> A, std::vector<int64_t> B) {
	int64_t p = 0, q = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (A[i] == B[j]) {
				if (i == j) {
					++p;
				} else {
					++q;
				}
			}
		}
	}
	return { p, q };
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	std::vector<int64_t> B(N);
	for (int i = 0; i < N; i++) {
		std::cin >> B[i];
	}
	auto ans = solve(N, A, B);
	cout << ans.first << endl;
	cout << ans.second << endl;
	return 0;
}
