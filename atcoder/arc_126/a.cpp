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

int64_t solve(int64_t a, int64_t b, int64_t c) {
	int64_t ans = 0, d = min(b / 2, c);
	ans += d;
	b -= d * 2, c -= d;
	d = min(a / 2, b / 2);
	ans += d;
	a -= d * 2, b -= d * 2;
	d = min(a, c / 2);
	ans += d;
	a -= d, c -= d * 2;
	d = min(a / 3, c);
	ans += d;
	a -= d * 3, c -= d;
	ans += a / 5;
	return ans;
}

int main() {
	int64_t T, a, b, c;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> a >> b >> c;
		cout << solve(a, b, c) << endl;
	}
	return 0;
}
