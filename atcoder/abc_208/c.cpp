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

void solve(int64_t N, int64_t K, std::vector<int64_t> a) {
	vector<int64_t> sorted = a;
	sort(sorted.begin(), sorted.end());
	int64_t c = K / N, r = K % N;
	for (int i = 0; i < N; ++i) {
		cout << (c + (a[i] < sorted[r])) << endl;
	}
}

int main() {
#if DEBUG || _DEBUG
	freopen("in.txt", "r", stdin);
	//	freopen("in_1.txt", "r", stdin);
#endif
	int64_t N, K;
	std::cin >> N >> K;
	std::vector<int64_t> a(N);
	for (int i = 0; i < N; i++) {
		std::cin >> a[i];
	}
	solve(N, K, std::move(a));
	return 0;
}
