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

typedef pair<int64_t, int64_t> II;

int64_t gcd(int64_t a, int64_t b) { return b ? gcd(b, a % b) : a; }
int64_t lcm(int64_t a, int64_t b) { return (a / gcd(a, b)) * b; }

int64_t solve(int64_t N, std::vector<int64_t> x, std::vector<int64_t> y) {
    set<II> s;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == j) continue;
            int64_t a = x[j] - x[i], b = y[j] - y[i];
            int64_t g = gcd(abs(a), abs(b));
            s.insert(II(a / g, b / g));
        }
    }
    return s.size();
}

int main() {
#if DEBUG || _DEBUG
	freopen("in_1.txt", "r", stdin);
#endif
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> x(N), y(N);
	for (int i = 0; i < N; i++) {
		std::cin >> x[i] >> y[i];
	}
	cout << solve(N, x, y) << endl;
	return 0;
}
