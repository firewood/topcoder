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

int64_t solve(int64_t N, int64_t K, int64_t A) {
	return ((A + K - 2) % N) + 1;
}

int main() {
	int64_t N, K, A;
	std::cin >> N >> K >> A;
	cout << solve(N, K, A) << endl;
	return 0;
}
