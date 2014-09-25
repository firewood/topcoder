// BEGIN CUT HERE
/*
SRM 620 Div2 Medium (500)

問題
-1以上の二つの整数のペアx,yがある
-次のターンで(x+y,y)か(x,x+y)のどちらかにできる
-(a,b)からはじめて(c,d)に到達できるかどうかを求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class PairGameEasy {
public:
	string able(int a, int b, int c, int d) {
		while (c > 0 && d > 0 && (c > a || d > b)) {
			if (c > d) {
				c -= d;
			} else {
				d -= c;
			}
		}
		if (a == c && b == d) {
			return "Able to generate";
		}
		return "Not able to generate";
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 2;
			int Arg2 = 3;
			int Arg3 = 5;
			string Arg4 = "Able to generate";

			verify_case(n, Arg4, able(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 2;
			int Arg2 = 2;
			int Arg3 = 1;
			string Arg4 = "Not able to generate";

			verify_case(n, Arg4, able(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 2;
			int Arg2 = 2;
			int Arg3 = 999;
			string Arg4 = "Not able to generate";

			verify_case(n, Arg4, able(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 2;
			int Arg2 = 2;
			int Arg3 = 1000;
			string Arg4 = "Able to generate";

			verify_case(n, Arg4, able(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 47;
			int Arg1 = 58;
			int Arg2 = 384;
			int Arg3 = 221;
			string Arg4 = "Able to generate";

			verify_case(n, Arg4, able(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1000;
			int Arg1 = 1000;
			int Arg2 = 1000;
			int Arg3 = 1000;
			string Arg4 = "Able to generate";

			verify_case(n, Arg4, able(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PairGameEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
