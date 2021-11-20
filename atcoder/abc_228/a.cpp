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

bool solve(int64_t S, int64_t T, int64_t X) {
	bool sw = false;
	for (int i = 0; i < 48; ++i) {
		if ((i % 24) == S) sw = true;
		if ((i % 24) == T) sw = false;
		if ((i % 24) == X && sw) return true;
	}
	return false;
}

int main() {
	int64_t S, T, X;
	std::cin >> S >> T >> X;
	cout << (solve(S, T, X) ? "Yes" : "No") << endl;
	return 0;
}
