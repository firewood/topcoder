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

bool solve(int64_t N, std::vector<int64_t> a, std::vector<int64_t> b) {
	vector<int> cnt(N);
	for (int i = 0; i < a.size(); ++i) {
		cnt[a[i]] += 1;
		cnt[b[i]] += 1;
	}
	return *max_element(cnt.begin(), cnt.end()) == N - 1;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> a(N - 1), b(N - 1);
	for (int i = 0; i < N - 1; i++) {
		std::cin >> a[i] >> b[i];
		--a[i], --b[i];
	}
	cout << (solve(N, a, b) ? "Yes" : "No") << endl;
	return 0;
}
