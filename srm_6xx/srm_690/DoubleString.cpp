// BEGIN CUT HERE
/*
SRM 690 Div2 Easy (250)

問題
-文字列Sが同じ文字列を2つつなげたものかどうか判定する

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class DoubleString {
public:
	string check(string S) {
		int hlen = (int)S.length() / 2;
		return S.substr(0, hlen).compare(S.substr(hlen)) == 0 ? "square" : "not square";
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
			string Arg0 = "MAZAIMAZAI";
			string Arg1 = "square";

			verify_case(n, Arg1, check(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "MAMAZAIZAI";
			string Arg1 = "not square";

			verify_case(n, Arg1, check(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "IOI";
			string Arg1 = "not square";

			verify_case(n, Arg1, check(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "AA";
			string Arg1 = "square";

			verify_case(n, Arg1, check(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ABCCBA";
			string Arg1 = "not square";

			verify_case(n, Arg1, check(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "Y";
			string Arg1 = "not square";

			verify_case(n, Arg1, check(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DoubleString ___test;
	___test.run_test(-1);
}
// END CUT HERE
