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

bool solve(int64_t a, int64_t s) {
	s -= a * 2;
	return s >= 0 && (s & ~a) == s;
}

int main() {
	int64_t T, a, s;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> a >> s;
		cout << (solve(a, s) ? "Yes" : "No") << endl;
	}
	return 0;
}
