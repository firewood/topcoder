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

bool solve(int64_t N, int64_t K, std::vector<int64_t> a) {
	vector< int64_t> x(N);
	for (int i = 0; i < K; ++i) {
		vector< int64_t> b;
		for (int j = i; j < N; j += K) {
			b.emplace_back(a[j]);
		}
		sort(b.begin(), b.end());
		for (int j = i, k = 0; j < N; j += K, ++k) {
			x[j] = b[k];
		}
	}
	sort(a.begin(), a.end());
	return a == x;
}

int main() {
	int64_t N, K;
	std::cin >> N >> K;
	std::vector<int64_t> a(N);
	for (int i = 0; i < N; i++) {
		std::cin >> a[i];
	}
	cout << (solve(N, K, a) ? "Yes" : "No") << endl;
	return 0;
}
