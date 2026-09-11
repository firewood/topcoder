#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int64_t, int64_t> II;

int64_t solve(int64_t N, vector<int64_t> A, vector<int64_t> B) {
	int64_t sum = accumulate(A.begin(), A.end(), int64_t(0));
	int64_t ans = sum, min_p = *min_element(A.begin(), A.end());

	vector<II> v;
	for (int i = 0; i < N; ++i) {
		v.emplace_back(II(A[i] - B[i], i));
	}
	sort(v.rbegin(), v.rend());

	for (int vi = 0; vi < N; ++vi) {
		int64_t i = v[vi].second, needs_to_buy = max(int64_t(0), vi + 1 - (N - (vi + 1)));
		sum -= A[i];
		sum += B[i];
		ans = min(ans, sum + needs_to_buy * min_p);
	}

	return ans;
}

void process_case() {
	int64_t N;
	cin >> N;
	vector<int64_t> A(N), B(N);
	for (int64_t i = 0; i < N; ++i) {
		cin >> A[i] >> B[i];
	}
	auto ans = solve(N, A, B);
	cout << ans << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		process_case();
	}
}
