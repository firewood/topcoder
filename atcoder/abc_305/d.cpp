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

int main() {
	int64_t N, Q, l, r, sum = 0;
	cin >> N;
	std::vector<int64_t> A(N);
	map<int64_t, pair<int64_t, int64_t>> m;
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
		if (i > 0 && (i % 2) == 0) {
			sum += A[i] - A[i - 1];
		}
		m[A[i]] = { i, sum };
	}

	auto calc = [&](int64_t t) {
		auto p = m.lower_bound(t);
		if (p->first > t) {
			--p;
		}
		int64_t sum = p->second.second;
		if (p->second.first % 2) {
			sum += t - p->first;
		}
		return sum;
	};

	cin >> Q;
	for (int tt = 0; tt < Q; ++tt) {
		cin >> l >> r;
		cout << calc(r) - calc(l) << endl;
	}
	return 0;
}
