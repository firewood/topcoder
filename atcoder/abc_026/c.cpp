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

int64_t solve(int64_t N, std::vector<int64_t> B) {
	vector<vector<int>> s(N);
	for (int i = N - 1; i >= 0; --i) {
		const vector<int>& a = s[i];
		int salary = 1;
		if (!a.empty()) {
			salary += *min_element(a.begin(), a.end()) + *max_element(a.begin(), a.end());
		}
		if (i == 0) {
			return salary;
		} else {
			s[B[i - 1]].emplace_back(salary);
		}
	}
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> B(N-2+1);
	for (int i = 0; i < N - 1; i++) {
		std::cin >> B[i];
		--B[i];
	}
	cout << solve(N, B) << endl;
	return 0;
}
