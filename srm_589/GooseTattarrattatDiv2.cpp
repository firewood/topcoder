// BEGIN CUT HERE
/*
SRM 589 Div2 Easy (250)

問題
-文字列が与えられる
-1文字変更するのに1秒かかる
-全ての文字を同じにするのにかかる時間を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class GooseTattarrattatDiv2 {
public:
	int getmin(string S) {
		int m = 0;
		int c[256] = {};
		for (int i = 0; i < (int)S.length(); ++i) {
			m = max(m, ++c[S[i]]);
		}
		return (int)S.length() - m;
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
			string Arg0 = "geese";
			int Arg1 = 2;

			verify_case(n, Arg1, getmin(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "tattarrattat";
			int Arg1 = 6;

			verify_case(n, Arg1, getmin(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "www";
			int Arg1 = 0;

			verify_case(n, Arg1, getmin(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "topcoder";
			int Arg1 = 6;

			verify_case(n, Arg1, getmin(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "xrepayuyubctwtykrauccnquqfuqvccuaakylwlcjuyhyammag";
			int Arg1 = 43;

			verify_case(n, Arg1, getmin(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	GooseTattarrattatDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
