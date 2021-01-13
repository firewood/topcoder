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

int solve(int N, int P, std::vector<int> &a, std::vector<int> &b) {
	vector<int> vi(N);
	iota(vi.begin(), vi.end(), 0);
	sort(vi.begin(), vi.end(), [&](int lhs, int rhs) {
		return a[lhs] > a[rhs];
	});
	vector<int> v(5101);
	for (int i = 0; i < N; ++i) {
		int k = vi[i];
		for (int j = P; j >= 0; --j) {
			if (v[j] + b[k] > v[j + a[k]]) {
				v[j + a[k]] = v[j] + b[k];
			}
		}
	}
	return *max_element(v.begin(), v.end());
}

int main() {
	int N, P;
	std::cin >> N >> P;
	std::vector<int> a(N), b(N);
	for (int i = 0; i < N; i++) {
		std::cin >> a[i] >> b[i];
	}
	cout << solve(N, P, a, b) << endl;
	return 0;
}
