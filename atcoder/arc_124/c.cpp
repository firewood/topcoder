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

int64_t gcd(int64_t a, int64_t b) { return b ? gcd(b, a % b) : a; }
int64_t lcm(int64_t a, int64_t b) { return (a / gcd(a, b)) * b; }

int64_t solve(int64_t N, std::vector<int64_t> a, std::vector<int64_t> b) {
	int64_t ans = 0;
	vector<int> seq(N);
	iota(seq.begin(), seq.end(), 0);
	for (int t = 0; t < 10000; ++t) {
		random_shuffle(seq.begin(), seq.end());
		int64_t ga = a[seq[0]], gb = b[seq[0]];
		for (int i = 1; i < N; ++i) {
			int64_t aa = gcd(ga, a[seq[i]]), bb = gcd(gb, b[seq[i]]);
			int64_t cc = gcd(ga, b[seq[i]]), dd = gcd(gb, a[seq[i]]);
			if (lcm(aa, bb) >= lcm(cc, dd)) {
				ga = aa;
				gb = bb;
			} else {
				ga = cc;
				gb = dd;
			}
		}
		ans = max(ans, lcm(ga, gb));
	}
	return ans;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> a(N), b(N);
	for (int i = 0; i < N; i++) {
		std::cin >> a[i] >> b[i];
	}
	cout << solve(N, a, b) << endl;
	return 0;
}
