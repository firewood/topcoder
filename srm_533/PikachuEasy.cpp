// BEGIN CUT HERE
/*
// SRM 533 Div2 Easy (250)

問題
ぴかちゅーは ぴ か ちゅー しかしゃべれない。
与えられた文字列がぴかちゅーが発音できるかどうか求める。

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

class PikachuEasy {

public:
	string check(string word) {
		const char *p = word.c_str();
		while (*p) {
			if (strncmp(p, "pi", 2) == 0 || strncmp(p, "ka", 2) == 0) {
				p += 2;
			} else if (strncmp(p, "chu", 3) == 0) {
				p += 3;
			} else {
				return "NO";
			}
		}
		return "YES";
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
			string Arg0 = "pikapi";
			string Arg1 = "YES";

			verify_case(n, Arg1, check(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "pipikachu";
			string Arg1 = "YES";

			verify_case(n, Arg1, check(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "pikaqiu";
			string Arg1 = "NO";

			verify_case(n, Arg1, check(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "topcoder";
			string Arg1 = "NO";

			verify_case(n, Arg1, check(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "piika";
			string Arg1 = "NO";

			verify_case(n, Arg1, check(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "chupikachupipichu";
			string Arg1 = "YES";

			verify_case(n, Arg1, check(Arg0));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			string Arg0 = "pikapipachu";
			string Arg1 = "NO";

			verify_case(n, Arg1, check(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PikachuEasy ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
