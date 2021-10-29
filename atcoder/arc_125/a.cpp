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

int solve(int N, int M, std::vector<int> S, std::vector<int> T) {
	int sz = count(S.begin(), S.end(), 0), so = N - sz;
	int tz = count(T.begin(), T.end(), 0), to = M - tz;
	if (tz > 0 && sz == 0 || to > 0 && so == 0) {
		return -1;
	}
	int ans = 0, curr = S[0];
	bool moved = false;
	for (int i = 0; i < M; ++i) {
		if (curr == T[i]) {
			++ans;
		} else if (moved) {
			ans += 2;
			curr = !curr;
		} else {
			int pos = int(find(S.begin(), S.end(), !curr) - S.begin());
			int rpos = int(find(S.rbegin(), S.rend(), !curr) - S.rbegin() + 1);
			curr = !curr;
			ans += min(pos, rpos) + 1;
			moved = true;
		}
	}
	return ans;
}

int main() {
	int N, M;
	std::cin >> N >> M;
	std::vector<int> S(N);
	for (int i = 0; i < N; i++) {
		std::cin >> S[i];
	}
	std::vector<int> T(M);
	for (int i = 0; i < M; i++) {
		std::cin >> T[i];
	}
	cout << solve(N, M, S, T) << endl;
	return 0;
}
