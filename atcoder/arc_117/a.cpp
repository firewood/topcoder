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
#include <cassert>

using namespace std;

typedef long long LL;

void solve(long long A, long long B) {
	vector<LL> v;
	if (B >= A) {
		for (int i = -B; i <= -1; ++i) {
			v.emplace_back(i);
		}
		for (int i = 1; i <= A; ++i) {
			v.emplace_back(i);
		}
	} else {
		for (int i = 1; i <= A; ++i) {
			v.emplace_back(i);
		}
		for (int i = -B; i <= -1; ++i) {
			v.emplace_back(i);
		}
	}
	v.back() -= accumulate(v.begin(), v.end(), 0LL);

	assert(accumulate(v.begin(), v.end(), 0LL) == 0);

	for (int i = 0; i < v.size(); ++i) {
		if (i) cout << " ";
		cout << v[i];
	}
	cout << endl;
}

int main() {
	long long A, B;
	std::cin >> A >> B;
	solve(A, B);
	return 0;
}
