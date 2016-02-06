// Google Code Jam 2015 R1C
// Problem C. Less Money, More Problems

#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

typedef vector<int> IntVec;

void fill(int c, int d, int v[]) {
	for (int i = 100; i >= 1; --i) {
		for (int j = 1; j <= c; ++j) {
			int k = j * d;
			if (k > i) {
				break;
			}
			if (v[i - k]) {
				v[i] = 1;
			}
		}
	}
}

int solve(int C, int D, int V, IntVec &c) {
	int v[101] = {};
	v[0] = 1;
	for (int coin : c) {
		fill(C, coin, v);
	}
	int cnt = 0;
	for (int i = 1; i <= V; ++i) {
		if (!v[i]) {
			++cnt;
			fill(C, i, v);
		}
	}
	return cnt;
}

int main(int argc, char *argv[]) {
	string s;
	getline(cin, s);
	int T = atoi(s.c_str());
	for (int t = 1; t <= T; ++t) {
		getline(cin, s);
		stringstream ss(s);
		int C, D, V;
		ss >> C >> D >> V;
		IntVec c(D);
		getline(cin, s);
		stringstream ss2(s);
		for (int i = 0; i < D; ++i) {
			ss2 >> c[i];
		}
		cout << "Case #" << t << ": " << solve(C, D, V, c) << endl;
	}
	return 0;
}
