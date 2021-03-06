//
// Facebook Hacker Cup 2015 Qualification Round
// B. New Year's Resolution
//

#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <set>

using namespace std;

typedef pair<int, int> II;
typedef pair<int, II> III;
typedef vector<int> IntVec;
typedef set<III> IIISet;

bool solve(int gp, int gc, int gf, IntVec &pv, IntVec &cv, IntVec &fv)
{
	int N = (int)pv.size();
	int a = N / 2;
	int M = 1 << a;
	IIISet s;
	for (int b = 1; b < M; ++b) {
		int p = 0, c = 0, f = 0;
		for (int i = 0; i < a; ++i) {
			if (b & (1 << i)) {
				p += pv[i], c += cv[i], f += fv[i];
			}
		}
		if (gp == p && gc == c && gf == f) {
			return true;
		}
		s.insert(III(p, II(c, f)));
	}
	int r = N - a;
	M = 1 << r;
	for (int b = 1; b < M; ++b) {
		int p = 0, c = 0, f = 0;
		for (int i = 0; i < r; ++i) {
			if (b & (1 << i)) {
				p += pv[a + i], c += cv[a + i], f += fv[a + i];
			}
		}
		if (gp == p && gc == c && gf == f) {
			return true;
		}
		if (p < gp && c < gc && f < gf) {
			if (s.find(III(gp - p, II(gc - c, gf - f))) != s.end()) {
				return true;
			}
		}
	}
	return false;
}

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	int T = atoi(s.c_str());
	for (int t = 0; t < T; ++t) {
		getline(cin, s);
		stringstream ss(s);
		int gp, gc, gf;
		ss >> gp >> gc >> gf;
		getline(cin, s);
		int N = atoi(s.c_str());
		IntVec pv(N), cv(N), fv(N);
		for (int i = 0; i < N; ++i) {
			getline(cin, s);
			stringstream ss(s);
			ss >> pv[i] >> cv[i] >> fv[i];
		}
		cout << "Case #" << (t + 1) << ": " << (solve(gp, gc, gf, pv, cv, fv) ? "yes" : "no") << endl;
	}
	return 0;
}
