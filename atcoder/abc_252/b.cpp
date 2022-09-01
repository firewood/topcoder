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

bool solve(int N, int K, std::vector<int> A, std::vector<int> B) {
	bool ans = false;
	int mx = *max_element(A.begin(), A.end());
	for (auto b : B) {
		if (A[b] == mx) {
			ans = true;
		}
	}
	return ans;
}

int main() {
	int N, K;
	std::cin >> N >> K;
	std::vector<int> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	std::vector<int> B(K);
	for (int i = 0; i < K; i++) {
		std::cin >> B[i];
		--B[i];
	}
	cout << (solve(N, K, A, B) ? "Yes" : "No") << endl;
	return 0;
}
