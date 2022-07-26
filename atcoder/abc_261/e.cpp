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

vector<int> solve(int N, int C, std::vector<int> T, std::vector<int> A) {
	vector<int> ans;
	int zero = 0, one = (1 << 30) - 1;
	for (int i = 0; i < N; ++i) {
		switch (T[i]) {
		case 1:
			zero &= A[i];
			one &= A[i];
			break;
		case 2:
			zero |= A[i];
			one |= A[i];
			break;
		case 3:
			zero ^= A[i];
			one ^= A[i];
			break;
		}
		C = (~C & zero) | (C & one);
		ans.emplace_back(C);
	}
	return ans;
}

int main() {
	int N, C;
	std::cin >> N >> C;
	std::vector<int> T(N), A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> T[i] >> A[i];
	}
	vector<int> ans = solve(N, C, T, A);
	for (auto x : ans) {
		cout << x << endl;
	}
	return 0;
}
