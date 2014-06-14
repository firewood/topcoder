// BEGIN CUT HERE
/*
SRM 623 Div1 Easy (300)

問題
-N×Nの升目がある
-それぞれの升目は空きか、りんごか梨が入っている
-1手で、任意の果物を別の空きに移動することができる
-最大K手移動できるとき、りんごのみからなる長方形の最大の面積を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class UniformBoard {

public:
	int getBoard(vector <string> board, int K) {
		int N = (int)board.size();
		int total[256] = {};
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				total[board[i][j]] += 1;
			}
		}

		int ans = 0;
		for (int sy = 0; sy < N; ++sy) {
			for (int ey = sy; ey < N; ++ey) {
				for (int sx = 0; sx < N; ++sx) {
					for (int ex = sx; ex < N; ++ex) {
						int sz = (ex - sx + 1) * (ey - sy + 1);
						if (total['A'] < sz) {
							break;
						}

						int count[256] = {};
						for (int y = sy; y <= ey; ++y) {
							for (int x = sx; x <= ex; ++x) {
								count[board[y][x]] += 1;
							}
						}
						int sum = count['.'] + count['P'] * 2;
						if (count['A'] >= sz || (total['.'] > 0 && sum <= K)) {
							ans = max(ans, sz);
						}
					}
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
			string Arr0[] = {"AP",
 ".A"};
			int Arg1 = 0;
			int Arg2 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getBoard(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"AP",
 ".A"};
			int Arg1 = 1;
			int Arg2 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getBoard(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"PPP",
 "APA",
 "A.P"};
			int Arg1 = 2;
			int Arg2 = 3;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getBoard(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"AAA",
 "PPP",
 "AAA"};
			int Arg1 = 10;
			int Arg2 = 3;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getBoard(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"."};
			int Arg1 = 1000;
			int Arg2 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getBoard(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"PPAAPA..AP",
 "PPA.APAP..",
 "..P.AA.PPP",
 "P.P..APAA.",
 "P.P..P.APA",
 "PPA..AP.AA",
 "APP..AAPAA",
 "P.P.AP...P",
 ".P.A.PAPPA",
 "..PAPAP..P"};
			int Arg1 = 10;
			int Arg2 = 15;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getBoard(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	UniformBoard ___test;
	___test.run_test(0);
//	___test.run_test(1);
//	___test.run_test(2);
//	___test.run_test(3);
//	___test.run_test(4);
//	___test.run_test(5);
	___test.run_test(-1);
}
// END CUT HERE
