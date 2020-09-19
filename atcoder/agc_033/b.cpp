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

typedef long long LL;

void solve(long long H, long long W, long long N, long long s_r, long long s_c, std::string S, std::string T) {
	bool ans = true;
	map<int, int> char_to_index;
	char_to_index['L'] = 0;
	char_to_index['R'] = 1;
	char_to_index['U'] = 2;
	char_to_index['D'] = 3;
	LL pos[4] = { s_c - 1, W - s_c, s_r - 1, H - s_r };
	LL max_pos[4] = { W - 1, W - 1, H - 1, H - 1 };
	for (LL i = 0; i < N; ++i) {
		if (--pos[char_to_index[S[i]]] < 0) {
			ans = false;
			break;
		}
		LL index = char_to_index[T[i]] ^ 1;
		pos[index] = min(max_pos[index], pos[index] + 1);
	}
	cout << (ans ? "YES" : "NO") << endl;
}

int main() {
	long long H, W, N, s_r, s_c;
	std::string S, T;
	std::cin >> H >> W >> N >> s_r >> s_c;
	std::cin >> S >> T;
	solve(H, W, N, s_r, s_c, S, T);
	return 0;
}
