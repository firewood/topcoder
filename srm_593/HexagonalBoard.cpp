// BEGIN CUT HERE
/*
SRM 593 Div1 Easy (250)

PROBLEM STATEMENT
The pony Applejack has an N by N hexagonal board. The following picture shows the hexagonal board when N = 1, 2, 3, and 4.

She wants to color some cells of the board. You are given a vector <string> board. If the j-th character of the i-th element of board is 'X', she wants to color the cell (i, j). If she colors two cells that share an edge, she must use different colors for those cells. Return the minimal number of colors she needs.


DEFINITION
Class:HexagonalBoard
Method:minColors
Parameters:vector <string>
Returns:int
Method signature:int minColors(vector <string> board)


CONSTRAINTS
-board will contain between 1 and 50 elements, inclusive.
-Each element of board will contain exactly N characters, where N is the number of elements in board.
-Each character in board will be either 'X' or '-'.


EXAMPLES

0)
{"---",
 "---",
 "---"}
 

Returns: 0

She won't color any cells, so she won't need any colors.


1)
{"-X--",
 "---X",
 "----",
 "-X--"}

Returns: 1

She can color all cells with the same color.


2)
{"XXXX",
 "---X",
 "---X",
 "---X"}

Returns: 2

For example, she can color cells in the following way:

Color cells (0, 0), (0, 2), (1, 3), and (3, 3) red.
Color cells (0, 1), (0, 3), and (2, 3) blue.


3)
{"XX-XX--"
,"-XX-XXX"
,"X-XX--X"
,"X--X-X-"
,"XX-X-XX"
,"-X-XX-X"
,"-XX-XX-"}

Returns: 3

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;

typedef vector<string> StrVec;

class HexagonalBoard {

	int N;
	StrVec b;
	int col[64][64];

	int dfs(int x, int y) {
		const int dx[] = {0,1,1,0,-1,-1};
		const int dy[] = {-1,-1,0,1,1,0};
		const int cc[] = {1,2,1,3};

		if (x < 0 || x >= N || y < 0 || y >= N) {
			return 0;
		}
		if (b[y][x] != 'X') {
			return 0;
		}
		int &color = col[y+1][x+1];
		if (color == 0) {
			int c = 0;
			for (int k = 0; k < 6; ++k) {
				int p = x + dx[k];
				int q = y + dy[k];
				c |= col[q+1][p+1];
			}
			color = cc[c];
			for (int k = 0; k < 6; ++k) {
				int p = x + dx[k];
				int q = y + dy[k];
				dfs(p, q);
			}
		}

		return color;
	}

public:
	int minColors(vector <string> board) {
		N = (int)board.size();
		b = board;
		memset(col, 0, sizeof(col));
		int ans = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				ans = max(ans, dfs(j, i));
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
			string Arr0[] = {"---",
 "---",
 "---"}
 ;
			int Arg1 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minColors(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"-X--",
 "---X",
 "----",
 "-X--"};
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minColors(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"XXXX",
 "---X",
 "---X",
 "---X"};
			int Arg1 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minColors(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"XX-XX--"
,"-XX-XXX"
,"X-XX--X"
,"X--X-X-"
,"XX-X-XX"
,"-X-XX-X"
,"-XX-XX-"};
			int Arg1 = 3;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minColors(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
				"-X-",
				 "-XX",
				  "X--"}
 ;
			int Arg1 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minColors(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
				"--X",
				 "XX-",
				  "-X-"}
 ;
			int Arg1 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minColors(Arg0));
		}
		n++;



		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
				"-X-X--XX-XX-XXXXX-XX-XXX---XX-X-XX-XX--XX-XXXXX--X",
				 "X-X-XX-X--X-----X--XX---XXX-X----XX-X-X-X-----XXX-",
				  "-X-X---X--XXX-X-XX--X--X--XX-XXXX-X-X-XX-X---X--X-",
				   "X-X-XX--XX---X----X--X--X--X-------X----X-XX--X-X-",
				    "X--X-X-X--X-X-X-XX-XX-X-XX--XX-XXX-XX-X-X--X-X--XX",
					 "XXX--X-X--XX--XX--X-XX-X--X--X----X--X--XX-XX-X---",
					  "--XX-XX-X----X--XX---X--XX-X-X-XX-X-X-XX-X---X-XXX",
					   "X--X---X-XXX-XX---XX--XX--X-X---X-X-X--X-X-XX-X--X",
					    "X--XX-X-X--X----XX--X--X-X-X-XX-X-X-XX-X--X-X-XX-X",
						 "X-X-X-X----X-XXX-XX-XXX-X-X-X--X-X-X-XX-X-XX-X-XX-",
						  "XX--X-XXXX--X---X-X---X-----X-X--X-X----X---X-X-XX",
						   "-X--X-----X--XXX-X-X---XX-X-X--X-X-X-XX-XX-X--XX-X",
						    "-XX--X-XX--X---XX--XX-X--X-X-XX--X-------X--XX---X",
							 "X-XX-XX-X-X-XX---X---X-X-X--X-XX-X-XXXXX-XX---XX-X",
							  "XX-X----X-----X-X-XX---XX-X-X--X-X--------X-X--XX-",
							   "----XXXX-X-XX-X-XX--XX---X--XX-X--XX-XXXX-X--XX--X",
							    "XXX----X-X----XX--XX-X-X-XXX--X-XX--X-----X-X-XXX-",
								 "--X-XXX---XX-X-X-X-X--X-----XX-X--X--X-X--XX-X--XX",
								  "XX-X--XXX--X----X--X-X-XX-X---X-XX-X-X-XXX-X--XX-X",
								   "-X-XXX--XX--XX-X-XX-X-X-XX--XX----X-X-X----XXX-X--",
								    "-XX---X--X-X--X-X-XX-X---X-X--X-X-X-X---XX---XX-XX",
									 "X-X-XX-X-XX-X--X----X--X----XX-X-----XX--XXX---X--",
									  "XX---X-XX---X-X-XXX--XX-XXXX---XX-X-X--XX--XX---XX",
									   "-XXX-----XX-X-X---X-X--X-----X--X-X--X--X-X-XX-X--",
									    "X---XXXX---X--X-X-X--XX-XX-XX-X---X-X-X-X-XX--X-X-",
										 "XXXX----XX-XX-----XX--XX--X--X-XX--X-----X--X--X-X",
										  "---X-X-X--X--X-X-X-XXX-XX---X-X--X--XXX--XX--X-X--",
										   "XX--X-X-X--X-XX--X---XX--XX-XX-XX-X---XX--X-X-X-XX",
										    "--X-X-X--XX-X-X-X-XX---XX--X-X--X-XXXX--X-XX-X-X--",
											 "X--X---XX-X-X-X----XXX--XX-X-XX-X------X-----XX-XX",
											  "X-X-XX----X-X-X-X----XX--X--X---X-XX-XX-XXXX---X-X",
											   "--X--X-X-X--X-X-XX-XX-XX-XX--X-X-X-XX--X---X-XX-X-",
											    "X--X----X---X-X---X-X--XX--X-X-X-XX-XX--XX--X---XX",
												 "X-X-XXX--XXX--XXXX--XXX-X-X-X-X-X-XX-XX--XX--XX---",
												  "X-XX---XX---XX----X---XX-X----XX-X-X--XX--X-X--XX-",
												   "-X--XXX-X-XX-X-X--X-XX---XXXX--X-X--X---X--X-XX-XX",
												    "X-XX--X--X---X-XXX-X-XXX-----X--X-XX-X-X-XX-X--X-X",
													 "-X-XXX-X-XXX-X----X-X--X-XXXX-X--X-X-X--X---X-X-X-",
													  "-XX--X--X----XX------X--X---X--XX-X--XXX-XX-X--X--",
													   "X-X-X-X-X-XX---XX-XX--X-X-X-XXX-XX-X---XX--X-XX-XX",
													    "XX-X--X--X-X-X--X---XX-X-X-X--XX---XXXX-X-X---XX-X",
														 "-X--X-XXX--X--X---XX-X-X---XX---X-X---X--X-XXX----",
														  "X-XX-X--X--X-X-X-X-X-XX-X---XX--X-X-X-X--XX--XXXXX",
														   "XX-X-XX-X--X----X-X----X-XX--XX-XX-X--X-X--X------",
														    "-X-X----X-X-XXX-X-XXX-X-----X--X-X---X--XX---XX-XX",
															 "X--XXX-X--X---X--X--X-XX-XX-X--X-XXXX-X--X-XX--X-X",
															  "X-X---X-X--XX--XX-XX-X-X---X-X-XX---XX-XX-X-X-X--X",
															   "X---X--X-XX--XX-XX-XX--XXXX--XX-XXXX-X----XX-X-X-X",
															    "X-XX-XX-X-X-X----X---X------X--X-------XXX-XX--X-X",
																 "-X-XX-X-XX--XXXX-XXX--XXX-XX-XX-XXXXXXX--XX-XX-X-X"};
			int Arg1 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minColors(Arg0));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	HexagonalBoard ___test;
	___test.run_test(-1);
}
// END CUT HERE
