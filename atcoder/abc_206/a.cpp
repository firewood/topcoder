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
typedef pair<int64_t, int64_t> II;
typedef pair<int64_t, II> III;

static const int64_t INF = 1LL << 60;

string solve(int64_t N) {
	int64_t x = (N * 108) / 100;
	if (x < 206) {
		return "Yay!";
	}
	if (x == 206) {
		return "so-so";
	}
	return ":(";
}

int main() {
#if DEBUG || _DEBUG
	freopen("in.txt", "r", stdin);
	//	freopen("in_1.txt", "r", stdin);
#endif
	int64_t N;
	std::cin >> N;
	cout << solve(N) << endl;
	return 0;
}
