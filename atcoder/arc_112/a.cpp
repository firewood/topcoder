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

int main() {
	LL T, l, r, ans;
	cin >> T;
	for (LL t = 0; t < T; ++t) {
		cin >> l >> r;
		LL d = max(0LL, r - l * 2 + 1);
		ans = d * (d + 1) / 2;
		cout << ans << endl;
	}
	return 0;
}
