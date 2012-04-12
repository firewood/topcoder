// BEGIN CUT HERE
/*
// SRM 540 Div2 Easy (250)

問題
フリスビーを2色で塗る。
上の色と、取りうる範囲が与えられる。
下の色は、上の色と同じでなく、かつ、違いすぎもしない色である。
下の色に使える組み合わせの個数を求める。

*/
// END CUT HERE
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
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
typedef vector<int> IntVec;
typedef vector<string> StrVec;

class RandomColoringDiv2 {

public:
	int getCount(int maxR, int maxG, int maxB, int startR, int startG, int startB, int d1, int d2) {

		int result;
		{
			int rs = max(0, startR - d2);
			int re = min(maxR - 1, startR + d2);
			int gs = max(0, startG - d2);
			int ge = min(maxG - 1, startG + d2);
			int bs = max(0, startB - d2);
			int be = min(maxB - 1, startB + d2);
			result = (re - rs + 1) * (ge - gs + 1) * (be - bs + 1);
		}
		if (d1 > 0) {
			--d1;
			int rs = max(0, startR - d1);
			int re = min(maxR - 1, startR + d1);
			int gs = max(0, startG - d1);
			int ge = min(maxG - 1, startG + d1);
			int bs = max(0, startB - d1);
			int be = min(maxB - 1, startB + d1);
			result -= (re - rs + 1) * (ge - gs + 1) * (be - bs + 1);
		}
		return result;
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
			int Arg0 = 5;
			int Arg1 = 1;
			int Arg2 = 1;
			int Arg3 = 2;
			int Arg4 = 0;
			int Arg5 = 0;
			int Arg6 = 0;
			int Arg7 = 1;
			int Arg8 = 3;

			verify_case(n, Arg8, getCount(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 2;
			int Arg2 = 2;
			int Arg3 = 0;
			int Arg4 = 0;
			int Arg5 = 0;
			int Arg6 = 3;
			int Arg7 = 3;
			int Arg8 = 4;

			verify_case(n, Arg8, getCount(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 2;
			int Arg2 = 2;
			int Arg3 = 0;
			int Arg4 = 0;
			int Arg5 = 0;
			int Arg6 = 5;
			int Arg7 = 5;
			int Arg8 = 0;

			verify_case(n, Arg8, getCount(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			int Arg1 = 9;
			int Arg2 = 10;
			int Arg3 = 1;
			int Arg4 = 2;
			int Arg5 = 3;
			int Arg6 = 0;
			int Arg7 = 10;
			int Arg8 = 540;

			verify_case(n, Arg8, getCount(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			int Arg1 = 9;
			int Arg2 = 10;
			int Arg3 = 1;
			int Arg4 = 2;
			int Arg5 = 3;
			int Arg6 = 4;
			int Arg7 = 10;
			int Arg8 = 330;

			verify_case(n, Arg8, getCount(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 49;
			int Arg1 = 59;
			int Arg2 = 53;
			int Arg3 = 12;
			int Arg4 = 23;
			int Arg5 = 13;
			int Arg6 = 11;
			int Arg7 = 22;
			int Arg8 = 47439;

			verify_case(n, Arg8, getCount(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 100;
			int Arg1 = 100;
			int Arg2 = 100;
			int Arg3 = 99;
			int Arg4 = 0;
			int Arg5 = 0;
			int Arg6 = 1;
			int Arg7 = 100;
			int Arg8 = 999999;

			verify_case(n, Arg8, getCount(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	RandomColoringDiv2 ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
