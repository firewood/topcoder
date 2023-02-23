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

vector<int64_t> solve(int64_t N, std::vector<int64_t> K) {
	vector<int64_t> ans(N);
	ans.front() = K.front();
	for (int i = 1; i < N - 1; ++i) {
		ans[i] = min(K[i - 1], K[i]);
	}
	ans.back() = K.back();
	return ans;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> K(N-1);
	for (int i = 0; i < N-1; i++) {
		std::cin >> K[i];
	}
	vector<int64_t> ans = solve(N, K);
	for (size_t i = 0; i < ans.size(); ++i) {
		if (i) cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}
