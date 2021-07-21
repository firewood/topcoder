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

int64_t solve(int N, std::vector<int> a) {
	map<int, int> m;
	for (int i = 0; i < 1 << N; ++i) {
		m[a[i]] = i;
	}
	while (a.size() > 2) {
		vector<int> next;
		for (int i = 0; i < a.size(); i += 2) {
			next.emplace_back(max(a[i], a[i + 1]));
		}
		a = next;
	}
	return m[min(a[0], a[1])] + 1;
}

int main() {
	int N;
	std::cin >> N;
	std::vector<int> A(1 << N);
	for (int i = 0; i < 1 << N; i++) {
		std::cin >> A[i];
	}
	cout << solve(N, A) << endl;
	return 0;
}
