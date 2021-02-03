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

void solve(long long N) {
	for (LL h = 1; h <= 3500; ++h) {
		for (LL n = 1; n <= 3500; ++n) {
			LL a = N * h * n;
			LL b = 4 * h * n - N * (h + n);
			if (b <= 0) continue;
			LL w = a / b;
			if (a == b * w) {
				cout << h << " " << n << " " << w << endl;
				return;
			}
		}
	}
}

int main() {
    long long N;
	std::cin >> N;
	solve(N);
	return 0;
}
