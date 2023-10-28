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

int N;
string R, C;

bool check(int r, vector<string>& b) {
	if (r >= N) {
		for (int j = 0; j < N; ++j) {
			int cnt[3] = {};
			for (int i = 0; i < N; ++i) {
				if (b[i][j] != '.') {
					cnt[b[i][j] - 'A'] += 1;
				}
			}
			if (!(cnt[0] == 1 && cnt[1] == 1 && cnt[2] == 1)) {
				return false;
			}
		}
		return true;
	}
	auto check_c = [&](int c) {
		for (int y = 0; y <= r; ++y) {
			if (b[y][c] != '.') {
				return b[y][c] == C[c];
			}
		}
		return false;
	};
	for (int i = 0; i < N; ++i) {
		b[r][i] = R[r];
		if (check_c(i)) {
			for (int j = i + 1; j < N; ++j) {
				for (char jc = 'A'; jc <= 'C'; ++jc) {
					if (b[r][i] == jc) continue;
					b[r][j] = jc;
					if (check_c(j)) {
						for (int k = j + 1; k < N; ++k) {
							for (char kc = 'A'; kc <= 'C'; ++kc) {
								if (b[r][i] == kc || jc == kc) continue;
								b[r][k] = kc;
								if (check_c(k)) {
									if (check(r + 1, b)) {
										return true;
									}
								}
							}
							b[r][k] = '.';
						}
					}
				}
				b[r][j] = '.';
			}
		}
		b[r][i] = '.';
	}
	return false;
}

int main() {
	std::cin >> N >> R >> C;
	vector<string> b(N, string(N, '.'));
	bool ans = check(0, b);
	cout << (ans ? "Yes" : "No") << endl;
	if (ans) {
		for (auto s : b) {
			cout << s << endl;
		}
	}
	return 0;
}
