// BEGIN CUT HERE
/*
// SRM 555 Div1 Easy (250)

問題
ビット列が文字列で与えられる。
5のべき乗のビット列文字列に分割したとき、何個になるかを求める。

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

typedef long long LL;

class CuttingBitString {

	int len;
	LL N;
	int memo[60];
	int rec(int pos) {
		int &res = memo[pos];
		if (res >= 0) {
			return res;
		}
		res = 9999;
		int r = len - pos;
		LL x = N & ((1LL << r) - 1);
		if (x & (1LL << (r-1))) {
			int i;
			for (i = 1; i <= r; ++i) {
				LL y = (x >> (r-i));
				while (y > 1 && ((y % 5) == 0)) {
					y /= 5;
				}
				if (y == 1) {
					res = min(res, 1 + rec(pos + i));
				}
			}
		}
		return res;
	}

public:
	int getmin(string S) {
		memset(memo, -1, sizeof(memo));
		len = (int)S.length();
		N = 0;
		int i;
		for (i = 0; i < (int)S.length(); ++i) {
			if (S[i] != '0') {
				N |= (1LL << (S.length() - i - 1));
			}
		}
		memo[S.length()] = 0;
		int res = rec(0);
		return res < 9999 ? res : -1;
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
			string Arg0 = "101101101";
			int Arg1 = 3;

			verify_case(n, Arg1, getmin(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "1111101";
			int Arg1 = 1;

			verify_case(n, Arg1, getmin(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "00000";
			int Arg1 = -1;

			verify_case(n, Arg1, getmin(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "110011011";
			int Arg1 = 3;

			verify_case(n, Arg1, getmin(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "1000101011";
			int Arg1 = -1;

			verify_case(n, Arg1, getmin(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "111011100110101100101110111";
			int Arg1 = 5;

			verify_case(n, Arg1, getmin(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	CuttingBitString ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
