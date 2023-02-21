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

string solve(int64_t N, std::vector<int64_t> A) {
	string ans(2 * N, ' ');
	vector<int> seq(2 * N), colors(2 * N), q;
	iota(seq.begin(), seq.end(), 0);
	sort(seq.begin(), seq.end(), [&](int lhs, int rhs) { return A[lhs] < A[rhs]; });
	for (int i = 0; i < N; ++i) {
		colors[seq[i]] = 1;
	}
	for (int i = 0; i < 2 * N; ++i) {
		int color = colors[i];
		if (!q.empty() && colors[q.back()] != color) {
			ans[q.back()] = '(';
			ans[i] = ')';
			q.pop_back();
		} else {
			q.emplace_back(i);
		}
	}
	return ans;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> A(2*N);
	for (int i = 0; i < 2*N; i++) {
		std::cin >> A[i];
	}
	cout << solve(N, A) << endl;
	return 0;
}
