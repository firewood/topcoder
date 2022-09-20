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

void solve(int64_t X) {
	vector<int64_t> bits;
	for (int i = 0; i < 60; ++i) {
		if ((1LL << i) & X) {
			bits.emplace_back(1LL << i);
		}
	}
	for (int i = 0; i < (1 << bits.size()); ++i) {
		int64_t x = 0;
		for (int j = 0; j < bits.size(); ++j) {
			if (i & (1 << j)) {
				x |= bits[j];
			}
		}
		cout << x << endl;
	}
}

int main() {
	int64_t X;
	std::cin >> X;
	solve(X);
	return 0;
}
