#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;

typedef long long LL;

bool solve(long long S, long long P) {
	for (LL a = 1; a * a <= P; ++a) {
		LL b = P / a;
		if (a * b == P && a + b == S) {
			return true;
		}
	}
	return false;
}

int main() {
	long long S, P;
	std::cin >> S >> P;
	cout << (solve(S, P) ? "Yes" : "No") << endl;
	return 0;
}
