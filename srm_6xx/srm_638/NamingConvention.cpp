// BEGIN CUT HERE
/*
SRM 638 Div2 Easy (250)

問題
-スネークケースの名前が与えられる
-キャメルケースに変換する

*/
// END CUT HERE
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class NamingConvention {
public:
	string toCamelCase(string variableName) {
		string ans;
		bool u = false;
		for (char c : variableName) {
			if (c == '_') {
				u = true;
			} else if (u) {
				u = false;
				ans += toupper(c);
			} else {
				ans += c;
			}
		}
		return ans;
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
			string Arg0 = "sum_of_two_numbers";
			string Arg1 = "sumOfTwoNumbers";

			verify_case(n, Arg1, toCamelCase(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "variable";
			string Arg1 = "variable";

			verify_case(n, Arg1, toCamelCase(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "t_o_p_c_o_d_e_r";
			string Arg1 = "tOPCODER";

			verify_case(n, Arg1, toCamelCase(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "the_variable_name_can_be_very_long_like_this";
			string Arg1 = "theVariableNameCanBeVeryLongLikeThis";

			verify_case(n, Arg1, toCamelCase(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	NamingConvention ___test;
	___test.run_test(-1);
}
// END CUT HERE
