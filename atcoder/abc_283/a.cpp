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

int64_t solve(int64_t A, int64_t B) {
	return pow(A, B);
}

int main() {
	int64_t A, B;
	std::cin >> A >> B;
	cout << solve(A, B) << endl;
	return 0;
}
