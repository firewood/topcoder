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
	vector<int> fact(N + 1);
	for (int i = 1; i <= N; ++i) {
		int x = i, c = 0;
		while ((x % 2) == 0) {
			++c;
			x /= 2;
		}
		fact[i] = fact[i - 1] + c;
	}
	auto get_two_count = [&](int n, int r) {
		return fact[n] - fact[r] - fact[n - r];
	};
	auto is_one = [&]() {
		int r = 0;
		for (int i = 0; i < N; ++i) {
			if (a[i] == 1 && get_two_count(N - 1, i) == 0) {
				r ^= 1;
			}
		}
		return r;
	};
	if (is_one()) {
		return 1;
	}
	for (int i = 0; i < N; ++i) {
		if (a[i] == 1) {
			return 0;
		} else if (a[i] == 2) {
			a[i] = 1;
		}
	}
	return is_one() ? 2 : 0;
}

int main() {
	int N;
	std::cin >> N;
	string s;
	cin >> s;
	std::vector<int> a(N);
	for (int i = 0; i < N; ++i) {
		a[i] = s[i] - '1';
	}
	cout << solve(N, a) << endl;
	return 0;
}
