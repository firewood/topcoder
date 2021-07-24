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

#ifdef __GNUC__
#define popcount __builtin_popcountll
#elif _MSC_VER >= 1400
#include <intrin.h>
#define popcount __popcnt64
#else
static inline int popcount(unsigned long long b) {
	b = (b & 0x5555555555555555LL) + (b >> 1 & 0x5555555555555555LL);
	b = (b & 0x3333333333333333LL) + (b >> 2 & 0x3333333333333333LL);
	b = (b & 0x0f0f0f0f0f0f0f0fLL) + (b >> 4 & 0x0f0f0f0f0f0f0f0fLL);
	b += b >> 8;
	b += b >> 16;
	return (int)((b + (b >> 32)) & 0x7F);
}
#endif

const int dy[4] = { 0, -1, 0, 1 };
const int dx[4] = { -1, 0, 1, 0 };
set<int64_t> memo;

int dfs(int N, int K, int64_t state, const std::vector<std::string> &S) {
	memo.insert(state);
	if (popcount(state) == K) {
		return 1;
	}
	auto check = [&](int r, int c) {
		for (int dir = 0; dir < 4; ++dir) {
			int ny = r + dy[dir], nx = c + dx[dir];
			if (ny >= 0 && ny < N && nx >= 0 && nx < N && ((1LL << (ny * N + nx)) & state) != 0) {
				return true;
			}
		}
		return false;
	};
	int total = 0;
	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < N; ++c) {
			if (S[r][c] != '.') continue;
			int64_t next_state = state | (1LL << (r * N + c));
			if (state != next_state && memo.find(next_state) == memo.end() && check(r, c)) {
				total += dfs(N, K, next_state, S);
			}
		}
	}
	return total;
}

int solve(int N, int K, const std::vector<std::string> &S) {
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (S[i][j] == '.') {
				ans += dfs(N, K, 1LL << (i * N + j), S);
			}
		}
	}
	return ans;
}

int main() {
#if DEBUG || _DEBUG
	freopen("in.txt", "r", stdin);
//	freopen("in_1.txt", "r", stdin);
#endif
	int N, K;
	std::cin >> N >> K;
	std::vector<std::string> S(N);
	for (int i = 0; i < N; i++) {
		std::cin >> S[i];
	}
	cout << solve(N, K, S) << endl;
	return 0;
}
