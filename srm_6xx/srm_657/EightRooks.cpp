// BEGIN CUT HERE
/*
SRM 657 Div2 Easy (250)

問題
-8×8の升目に8個の岩を置く
-同じ行または同じ桁には2つ以上の岩がないこと
-条件を満たしているかどうかを求める

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class EightRooks {
public:
	string isCorrect(vector <string> board) {
		for (int i = 0; i < 8; ++i) {
			int xc = 0, yc = 0;
			for (int j = 0; j < 8; ++j) {
				xc += board[i][j] == 'R';
				yc += board[j][i] == 'R';
			}
			if (xc != 1 || yc != 1) {
				return "Incorrect";
			}
		}
		return "Correct";
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
			string Arr0[] = {"R.......",
 ".R......",
 "..R.....",
 "...R....",
 "....R...",
 ".....R..",
 "......R.",
 ".......R"};
			string Arg1 = "Correct";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isCorrect(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"........",
 "....R...",
 "........",
 ".R......",
 "........",
 "........",
 "..R.....",
 "........"};
			string Arg1 = "Incorrect";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isCorrect(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"......R.",
 "....R...",
 "...R....",
 ".R......",
 "R.......",
 ".....R..",
 "..R.....",
 ".......R"};
			string Arg1 = "Correct";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isCorrect(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"......R.",
 "....R...",
 "...R....",
 ".R......",
 "R.......",
 ".......R",
 "..R.....",
 ".......R"};
			string Arg1 = "Incorrect";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isCorrect(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"........",
 "........",
 "........",
 "........",
 "........",
 "........",
 "........",
 "........"};
			string Arg1 = "Incorrect";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isCorrect(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EightRooks ___test;
	___test.run_test(-1);
}
// END CUT HERE
