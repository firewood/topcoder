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

bool solve(int64_t a, int64_t b) {
	return a + 1 == b || a == 1 && b == 10;
}

int main() {
	int64_t a, b;
	std::cin >> a >> b;
	cout << (solve(a, b) ? "Yes" : "No") << endl;
	return 0;
}
