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

typedef long double LD;
typedef pair<int64_t, int64_t> II;
typedef pair<int64_t, II> III;

static const int64_t INF = 1LL << 60;

vector<int> solve(int N, int K, std::vector<int> A) {
	int left = 1;
	vector<int> ans, used(N + 1);
	for (int i = 0; i < K - 1; ++i) {
		ans.emplace_back(A[i]);
		used[A[i]] = 1;
		while (left < A[i] && left < A[i + 1]) {
			if (!used[left]) {
				ans.emplace_back(left);
				used[left] = 1;
				++left;
				break;
			}
			++left;
		}
	}
	for (int i = N; i >= 1; --i) {
		if (!used[i]) {
			ans.emplace_back(i);
		}
	}
	return ans;
}

int main() {
	int N, K;
	std::cin >> N >> K;
	std::vector<int> A(K);
	for (int i = 0; i < K; i++) {
		std::cin >> A[i];
	}
	vector<int> ans = solve(N, K, A);
	for (size_t i = 0; i < ans.size(); ++i) {
		if (i) cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}
