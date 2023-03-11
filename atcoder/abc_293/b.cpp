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

vector<int> solve(int N, std::vector<int> A) {
	vector<int> ans, u(N);
	for (int i = 0; i < N; ++i) {
		if (!u[i]) {
			u[A[i]] = 1;
		}
	}
	for (int i = 0; i < N; ++i) {
		if (!u[i]) {
			ans.emplace_back(i);
		}
	}
	return ans;
}

int main() {
	int N;
	std::cin >> N;
	std::vector<int> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
		--A[i];
	}
	vector<int> ans = solve(N, A);
	cout << ans.size() << endl;
	if (!ans.empty()) {
		for (size_t i = 0; i < ans.size(); ++i) {
			if (i) cout << " ";
			cout << (ans[i] + 1);
		}
		cout << endl;
	}
	return 0;
}
