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
#include <atcoder/modint>

using namespace std;

using mint = atcoder::modint998244353;

mint solve(int64_t N, string sa, string sb) {
	for (int i = 0; i < N; ++i) {
		if (sa[i] > sb[i]) {
			swap(sa[i], sb[i]);
		}
	}
	mint a = 0, b = 0;
	for (int i = 0; i < N; ++i) {
		a = a * 10 + sa[i] - '0';
		b = b * 10 + sb[i] - '0';
	}
	return a * b;
}

int main() {
	int64_t N;
	string A, B;
	std::cin >> N >> A >> B;
	cout << solve(N, A, B).val() << endl;
	return 0;
}
