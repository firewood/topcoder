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

int solve(int H, int W) {
	if (min(H, W) <= 1) {
		return max(H, W);
	}
	return ((H + 1) / 2) * ((W + 1) / 2);
}

int main() {
	int H, W;
	cin >> H >> W;
	cout << solve(H, W) << endl;
	return 0;
}
