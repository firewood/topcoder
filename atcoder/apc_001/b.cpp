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

bool solve(int64_t N, std::vector<int64_t> a, std::vector<int64_t> b) {
	int64_t cnt = 0;
	for (int i = 0; i < N; ++i) {
		if (a[i] < b[i]) {
			cnt += (b[i] - a[i]) / 2;
		} else {
			cnt -= a[i] - b[i];
		}
	}
	return cnt >= 0;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> a(N);
	for (int i = 0; i < N; i++) {
		std::cin >> a[i];
	}
	std::vector<int64_t> b(N);
	for (int i = 0; i < N; i++) {
		std::cin >> b[i];
	}
	cout << (solve(N, a, b) ? "Yes" : "No") << endl;
	return 0;
}
