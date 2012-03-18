// BEGIN CUT HERE
/*
// SRM 537 Div1 Easy (250)

問題
アヒルの国の通貨は価値Aと価値Bの二種類ある。
王がAとBに飽きたので通貨を価値Xと価値Yに変更することにした。
変更後もAB貨幣システムでの価格が使えるYは何通りあるかを求める。

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
typedef vector<int> IntVec;
typedef vector<LL> LLVec;
typedef vector<string> StrVec;
typedef set<int> IntSet;
typedef set<LL> LLSet;

class KingXNewCurrency {

public:
	int howMany(int A, int B, int X) {
		if ((A % X) == 0 && (B % X) == 0) {
			return -1;
		}
		int res = 0;
		int y;
		for (y = 1; y <= 200; ++y) {
			int Max = max(A, B);
			bool af = false, bf = false;
			int i, j;
			for (i = 0; i <= Max; ++i) {
				for (j = 0; j <= Max; ++j) {
					int z = X*i+y*j;
					if (z > Max) {
						break;
					}
					if (z == A) {
						af = true;
					}
					if (z == B) {
						bf = true;
					}
				}
			}
			res += af && bf;
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
			int Arg0 = 5;
			int Arg1 = 8;
			int Arg2 = 5;
			int Arg3 = 5;

			verify_case(n, Arg3, howMany(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 8;
			int Arg1 = 4;
			int Arg2 = 2;
			int Arg3 = -1;

			verify_case(n, Arg3, howMany(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 7;
			int Arg1 = 4;
			int Arg2 = 13;
			int Arg3 = 1;

			verify_case(n, Arg3, howMany(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 47;
			int Arg1 = 74;
			int Arg2 = 44;
			int Arg3 = 2;

			verify_case(n, Arg3, howMany(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 128;
			int Arg1 = 96;
			int Arg2 = 3;
			int Arg3 = 65;

			verify_case(n, Arg3, howMany(Arg0, Arg1, Arg2));
		}
		n++;
	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	KingXNewCurrency ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
