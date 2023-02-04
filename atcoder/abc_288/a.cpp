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

vector<int> solve(int N, std::vector<int> A, std::vector<int> B) {
	vector<int> ans(N);
	for (int i = 0; i < N; ++i) {
		ans[i] = A[i] + B[i];
	}
	return ans;
}

int main() {
	int N;
	std::cin >> N;
	std::vector<int> A(N), B(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i] >> B[i];
	}
	for (auto x : solve(N, A, B)) {
		cout << x << endl;
	}
	return 0;
}
