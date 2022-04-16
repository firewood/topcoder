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

void solve(int64_t N) {
	if (N > 1) {
		solve(N - 1);
	}
	cout << " " << N;
	if (N > 1) {
		solve(N - 1);
	}
}

int main() {
	int64_t N;
	std::cin >> N;
	solve(N);
	return 0;
}
