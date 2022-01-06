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

typedef long double LD;
typedef pair<int64_t, int64_t> II;
typedef pair<int64_t, II> III;

static const int64_t INF = 1LL << 60;

bool solve(std::vector<std::string> b) {
	const int N = 19;
	auto count_stones = [&](char c) {
		int cnt = 0;
		for (int i = 0; i < N; ++i) {
			cnt += count(b[i].begin(), b[i].end(), c);
		}
		return cnt;
	};
	int blacks = count_stones('o'), whites = count_stones('x');
	if (!(blacks == whites || blacks == whites + 1)) {
		return false;
	}
	if (whites <= 1) {
		return true;
	}
	auto get_max_length = [&](char c) {
		int mx = 0;
		for (int i = 0; i < N; ++i) {
			int cnt = 0;
			for (int j = 0; j < N; ++j) {
				if (b[i][j] == c) {
					++cnt;
					mx = max(mx, cnt);
				} else {
					cnt = 0;
				}
			}
		}
		for (int j = 0; j < N; ++j) {
			int cnt = 0;
			for (int i = 0; i < N; ++i) {
				if (b[i][j] == c) {
					++cnt;
					mx = max(mx, cnt);
				} else {
					cnt = 0;
				}
			}
		}
		for (int k = -N; k <= N * 2; ++k) {
			int cnt = 0, j = k;
			for (int i = 0; i < N; ++i, ++j) {
				if (j >= 0 && j < N) {
					if (b[i][j] == c) {
						++cnt;
						mx = max(mx, cnt);
					} else {
						cnt = 0;
					}
				}
			}
			cnt = 0, j = k;
			for (int i = 0; i < N; ++i, --j) {
				if (j >= 0 && j < N) {
					if (b[i][j] == c) {
						++cnt;
						mx = max(mx, cnt);
					} else {
						cnt = 0;
					}
				}
			}
		}
		return mx;
	};
	char prev = blacks > whites ? 'o' : 'x';
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (b[i][j] == prev) {
				b[i][j] = 0;
				if (get_max_length('o') < 5 && get_max_length('x') < 5) {
					return true;
				}
				b[i][j] = prev;
			}
		}
	}
	return false;
}

int main() {
	std::vector<std::string> b(19);
	for (int i = 0; i < 19; i++) {
		std::cin >> b[i];
	}
	cout << (solve(b) ? "YES" : "NO") << endl;
	return 0;
}
