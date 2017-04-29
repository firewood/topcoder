// BEGIN CUT HERE
/*
SRM 713 Div2 Easy (250)

問題
-N行M列の升目がある
-各升目は白か黒である
-水平線と垂直線のそれぞれについて対称かどうかを求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class SymmetryDetection {
public:
	string detect(vector <string> board) {
		int h = (int)board.size(), w = (int)board[0].length();
		bool hs = true, vs = true;
		for (int i = 0; i <= h / 2; ++i) {
			for (int j = 0; j < w; ++j) {
				if (board[i][j] != board[h - i - 1][j]) {
					hs = false;
				}
			}
		}
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j <= w / 2; ++j) {
				if (board[i][j] != board[i][w-j-1]) {
					vs = false;
				}

			}
		}
		if (hs) {
			return vs ? "Both" : "Horizontally symmetric";
		}
		return vs ? "Vertically symmetric" : "Neither";
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
			string Arr0[] = {"#####",
 ".###.",
 "..#.."};
			string Arg1 = "Vertically symmetric";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, detect(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"#####",
 "#...#",
 "#####"};
			string Arg1 = "Both";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, detect(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"#..",
 "#..",
 "#.."};
			string Arg1 = "Horizontally symmetric";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, detect(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"#.",
 ".#"};
			string Arg1 = "Neither";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, detect(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"#######",
 "#..#..#",
 "#######",
 "...#...",
 "#######"};
			string Arg1 = "Vertically symmetric";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, detect(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"#.....#",
 "#.....#",
 "#######",
 "#...#.#",
 "#.....#"};
			string Arg1 = "Neither";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, detect(Arg0));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"#######.#.....#",
 "...#....#.....#",
 ".#####..#######",
 "...#....#.....#",
 "#######.#.....#"};
			string Arg1 = "Horizontally symmetric";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, detect(Arg0));
		}
		n++;

		// test_case_7
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"."};
			string Arg1 = "Both";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, detect(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SymmetryDetection ___test;
	___test.run_test(-1);
}
// END CUT HERE
