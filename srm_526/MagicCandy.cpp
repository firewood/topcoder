// BEGIN CUT HERE
/*
// SRM 526.5 Div2 Medium (500)

問題

1-nまでの番号がついたn個のキャンディーがある。
x^2番目のキャンディーを取り除き、残ったy個に1-yの番号を割り当てなおす。
残りの1個になったとき、最初のどの位置だったのかを求める。

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

class MagicCandy {

public:
	int whichOne(int n) {
		int x[32000];
		int i;
		for (i = 0; i < 32000; ++i) {
			x[i] = i*i;
		}

		int result = n;
		int *p = lower_bound(x + 1, x + 32000, n);
		int d = p - x;
		while (n > 1) {
			if (n < *p) {
				--p;
				--d;
			} else {
				if (n == *p) {
					--result;
				}
				n -= d;
			}


/*
			while (n < *p) {
				--p;
				--d;
			}
			while (n > 1 && n >= *p) {
				if (n == *p) {
					--result;
				}
				n -= d;
			}
*/
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
			int Arg1 = 5;

			verify_case(n, Arg1, whichOne(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 9;
			int Arg1 = 7;

			verify_case(n, Arg1, whichOne(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 20;
			int Arg1 = 17;

			verify_case(n, Arg1, whichOne(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5265;
			int Arg1 = 5257;

			verify_case(n, Arg1, whichOne(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 20111223;
			int Arg1 = 20110741;

			verify_case(n, Arg1, whichOne(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 1;

			verify_case(n, Arg1, whichOne(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 2;

			verify_case(n, Arg1, whichOne(Arg0));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MagicCandy ___test;

//	___test.run_test(1);

	___test.run_test(-1);
	return 0;
}
// END CUT HERE
