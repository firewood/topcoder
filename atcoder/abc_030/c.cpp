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

int64_t solve(int64_t N, int64_t M, int64_t X, int64_t Y, std::vector<int64_t> a, std::vector<int64_t> b) {
	int64_t ans = 0, p = 0, q = 0, t = 0;
	bool go = true;
	while (true) {
		if (go) {
			while (p < a.size() && t > a[p]) {
				++p;
			}
			if (p >= a.size()) {
				break;
			}
			t = a[p] + X;
		} else {
			while (q < b.size() && t > b[q]) {
				++q;
			}
			if (q >= b.size()) {
				break;
			}
			t = b[q] + Y;
			++ans;
		}
		go = !go;
	}
	return ans;
}

int main() {
	int64_t N, M, X, Y;
	std::cin >> N >> M >> X >> Y;
	std::vector<int64_t> a(N);
	for (int i = 0; i < N; i++) {
		std::cin >> a[i];
	}
	std::vector<int64_t> b(M);
	for (int i = 0; i < M; i++) {
		std::cin >> b[i];
	}
	cout << solve(N, M, X, Y, a, b) << endl;
	return 0;
}
