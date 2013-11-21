// BEGIN CUT HERE
/*
SRM 500 Div1 Easy (250)

// PROBLEM STATEMENT
// Fox Ciel is going to play Gomoku with her friend Fox Jiro.
Ciel plays better, so before they start she allowed Jiro to put some of his pieces on the board.


You are given a vector <string> board that represents a square board.
The character board[i][j] represents the cell with coordinates (i,j).
Each of those characters is either '.' (representing an empty cell) or 'o' (representing a cell with Jiro's piece).


Of course, Ciel does not want Jiro to win the game before she has a chance to play.
Thus she now has to check the board and determine whether there are five consecutive tokens somewhere on the board.


Determine whether there are 5 consecutive cells (horizontally, vertically, or diagonally) that contain Jiro's tokens.
Return "found" (quotes for clarity) if there are five such cells anywhere on the board.
Otherwise, return "not found".

DEFINITION
Class:FoxAndGomoku
Method:win
Parameters:vector <string>
Returns:string
Method signature:string win(vector <string> board)


CONSTRAINTS
-n will be between 5 and 15, inclusive.
-board will contain exactly n elements.
-Each element in board will contain exactly n characters.
-Each character in board will be 'o' or '.'.


EXAMPLES

0)
{"....o.",
 "...o..",
 "..o...",
 ".o....",
 "o.....",
 "......"}

Returns: "found"

There is five continue pieces diagonally.

1)
{"oooo.",
 ".oooo",
 "oooo.",
 ".oooo",
 "....."}
 

Returns: "not found"

There is no five-in-a-row on this board.

2)
{"oooo.",
 ".oooo",
 "oooo.",
 ".oooo",
 "....o"}
 

Returns: "found"

Five consecutive tokens can be found in the following cells: (0,0), (1,1), (2,2), (3,3), and (4,4).

3)
{"o.....",
 ".o....",
 "..o...",
 "...o..",
 "....o.",
 "......"}

Returns: "found"



4)
{"o....",
 "o.o..",
 "o.o.o",
 "o.o..",
 "o...."}

Returns: "found"



5)
{"..........",
 "..........",
 "..oooooo..",
 "..o.......",
 "..o.......",
 "..oooooo..",
 ".......o..",
 ".......o..",
 "..oooooo..",
 ".........."}
 


Returns: "found"



6)
{"..........",
 "..........",
 "..oooo.o..",
 "..o.......",
 "..o.......",
 "..o.oooo..",
 ".......o..",
 ".......o..",
 "..oooo.o..",
 ".........."}


Returns: "not found"



7)
{"ooooo",
 "ooooo",
 "ooooo",
 "ooooo",
 "ooooo"}

Returns: "found"



8)
{".....",
 ".....",
 ".....",
 ".....",
 "....."}

Returns: "not found"

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class FoxAndGomoku {
public:
	string win(vector <string> board) {
		int N = (int)board.size();
		int i, j, k;
		for (i = 0; i < N; ++i) {
			for (j = 0; j <= (N-5); ++j) {
				int h = 0, v = 0, p = 0, q = 0;
				for (k = 0; k < 5; ++k) {
					h += board[i][j+k] == 'o';
					v += board[j+k][i] == 'o';
					if (i <= (N-5)) {
						p += board[i+k][j+k] == 'o';
						q += board[i+4-k][j+k] == 'o';
					}
				}
				if (h >= 5 || v >= 5 || p >= 5 || q >= 5) {
					return "found";
				}
			}
		}
		return "not found";
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
			string Arr0[] = {"....o.",
 "...o..",
 "..o...",
 ".o....",
 "o.....",
 "......"};
			string Arg1 = "found";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, win(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"oooo.",
 ".oooo",
 "oooo.",
 ".oooo",
 "....."}
 ;
			string Arg1 = "not found";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, win(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"oooo.",
 ".oooo",
 "oooo.",
 ".oooo",
 "....o"}
 ;
			string Arg1 = "found";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, win(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"o.....",
 ".o....",
 "..o...",
 "...o..",
 "....o.",
 "......"};
			string Arg1 = "found";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, win(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"o....",
 "o.o..",
 "o.o.o",
 "o.o..",
 "o...."};
			string Arg1 = "found";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, win(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"..........",
 "..........",
 "..oooooo..",
 "..o.......",
 "..o.......",
 "..oooooo..",
 ".......o..",
 ".......o..",
 "..oooooo..",
 ".........."}
 
;
			string Arg1 = "found";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, win(Arg0));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"..........",
 "..........",
 "..oooo.o..",
 "..o.......",
 "..o.......",
 "..o.oooo..",
 ".......o..",
 ".......o..",
 "..oooo.o..",
 ".........."}
;
			string Arg1 = "not found";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, win(Arg0));
		}
		n++;

		// test_case_7
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"ooooo",
 "ooooo",
 "ooooo",
 "ooooo",
 "ooooo"};
			string Arg1 = "found";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, win(Arg0));
		}
		n++;

		// test_case_8
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {".....",
 ".....",
 ".....",
 ".....",
 "....."};
			string Arg1 = "not found";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, win(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FoxAndGomoku ___test;
//	___test.run_test(0);
//	___test.run_test(1);
//	___test.run_test(2);
//	___test.run_test(3);
//	___test.run_test(4);
//	___test.run_test(5);
	___test.run_test(-1);
}
// END CUT HERE
