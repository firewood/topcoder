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

vector<int64_t> solve(int64_t Q, std::vector<int64_t> A, std::vector<int64_t> B) {
	vector<int64_t> ans(Q);
	for (int i = 0; i < Q; ++i) {
		int64_t a = A[i], b = B[i], c = sqrt(a * b), & d = ans[i];
		if (a > b) swap(a, b);
		if (a == b) {
			d = (a - 1) * 2;
		} else if (c * (c + 1) < a * b) {
			d = c * 2 - 1;
		} else {
			d = (c - 1) * 2 - (c * c == a * b);
		}
	}
	return ans;
}

int main() {
	int64_t Q;
	std::cin >> Q;
	std::vector<int64_t> A(Q), B(Q);
	for (int i = 0; i < Q; i++) {
		std::cin >> A[i] >> B[i];
	}
	vector<int64_t> ans = solve(Q, A, B);
	for (auto x : ans) {
		cout << x << endl;
	}
	return 0;
}
