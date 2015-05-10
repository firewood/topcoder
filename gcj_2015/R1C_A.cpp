// Google Code Jam 2015 R1C
// Problem A. Brattleship

#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

typedef long long LL;

int solve(int R, int C, int W) {
	int cnt = 0;
	if (R > 1) {
		cnt += (R - 1) * (C / W);
	}
	while (C >= W * 2) {
		++cnt;
		C -= W;
	}
	return cnt + W + (C > W);
}

int main(int argc, char *argv[]) {
	string s;
	getline(cin, s);
	LL T = atoi(s.c_str());
	for (LL t = 1; t <= T; ++t) {
		getline(cin, s);
		stringstream ss(s);
		int R, C, W;
		ss >> R >> C >> W;
		cout << "Case #" << t << ": " << solve(R, C, W) << endl;
	}
	return 0;
}
