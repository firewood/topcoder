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

int64_t solve(int64_t N, std::vector<int64_t> A) {
	vector<pair<int64_t, int64_t>> v;
	for (int i = 0; i < N; ++i) {
		v.emplace_back(make_pair(A[i], i));
	}
	sort(v.begin(), v.end());
	return v[N - 2].second + 1;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	cout << solve(N, A) << endl;
	return 0;
}
