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

string solve(int64_t N, int64_t Q, std::vector<int64_t> l, std::vector<int64_t> r) {
	vector<int> q(N + 1);
	for (int i = 0; i < Q; ++i) {
		q[l[i]] += 1;
		q[r[i] + 1] += 1;
	}
	string ans;
	int sum = 0;
	for (int i = 0; i < N; ++i) {
		sum += q[i];
		ans += char('0' + (sum % 2));
	}
	return ans;
}

int main() {
	int64_t N, Q;
	std::cin >> N >> Q;
	std::vector<int64_t> l(Q), r(Q);
	for (int i = 0; i < Q; i++) {
		std::cin >> l[i] >> r[i];
		--l[i];
		--r[i];
	}
	cout << solve(N, Q, l, r) << endl;
	return 0;
}
