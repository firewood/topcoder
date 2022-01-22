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
	int x = A.back();
	for (int i = 1; i < N; ++i) {
		if (A[i - 1] > A[i]) {
			x = A[i - 1];
			break;
		}
	}
	vector<int> ans;
	for (int i = 0; i < N; ++i) {
		if (A[i] != x) {
			ans.emplace_back(A[i]);
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
	}
	vector<int> ans = solve(N, A);
	for (size_t i = 0; i < ans.size(); ++i) {
		if (i) cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}
