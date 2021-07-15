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

typedef long long LL;
typedef pair<LL, LL> II;

void solve(long long N, std::vector<long long>& A) {
	LL ans = 0;
	vector<II> v;
	for (LL i = 0; i < N; i++) {
		v.emplace_back(II(A[i], i));
	}
	sort(v.begin(), v.end());
	set<LL> s;
	s.insert(-1);
	s.insert(N);
	for (auto kv : v) {
		LL i = kv.second;
		LL x = kv.first;
		auto next = s.lower_bound(i), prev = next;
		--prev;
		ans = max(ans, (*next - *prev - 1) * x);
		s.insert(i);
	}
	cout << ans << endl;
}

int main() {
	long long N;
	std::cin >> N;
	std::vector<long long> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	solve(N, A);
	return 0;
}
