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

typedef pair<int, int> II;

vector<II> memo(10001, II(-1, -1));

II search(const vector<int> &a, int n) {
	II& ret = memo[n];
	if (ret.first < 0) {
		ret = { 0,0 };
		for (auto x : a) {
			int r = n - x;
			if (r < 0) break;
			II y = search(a, r);
			int total = x + y.second;
			if (total > ret.first) {
				ret = II(total, y.first);
			}
		}
	}
	return ret;
}

int solve(int N, int K, std::vector<int> A) {
	II ret = search(A, N);
	return ret.first;
}

int main() {
	int N, K;
	std::cin >> N >> K;
	std::vector<int> A(K);
	for (int i = 0; i < K; i++) {
		std::cin >> A[i];
	}
	cout << solve(N, K, A) << endl;
	return 0;
}
