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

int solve(int N, std::vector<int> a) {
	int prev = -1;
	vector<int> c2(N), c3(N);
	for (int i = 0; i < N; ++i) {
		int x = a[i];
		while ((x % 2) == 0) {
			x /= 2;
			++c2[i];
		}
		while ((x % 3) == 0) {
			x /= 3;
			++c3[i];
		}
		if (prev < 0) {
			prev = x;
		} else if (prev != x) {
			return -1;
		}
	}
	return accumulate(c2.begin(), c2.end(), 0) - *min_element(c2.begin(), c2.end()) * N
		+ accumulate(c3.begin(), c3.end(), 0) - *min_element(c3.begin(), c3.end()) * N;
}

int main() {
	int N;
	std::cin >> N;
	std::vector<int> a(N);
	for (int i = 0; i < N; i++) {
		std::cin >> a[i];
	}
	cout << solve(N, a) << endl;
	return 0;
}
