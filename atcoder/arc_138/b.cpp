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

bool check(int st, int ed, int state, const vector<int>& v) {
	if (st >= ed) {
		return true;
	}
	if ((v[ed - 1] ^ state) == 0) {
		return check(st, ed - 1, state, v);
	}
	if ((v[st] ^ state) != 0) {
		return false;
	}
	return check(st + 1, ed, !state, v);
}

bool solve(int64_t N, std::vector<int> A) {
	return check(0, N, 0, A);
}

int main() {
	int N;
	std::cin >> N;
	std::vector<int> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	cout << (solve(N, A) ? "Yes" : "No") << endl;
	return 0;
}
