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

int64_t solve(int64_t A, int64_t B, int64_t C) {
	vector< int64_t> v = { A, B, C };
	sort(v.begin(), v.end());
	int64_t b = v[2] - v[0];
	v[1] -= b;
	v[2] -= b;
	int64_t a = v[2] - v[1];
	v[0] -= a;
	v[2] -= a;
	if (a >= 0 && b >= 0 && v[0] >= 0 && v[0] == v[1] && v[1] == v[2] && v[2] == v[0]) {
		return a + b + v[0];
	}
	return -1;
}

int main() {
	int64_t A, B, C;
	std::cin >> A >> B >> C;
	cout << solve(A, B, C) << endl;
	return 0;
}
