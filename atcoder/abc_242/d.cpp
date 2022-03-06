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

const string abc = "ABCABC";
string S;

char solve(int64_t t, int64_t k) {
	if (k == 0) {
		return abc[S[0] - 'A' + (t % 3)];
	}
	if (t == 0) {
		return S[k];
	}
	return abc[solve(t - 1, k / 2) - 'A' + 1 + (k % 2)];
}

int main() {
	cin >> S;
	int64_t Q, t, k;
	cin >> Q;
	for (int tt = 0; tt < Q; ++tt) {
		cin >> t >> k;
		cout << solve(t, k - 1) << endl;
	}
	return 0;
}
