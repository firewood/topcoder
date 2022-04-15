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

void solve(int64_t N, int64_t A, int64_t B, int64_t P, int64_t Q, int64_t R, int64_t S) {
	int64_t aa = max(1 - A, 1 - B), bb = min(N - A, N - B);
	int64_t cc = max(1 - A, B - N), dd = min(N - A, B - 1);
	for (int64_t i = P; i <= Q; ++i) {
		int64_t k1 = i - A;
		for (int64_t j = R; j <= S; ++j) {
			char ch = '.';
			if (k1 == j - B && aa <= k1 && k1 <= bb) {
				ch = '#';
			}
			if (k1 == -j + B && cc <= k1 && k1 <= dd) {
				ch = '#';
			}
			cout << ch;
		}
		cout << endl;
	}
}

int main() {
	int64_t N, A, B, P, Q, R, S;
	std::cin >> N >> A >> B >> P >> Q >> R >> S;
	solve(N, A, B, P, Q, R, S);
	return 0;
}
