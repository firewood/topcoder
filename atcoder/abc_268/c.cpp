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

int64_t solve(int64_t N, std::vector<int64_t> p) {
	vector<int> seq(N), cnt(N);
	for (int i = 0; i < N; ++i) {
		seq[p[i]] = i;
	}
	for (int i = 0; i < N; ++i) {
		int pos = seq[i];
		cnt[(i - 1 - pos + N) % N] += 1;
		cnt[(i - pos + N) % N] += 1;
		cnt[(i + 1 - pos + N) % N] += 1;
	}
	return *max_element(cnt.begin(), cnt.end());
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> p(N);
	for (int i = 0; i < N; i++) {
		std::cin >> p[i];
	}
	cout << solve(N, p) << endl;
	return 0;
}
