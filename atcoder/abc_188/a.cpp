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

bool solve(long long X, long long Y) {
	return abs(X - Y) <= 2;
}

int main() {
    long long X, Y;
	std::cin >> X >> Y;
	cout << (solve(X, Y) ? "Yes" : "No") << endl;
	return 0;
}
