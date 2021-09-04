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

void solve(int L, int Q, std::vector<int> c, std::vector<int> x) {
	set<int> s;
	s.insert(0);
	s.insert(L);
	for (int i = 0; i < Q; ++i) {
		if (c[i] == 1) {
			s.insert(x[i]);
		} else {
			auto p = s.lower_bound(x[i]), q = p;
			cout << *p - *--q << endl;
		}
	}
}

int main() {
	int L, Q;
	std::cin >> L >> Q;
	std::vector<int> c(Q), x(Q);
	for (int i = 0; i < Q; i++) {
		std::cin >> c[i] >> x[i];
	}
	solve(L, Q, c, x);
	return 0;
}
