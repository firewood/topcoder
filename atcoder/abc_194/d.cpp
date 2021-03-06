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

long double solve(int N) {
	long double ans = 0;
	for (int i = 1; i <= N; ++i) {
		ans += 1.0 / i;
	}
	return ans * N - 1.0;
}

int main() {
	cout.precision(20);
    int N;
	std::cin >> N;
	cout << solve(N) << endl;
	return 0;
}
