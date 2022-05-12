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

const int64_t INF = 1LL << 62;

int64_t get_area(const vector<int64_t>& X, const vector<int64_t>& Y, int a, int b, int c) {
	return abs((X[a] - X[c]) * (Y[b] - Y[c]) - (X[b] - X[c]) * (Y[a] - Y[c]));
}

int64_t solve(int64_t N, std::vector<int64_t> X, std::vector<int64_t> Y) {
	int64_t ans = INF, total = 0, sum = 0;
	for (int i = 2; i < N; ++i) {
		total += get_area(X, Y, 0, i - 1, i);
	}
	for (int left = 0, right = 1, tt = 0; tt < N * 2; ++tt) {
		int next = (right + 1) % N;
		sum += get_area(X, Y, left, right, next) * 4;
		ans = min(ans, abs(total - sum));
		right = next;
		while (sum > total) {
			next = (left + 1) % N;
			int64_t area = get_area(X, Y, left, next, right) * 4;
			if (sum <= area) {
				break;
			}
			sum -= area;
			ans = min(ans, abs(total - sum));
			left = next;
		}
	}
	return ans;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> X(N), Y(N);
	for (int i = 0; i < N; i++) {
		std::cin >> X[i] >> Y[i];
	}
	cout << solve(N, X, Y) << endl;
	return 0;
}
