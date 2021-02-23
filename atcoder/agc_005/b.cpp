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

LL solve(int N, std::vector<long long> &a) {
	LL ans = 0;
	vector<int> order(N + 1);
	for (int i = 0; i < N; i++) {
		order[a[i]] = i;
	}
	set<int> s;
	s.insert(-1);
	s.insert(N);
	for (LL i = 1; i <= N; i++) {
		auto it = s.lower_bound(order[i]);
		LL right = *it;
		--it;
		LL left = *it;
		LL a = order[i] - left - 1;
		LL b = right - order[i] - 1;
		LL d = right - left - 1;
		ans += i * (d * (d + 1) - a * (a + 1) - b * (b + 1)) / 2;
		s.insert(order[i]);
	}
	return ans;
}

int main() {
    int N;
	std::cin >> N;
	std::vector<long long> a(N);
	for (int i = 0; i < N; i++) {
		std::cin >> a[i];
	}
	cout << solve(N, a) << endl;
	return 0;
}
