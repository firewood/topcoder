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

string solve(int64_t A, int64_t B, int64_t C) {
	if (C % 2 == 0) {
		A = abs(A);
		B = abs(B);
	}
	if (A < 0 && B >= 0) return "<";
	if (A >= 0 && B < 0) return ">";
	if (A == B) return "=";
	return A < B ? "<" : ">";
}

int main() {
#if DEBUG || _DEBUG
	freopen("in.txt", "r", stdin);
	//	freopen("in_1.txt", "r", stdin);
#endif
	int64_t A, B, C;
	std::cin >> A >> B >> C;
	cout << solve(A, B, C) << endl;
	return 0;
}
