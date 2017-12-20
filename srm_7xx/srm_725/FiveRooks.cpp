// BEGIN CUT HERE
/*
SRM 725 Div1 Easy (250)

問題
-8x8のチェス盤がある
-何個かのルークが置かれている
-ルークの個数は、何も置かれていないマス目の個数よりも多い
-ルークを5個だけ選んで、残りを除去する
-どのルークも別のルークと干渉しない置き方を求めよ

*/
// END CUT HERE
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class FiveRooks {
public:
	vector <int> find(vector <string> board) {
		int si = 0;
		int seq[8] = {};
		for (int i = 0; i < 8; ++i) {
			if (count(board[i].begin(), board[i].end(), 'R') > 0) {
				seq[si++] = i;
			}
		}
		vector <int> ans;
		int rows;
		int col[8];
		do {
			int u[8] = {};
			rows = 0;
			for (int i = 0; i < 5; ++i) {
				int row = seq[i];
				for (int j = 0; j < 8; ++j) {
					if (!u[j] && board[row][j] != '.') {
						u[j] = 1;
						col[rows++] = j;
						break;
					}
				}
			}
		} while (rows < 5 && next_permutation(seq, seq + si));
		for (int i = 0; i < 5; ++i) {
			ans.push_back(seq[i]);
			ans.push_back(col[i]);
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
"RRRRRRRR",
"RRRRRRRR",
"RRRRRRRR",
"RRRRRRRR",
"R.......",
"........",
"........",
"........"
};
			int Arr1[] = {0, 7, 1, 3, 2, 4, 3, 6, 4, 0 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, find(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
"R.R.R.R.",
".R.R.R.R",
"R.R.R.R.",
".R.RRR.R",
"R.R.R.R.",
".R.R.R.R",
"R.R.R.R.",
".R.R.R.R"
};
			int Arr1[] = {0, 0, 1, 7, 2, 6, 3, 5, 4, 4 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, find(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
"RRRRRRRR",
"RRRRRRRR",
"RRRRRRRR",
"RRRRRRRR",
"RRRRRRRR",
"RRRRRRRR",
"RRRRRRRR",
"RRRRRRRR"
};
			int Arr1[] = {0, 7, 1, 3, 2, 4, 3, 6, 4, 0 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, find(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
".RRRRRR.",
"RRRRRRRR",
"....RRRR",
"...RRRR.",
"..RRRR..",
".RRRR...",
"RRRR....",
"RRR....."
}
;
			int Arr1[] = {1, 7, 2, 6, 3, 5, 4, 4, 5, 3 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, find(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
".RRRRRR.",
"RRRRRRRR",
"....RRRR",
"...RRRR.",
"..RRRR..",
".RRRR...",
"RRRRRRRR",
".RRRRRR."
};
			int Arr1[] = {1, 7, 2, 6, 3, 5, 4, 4, 5, 3 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, find(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = 
{
".RRRRRR.",
"RRRRRRRR",
".RRRR...",
"..RRRR..",
"...RRRR.",
"....RRRR",
"RRRRRRRR",
".RRRRRR."
};
			int Arr1[] = {1, 7, 3, 5, 4, 4, 6, 2, 7, 1 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, find(Arg0));
		}
		n++;





		if ((Case == -1) || (Case == n)) {
			string Arr0[] = {
				"R......R",
				".R......",
				"..R.....",
				"...R....",
				"R.......",
				"........",
				"........",
				"........"
			};
			int Arr1[] = { 0, 7, 1, 3, 2, 4, 3, 6, 4, 0 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, find(Arg0));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FiveRooks ___test;
	___test.run_test(-1);
}
// END CUT HERE
