#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif

#include <algorithm>
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

void solve(int N, std::string s) {
	int ans = N;
	char cmds[] = { 'A', 'B', 'X', 'Y' };
	for (int a = 0; a < 4; ++a) {
		for (int b = 0; b < 4; ++b) {
			for (int c = 0; c < 4; ++c) {
				for (int d = 0; d < 4; ++d) {
					int r = N;
					int prev = -1;
					for (char x : s) {
						if (prev == cmds[a] && x == cmds[b] || prev == cmds[c] && x == cmds[d]) {
							--r;
							prev = 0;
						} else {
							prev = x;
						}
					}
					ans = min(ans, r);
				}
			}
		}
	}
	cout << ans << endl;
}

int main() {
    int N;
	std::string s;
	std::cin >> N >> s;
	solve(N, s);
	return 0;
}
