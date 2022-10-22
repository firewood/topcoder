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

vector<int> solve(int64_t N, std::vector<int64_t> A) {
	vector<int> ans(N * 2 + 1);
	for (int i = 0; i < N; ++i) {
		ans[i * 2 + 1] = ans[i * 2 + 2] = ans[A[i]] + 1;
	}
	return ans;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
		--A[i];
	}
	vector<int> ans = solve(N, A);
	for (size_t i = 0; i < ans.size(); ++i) {
		cout << ans[i] << endl;
	}
	return 0;
}
