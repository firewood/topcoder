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

int solve(int n, std::vector<int> p) {
	int ans = 1 << 30;
	int ap = find(p.begin(), p.end(), 0) - p.begin();
	int bp = find(p.begin(), p.end(), 1) - p.begin();
	if ((ap + 1) % n == bp) {
		ans = min({ ans, ap, n - ap + 2 });
	}
	if (ap == (bp + 1) % n) {
		ans = min({ ans, ap + 2, n - ap });
	}
	return ans;
}

int main() {
	int n;
	std::cin >> n;
	std::vector<int> p(n);
	for (int i = 0; i < n; i++) {
		std::cin >> p[i];
		--p[i];
	}
	cout << solve(n, p) << endl;
	return 0;
}
