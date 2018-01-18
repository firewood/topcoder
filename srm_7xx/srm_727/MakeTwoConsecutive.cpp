// BEGIN CUT HERE
/*
SRM 727 Div2 Easy (250)

問題
-文字列Sから1文字削除して、同じ文字が連続する文字列が作れるかどうかを求めよ

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class MakeTwoConsecutive {
	bool possible(const string &s) {
		for (int i = 0; i < (int)s.length(); ++i) {
			string x = s.substr(0, i) + s.substr(i + 1);
			char prev = 0;
			for (char c : x) {
				if (c == prev) {
					return true;
				}
				prev = c;
			}
		}
		return false;
	}
public:
	string solve(string S) {
		return possible(S) ? "Possible" : "Impossible";
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
			string Arg0 = "VIKING";
			string Arg1 = "Possible";

			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "BCAB";
			string Arg1 = "Impossible";

			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "XX";
			string Arg1 = "Impossible";

			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "A";
			string Arg1 = "Impossible";

			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "AABB";
			string Arg1 = "Possible";

			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "QWERTYY";
			string Arg1 = "Possible";

			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ITHINKYOUAREAHUMAN";
			string Arg1 = "Impossible";

			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_7
		if ((Case == -1) || (Case == n)){
			string Arg0 = "BOB";
			string Arg1 = "Possible";

			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MakeTwoConsecutive ___test;
	___test.run_test(-1);
}
// END CUT HERE
