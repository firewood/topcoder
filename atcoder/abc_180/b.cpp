#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

typedef long long LL;

void solve(long long N, std::vector<long long>& x) {
	for (int i = 0; i < N; i++) {
		x[i] = abs(x[i]);
	}
	cout << accumulate(x.begin(), x.end(), 0LL) << endl;
	LL sum = accumulate(x.begin(), x.end(), 0LL, [](LL sum, LL x) { return sum + x * x; });
	cout << sqrt(sum) << endl;
	cout << accumulate(x.begin(), x.end(), 0LL, [](LL acc, LL x) { return max(acc, x); }) << endl;
}

int main() {
	cout.precision(20);
	long long N;
	std::cin >> N;
	std::vector<long long> x(N);
	for (int i = 0; i < N; i++) {
		std::cin >> x[i];
	}
	solve(N, x);
	return 0;
}
