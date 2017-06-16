// BEGIN CUT HERE
/*
SRM 715 Div2 Medium (500)

問題
-プラスかマイナスでできた文字列sが与えられる
-初期値がゼロで、プラスなら1増加、マイナスなら1減少
-sの部分文字列によりできる値の差の最大値を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class MaximumRangeDiv2 {
	public:
	int findMax(string s) {
		int c = count(s.begin(), s.end(), '+');
		return max(c, (int)s.length() - c);
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
			string Arg0 = "+++++++";
			int Arg1 = 7;

			verify_case(n, Arg1, findMax(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "+--+--+" ;
			int Arg1 = 4;

			verify_case(n, Arg1, findMax(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "++++--------" ;
			int Arg1 = 8;

			verify_case(n, Arg1, findMax(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "-+-+-+-+-+-+" ;
			int Arg1 = 6;

			verify_case(n, Arg1, findMax(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "+";
			int Arg1 = 1;

			verify_case(n, Arg1, findMax(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MaximumRangeDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
