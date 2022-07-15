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

string solve(int64_t N, int64_t X) {
	return string(1, char('A' + (X - 1) / N));
}

int main() {
	int64_t N, X;
	std::cin >> N >> X;
	cout << solve(N, X) << endl;
	return 0;
}
