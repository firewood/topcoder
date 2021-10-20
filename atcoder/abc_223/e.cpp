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

bool solve2(int64_t X, int64_t Y, int64_t A, int64_t B, int64_t C) {
	int64_t a = ((A + Y - 1) / Y);
	int64_t b = ((B + Y - 1) / Y);
	int64_t c = ((C + Y - 1) / Y);
	if ((a + b + c) <= X) {
		return true;
	}
	int64_t x = X - a;
	if (x > 0) {
		int64_t b = ((B + x - 1) / x);
		int64_t c = ((C + x - 1) / x);
		if ((b + c) <= Y) {
			return true;
		}
	}
	return false;
}

bool solve1(int64_t X, int64_t Y, int64_t A, int64_t B, int64_t C) {
	vector<int64_t> seq = { A, B, C };
	sort(seq.begin(), seq.end());
	do {
		if (solve2(X, Y, seq[0], seq[1], seq[2])) {
			return true;
		}
	} while (next_permutation(seq.begin(), seq.end()));
	return false;
}

bool solve(int64_t X, int64_t Y, int64_t A, int64_t B, int64_t C) {
	if (solve1(X, Y, A, B, C)) {
		return true;
	}
	if (solve1(Y, X, A, B, C)) {
		return true;
	}
	return false;
}

int main() {
	int64_t X, Y, A, B, C;
	std::cin >> X >> Y >> A >> B >> C;
	cout << (solve(X, Y, A, B, C) ? "Yes" : "No") << endl;
	return 0;
}
