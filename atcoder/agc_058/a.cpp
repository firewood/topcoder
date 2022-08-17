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

vector<int> solve(int64_t N, std::vector<int> P) {
	vector<int> ans;
	for (int i = 0; i < 2 * N - 1; ++i) {
		bool needs_swap = ((i % 2) == 0) == (P[i] > P[i + 1]);
		if ((i % 2) == 0 && i < 2 * N - 2 && P[i] > P[i + 1] && P[i] < P[i + 2]) {
			needs_swap = false;
		}
		if (needs_swap) {
			ans.emplace_back(i + 1);
			swap(P[i], P[i + 1]);
		}
	}
	return ans;
}

int main() {
	int N;
	std::cin >> N;
	std::vector<int> P(2 * N);
	for (int i = 0; i < 2 * N; i++) {
		std::cin >> P[i];
	}
	vector<int> ans = solve(N, P);
	cout << ans.size() << endl;
	if (!ans.empty()) {
		for (size_t i = 0; i < ans.size(); ++i) {
			if (i) cout << " ";
			cout << ans[i];
		}
		cout << endl;
	}
	return 0;
}
