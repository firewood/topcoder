// BEGIN CUT HERE
/*
SRM 587 Div2 Easy (250)

問題
-2つの文字列initとgoalが与えられる
-initには文字zが含まれていない
-initに任意の個数だけ文字zを追加してgoalにすることができるかどうかを求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;

class InsertZ {
public:
	string canTransform(string init, string goal) {
		string s;
		for (char c : goal) {
			if (c != 'z') {
				s += c;
			}
		}
		return init.compare(s) == 0 ? "Yes" : "No";
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
			string Arg0 = "fox";
			string Arg1 = "fozx";
			string Arg2 = "Yes";

			verify_case(n, Arg2, canTransform(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "fox";
			string Arg1 = "zfzoxzz";
			string Arg2 = "Yes";

			verify_case(n, Arg2, canTransform(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "foon";
			string Arg1 = "foon";
			string Arg2 = "Yes";

			verify_case(n, Arg2, canTransform(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "topcoder";
			string Arg1 = "zopzoder";
			string Arg2 = "No";

			verify_case(n, Arg2, canTransform(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "aaaaaaaaaa";
			string Arg1 = "a";
			string Arg2 = "No";

			verify_case(n, Arg2, canTransform(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "mvixrdnrpxowkasufnvxaq";
			string Arg1 = "mvizzxzzzrdzznzrpxozzwzzkazzzszzuzzfnvxzzzazzq";
			string Arg2 = "Yes";

			verify_case(n, Arg2, canTransform(Arg0, Arg1));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			string Arg0 = "opdlfmvuicjsierjowdvnx";
			string Arg1 = "zzopzdlfmvzuicjzzsizzeijzowvznxzz";
			string Arg2 = "No";

			verify_case(n, Arg2, canTransform(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	InsertZ ___test;
	___test.run_test(-1);
}
// END CUT HERE
