#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif

#include <algorithm>
#include <cstring>
#include <iostream>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

int b[2][3];
int c[3][2];
map<string, int> memo;

int dfs(string state, bool maximize) {
	if (memo.find(state) != memo.end()) {
		return memo[state];
	}
	int r = 0;
	if (state.find(' ') == string::npos) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i < 2 && state[i * 3 + j] == state[(i + 1) * 3 + j]) {
					r += b[i][j];
				}
				if (j < 2 && state[i * 3 + j] == state[i * 3 + j + 1]) {
					r += c[i][j];
				}
			}
		}
	} else {
		r = maximize ? 0 : (1 << 30);
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (state[i * 3 + j] == ' ') {
					state[i * 3 + j] = maximize ? 'o' : 'x';
					int sub = dfs(state, !maximize);
					state[i * 3 + j] = ' ';
					r = maximize ? max(r, sub) : min(r, sub);
				}
			}
		}
	}
	memo[state] = r;
	return r;
}

int main() {
	int sum = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> b[i][j];
			sum += b[i][j];
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> c[i][j];
			sum += c[i][j];
		}
	}
	int ans = dfs("         ", true);
	cout << ans << endl;
	cout << (sum - ans) << endl;
	return 0;
}
