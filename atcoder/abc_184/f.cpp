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
#include <functional>

using namespace std;

typedef long long LL;

LL solve(long long N, long long T, std::vector<long long>& A) {
	LL ans = 0;
	vector<LL> a(1), b(1);
	for (auto x : A) {
		for (LL i = a.size() - 1; i >= 0; --i) {
			a.emplace_back(a[i] + x);
		}
		swap(a, b);
	}
	sort(a.rbegin(), a.rend());
	for (auto x : b) {
		LL r = T - x;
		if (r >= 0) {
			ans = max(ans, x + *lower_bound(a.begin(), a.end(), r, greater<LL>()));
		}
	}
	return ans;
}

int main() {
	long long N;
	std::cin >> N;
	long long T;
	std::cin >> T;
	std::vector<long long> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	cout << solve(N, T, A) << endl;
	return 0;
}
