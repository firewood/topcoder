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

int64_t solve(int N, std::vector<int> A) {
	int64_t ans = 0;
	map<int, int> m;
	for (int i = 0; i < N; ++i) {
		m[A[i]] += 1;
	}
	while (m.size() > 1) {
		++ans;
		int low = m.begin()->first, high = m.rbegin()->first;
		m[high] -= 1;
		if (m[high] <= 0) {
			m.erase(high);
		}
		high %= low;
		if (high > 0) {
			m[high] += 1;
		}
	}
	ans += m.begin()->second - 1;
	return ans;
}

int main() {
	int N;
	std::cin >> N;
	std::vector<int> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	cout << solve(N, A) << endl;
	return 0;
}
