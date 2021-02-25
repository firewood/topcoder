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
typedef long double LD;
typedef pair<LL, LL> II;
typedef pair<LL, II> III;

static const LL INF = 1LL << 60;

double solve(long long N) {
	return (N + 1) * 10000 * 0.5;
}

int main() {
	cout.precision(20);
    long long N;
	std::cin >> N;
	cout << solve(N) << endl;
	return 0;
}
