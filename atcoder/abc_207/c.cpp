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

int main() {
	int64_t N, ans = 0;
	cin >> N;
	std::vector<int64_t> T(N), L(N), R(N);
	for (int i = 0; i < N; i++) {
		std::cin >> T[i] >> L[i] >> R[i];
		L[i] *= 2;
		R[i] *= 2;
		if (T[i] >= 3) {
			++L[i];
		}
		if (T[i] == 2 || T[i] == 4) {
			--R[i];
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			ans += L[i] <= L[j] && R[i] >= L[j] || L[j] <= L[i] && R[j] >= L[i];
		}
	}
	cout << ans << endl;
	return 0;
}
