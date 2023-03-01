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

int solve(int M, int N) {
	const int tbl_small[4][6] = {
		{ 0, 0, 0, 0, 0, 0 },
		{ 0, 3, 6, 8, 8, 8 },
		{ 0, 0,18,20,16,16 },
		{ 0, 0, 0,28,16,18 },
	};
	const int tbl_one[4] = { 10,9,8,9 };
	const int tbl_others[4] = { 18,20,18,16 };
	if (M > N) swap(N, M);
	if (N <= 5 && M <= 3) {
		return tbl_small[M][N];
	} else if (M == 1) {
		return tbl_one[N % 4];
	} else {
		return tbl_others[(N + M) % 4];
	}
}

int main() {
	int M, N;
	std::cin >> M >> N;
	cout << solve(M, N) << endl;
	return 0;
}
