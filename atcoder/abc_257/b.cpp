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

vector<int> solve(int N, int K, int Q, std::vector<int> A, std::vector<int> L) {
	vector<int> ans = A;
	for (auto a : L) {
		int &pos = ans[a - 1];
		if (pos < N && (a == K || pos + 1 < ans[a])) {
			++pos;
		}
	}
	return ans;
}

int main() {
	int N, K, Q;
	std::cin >> N >> K >> Q;
	std::vector<int> A(K);
	for (int i = 0; i < K; i++) {
		std::cin >> A[i];
	}
	std::vector<int> L(Q);
	for (int i = 0; i < Q; i++) {
		std::cin >> L[i];
	}
	vector<int> ans = solve(N, K, Q, A, L);
	if (!ans.empty()) {
		for (size_t i = 0; i < ans.size(); ++i) {
			if (i) cout << " ";
			cout << ans[i];
		}
		cout << endl;
	}
	return 0;
}
