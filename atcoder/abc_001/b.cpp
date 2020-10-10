#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif

#include <algorithm>
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
	long long m, vv = 0;
	std::cin >> m;
	if (m > 70000) {
		vv = 89;
	} else if (m >= 35000) {
		vv = (m / 1000 - 30) / 5 + 80;
	} else if (m >= 6000) {
		vv = m / 1000 + 50;
	} else if (m >= 100) {
		vv = m / 100;
	}
	string ans = "0" + to_string(vv);
	cout << ans.substr(ans.length() - 2, 2) << endl;
	return 0;
}
