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

string solve(int64_t A, int64_t B, int64_t K) {
	static const int COMBSZ = 64;
	int64_t C[COMBSZ][COMBSZ] = { 1 };
	for (int i = 1; i < COMBSZ; ++i) {
		C[i][0] = 1;
		for (int j = 1; j <= i; ++j) {
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
	}
	--K;
	string ans;
	while (A > 0 || B > 0) {
		bool a = A > 0;
		if (B > 0 && K + C[A + B - 1][B - 1] >= C[A + B][B]) {
			K -= (C[A + B][B] - C[A + B - 1][B - 1]);
			a = false;
		}
		ans += a ? 'a' : 'b';
		A -= a;
		B -= !a;
	}
	return ans;
}

int main() {
	int64_t A, B, K;
	std::cin >> A >> B >> K;
	cout << solve(A, B, K) << endl;
	return 0;
}
