// BEGIN CUT HERE
/*
SRM 707 Div2 Easy (250)

問題
-白か黒が書かれたマス目がある
-黒で十字をなす部分があるかどうかを求める

*/
// END CUT HERE
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class Cross {
	public:
	string exist(vector <string> board) {
		int H = (int)board.size();
		int W = (int)board[0].length();
		for (int i = 1; i < (H - 1); ++i) {
			for (int j = 1; j < (W - 1); ++j) {
				if (board[i - 1][j] == '#' && board[i][j - 1] == '#' && board[i][j] == '#' && board[i][j + 1] == '#' && board[i + 1][j] == '#') {
					return "Exist";
				}
			}
		}
		return "Does not exist";
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
			string Arr0[] = {".##",
 "###",
 "##."};
			string Arg1 = "Exist";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, exist(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {".##",
 "###",
 "#.."};
			string Arg1 = "Does not exist";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, exist(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"######",
 "######",
 "######",
 "######",
 "######",
 "######",
 "######"};
			string Arg1 = "Exist";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, exist(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {".#.#",
 "#.#.",
 ".#.#",
 "#.#."};
			string Arg1 = "Does not exist";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, exist(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {".#.#",
 "###.",
 ".###",
 "#.#."};
			string Arg1 = "Exist";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, exist(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Cross ___test;
	___test.run_test(-1);
}
// END CUT HERE
