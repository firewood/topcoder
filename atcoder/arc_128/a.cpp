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

vector<int64_t> solve(int64_t N, std::vector<int64_t> A) {
	vector<int64_t> ans(N);
	int64_t bi = -1, si = -1;
	for (int i = 0; i < N; ++i) {
		int64_t a = A[i];
		if (si >= 0 && a < A[si]) {
			ans[si] = 0;
			si = i;
			ans[si] = 1;
		} else {
			si = -1;
			if (bi < 0 || a > A[bi]) {
				bi = i;
			} else if (bi >= 0 && a < A[bi]) {
				ans[bi] = 1;
				bi = -1;
				si = i;
				ans[si] = 1;
			}
		}
	}
	return ans;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	vector<int64_t> ans = solve(N, A);
	for (int i = 0; i < N; ++i) {
		if (i) cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}
