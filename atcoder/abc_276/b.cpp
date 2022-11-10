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

vector<set<int>> solve(int N, int M, std::vector<int> A, std::vector<int> B) {
	vector<set<int>> ans(N);
	for (int i = 0; i < M; ++i) {
		ans[A[i]].insert(B[i]);
		ans[B[i]].insert(A[i]);
	}
	return ans;
}

int main() {
	int N, M;
	std::cin >> N >> M;
	std::vector<int> A(M), B(M);
	for (int i = 0; i < M; i++) {
		std::cin >> A[i] >> B[i];
		--A[i];
		--B[i];
	}
	vector<set<int>> ans = solve(N, M, A, B);
	for (const auto& s : ans) {
		cout << s.size();
		for (auto x : s) {
			cout << " " << x + 1;
		}
		cout << endl;
	}
	return 0;
}
