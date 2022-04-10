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

pair<int64_t, int64_t> solve(int64_t N, std::vector<int64_t> A) {
	vector<pair<int64_t, int64_t>> v;
	for (int i = 0; i < N; ++i) {
		v.emplace_back(make_pair(A[i], i));
	}
	sort(v.begin(), v.end());
	vector<int> val(N), sum(N + 1);
	for (int i = 0; i < N; ++i) {
		val[v[i].second] = i < N / 2 ? 1 : -1;
	}
	for (int i = 0; i < N; ++i) {
		sum[i + 1] = sum[i] + val[i];
	}
	sort(A.begin(), A.end());
	return make_pair(min_element(sum.begin(), sum.end()) - sum.begin(), accumulate(A.begin() + N / 2, A.end(), int64_t(0)));
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	auto ans = solve(N, A);
	cout << ans.first << " " << ans.second << endl;
	return 0;
}
