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

typedef long long LL;

static const LL INF = 1LL << 60;

bool solve(long long A, long long B, long long W) {
	W *= 1000;
	LL low = INF, high = 0;
	for (LL x = 1; x <= 1000000; ++x) {
		if (A * x <= W && W <= B * x) {
			low = min(low, x);
			high = max(high, x);
		}
	}
	if (high <= 0) return false;
	cout << low << " " << high << endl;
	return true;
}

int main() {
	long long A, B, W;
	std::cin >> A >> B >> W;
	if (!solve(A, B, W)) {
		cout << "UNSATISFIABLE" << endl;
	}
	return 0;
}
