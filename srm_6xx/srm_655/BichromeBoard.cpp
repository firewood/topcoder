// BEGIN CUT HERE
/*
SRM 655 Div2 Easy (250)

問題
-碁盤がある
-各升目の初期状態はBかWか?である
-それぞれの?はBかWにする
-市松模様にできるかどうかを求める

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

class BichromeBoard {
	bool possible(vector <string> &board, int c) {
		for (int i = 0; i < (int)board.size(); ++i) {
			for (int j = 0; j < (int)board[0].length(); ++j) {
				if (board[i][j] != '?' && board[i][j] != "BW"[(i + j + c) % 2]) {
					return false;
				}
			}
		}
		return true;
	}
public:
	string ableToDraw(vector <string> board) {
		if (possible(board, 0) || possible(board, 1)) {
			return "Possible";
		}
		return "Impossible";
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
			string Arr0[] = {"W?W",
 "??B",
 "???"};
			string Arg1 = "Possible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, ableToDraw(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"W??W"};
			string Arg1 = "Impossible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, ableToDraw(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"??"};
			string Arg1 = "Possible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, ableToDraw(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"W???",
 "??B?",
 "W???",
 "???W"};
			string Arg1 = "Possible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, ableToDraw(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"W???",
 "??B?",
 "W???",
 "?B?W"};
			string Arg1 = "Impossible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, ableToDraw(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"B"};
			string Arg1 = "Possible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, ableToDraw(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BichromeBoard ___test;
	___test.run_test(-1);
}
// END CUT HERE
