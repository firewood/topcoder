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

LD solve(int64_t N, int64_t M, int64_t S, std::vector<int64_t> A) {
	LD ans = 0, r = S;
	int ed = N;
	while (ed > 0) {
		LD sum = 0, mx = 0;
		int mxi = -1;
		for (int i = ed - 1; i >= 0; --i) {
			sum += A[i];
			LD avg = sum / (ed - i);
			if (avg > mx) {
				mx = avg;
				mxi = i;
			}
		}
		LD x = min(LD(M), r / (ed - mxi)) * (ed - mxi);
		r -= x;
		ans += x * mx;
		ed = mxi;
	}
	return ans;
}

int main() {
	cout.precision(20);
	int64_t N, M, S;
	std::cin >> N >> M >> S;
	std::vector<int64_t> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	cout << solve(N, M, S, A) << endl;
	return 0;
}
