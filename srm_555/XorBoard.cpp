// BEGIN CUT HERE
/*
// SRM 555 Div1 Medium (500)

問題
0か1の状態を持つH×Wのセルがある。
行または列の反転操作の回数と、1の個数Sが与えられる。
何通りの操作があるか求める。

*/
// END CUT HERE
#include <cmath>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

#define MOD 555555555
#define COMBSZ 2500

typedef long long LL;

class XorBoard {

public:
	int count(int H, int W, int Rcount, int Ccount, int S) {
		// generate combination table
		static int C[COMBSZ][COMBSZ];
		memset(C, 0, sizeof(C));
		int i, j;
		for (i = 0; i < COMBSZ; ++i) {
			C[i][0] = 1;
		}
		for (i = 1; i < COMBSZ; ++i) {
			for (j = 1; j < COMBSZ; ++j) {
				C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
			}
		}
		// enumerate
		int res = 0;
		for (i = 0; i <= Rcount; ++i) {
			for (j = 0; j <= Ccount; ++j) {
				int rr = Rcount-i, cr = Ccount-j;
				if ((i*W + j*H - 2*i*j) == S && (rr%2) == 0 && (cr%2) == 0) {
					LL cnt = C[H][i];
					cnt = (cnt * C[rr/2 + H-1][H-1]) % MOD;
					cnt = (cnt * C[W][j]) % MOD;
					cnt = (cnt * C[cr/2 + W-1][W-1]) % MOD;
					res = (res + (int)cnt) % MOD;
				}
			}
		}
		return res;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 2;
			int Arg2 = 2;
			int Arg3 = 2;
			int Arg4 = 4;
			int Arg5 = 4;

			verify_case(n, Arg5, count(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 2;
			int Arg2 = 0;
			int Arg3 = 0;
			int Arg4 = 1;
			int Arg5 = 0;

			verify_case(n, Arg5, count(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arg1 = 20;
			int Arg2 = 50;
			int Arg3 = 40;
			int Arg4 = 200;
			int Arg5 = 333759825;

			verify_case(n, Arg5, count(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1200;
			int Arg1 = 1000;
			int Arg2 = 800;
			int Arg3 = 600;
			int Arg4 = 4000;
			int Arg5 = 96859710;

			verify_case(n, Arg5, count(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 555;
			int Arg1 = 555;
			int Arg2 = 555;
			int Arg3 = 555;
			int Arg4 = 5550;
			int Arg5 = 549361755;

			verify_case(n, Arg5, count(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	XorBoard ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
