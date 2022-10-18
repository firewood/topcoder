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
	vector<int> ans(N);
	map<int, int> m;
	for (int i = 0; i < N; ++i) {
		m[A[i]] += 1;
	}
	int index = 0;
	for (auto it = m.rbegin(); it != m.rend(); ++it) {
		ans[index++] = it->second;
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
		cout << ans[i] << endl;
	}
	return 0;
}
