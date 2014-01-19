// BEGIN CUT HERE
/*
SRM 593 Div1 Easy (250)

問題
-ヘックスの升目のボードがある
-Xの印がついているところに色を塗る
-隣接していれば違う色を塗る
-最低何色必要か求める

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
