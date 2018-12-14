// BEGIN CUT HERE
/*
SRM 743 Div2 Medium (500)

問題
- チェス盤に何個かのルークが置かれている
- 同じ列または同じ行のルークは同じ色でなければならない
- 最大何色に塗れるか求めよ

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class FriendlyRooks {
	int h;
	int w;
	vector <string> b;
	void fill(int r, int c) {
		b[r][c] = 0;
		for (int i = 0; i < h; ++i) {
			if (b[i][c] == 'R') {
				fill(i, c);
			}
		}
		for (int i = 0; i < w; ++i) {
			if (b[r][i] == 'R') {
				fill(r, i);
			}
		}
	}

public:
	int getMinFriendlyColoring(vector <string> board) {
		h = board.size();
		w = board[0].length();
		b = board;
		int ans = 0;
		for (int r = 0; r < h; ++r) {
			for (int c = 0; c < w; ++c) {
				if (b[r][c] == 'R') {
					++ans;
					fill(r, c);
				}
			}
		}
		return ans;
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
			string Arr0[] = {".R.R",
 "R.R.",
 ".R.R"};
			int Arg1 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMinFriendlyColoring(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"RRRRRRRRRRRRRRR"};
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMinFriendlyColoring(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"...............",
 "...............",
 "...............",
 "...............",
 "...............",
 "..............."};
			int Arg1 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMinFriendlyColoring(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"....R..........",
 ".R...........R.",
 "....R..........",
 ".R........R....",
 "....R..........",
 "....R.....R...."};
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMinFriendlyColoring(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"R.........R",
 ".R.......R.",
 "..R.....R..",
 "...R...R...",
 "....R.R....",
 ".....R.....",
 "....R.R....",
 "...R...R...",
 "..R.....R..",
 ".R.......R.",
 "R.........R"};
			int Arg1 = 6;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMinFriendlyColoring(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FriendlyRooks ___test;
	___test.run_test(-1);
}
// END CUT HERE
