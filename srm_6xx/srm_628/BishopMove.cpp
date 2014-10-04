// BEGIN CUT HERE
/*
SRM 628 Div2 Easy (250)

問題
-チェスの盤面がある
-ビショップが(r1,c1)から(r2,c2)に何手で移動できるか求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;

class BishopMove {

public:
	int howManyMoves(int r1, int c1, int r2, int c2) {
		int b[8][8];
		memset(b, -1, sizeof(b));
		b[r1][c1] = 0;
		for (int m = 0; m < 8; ++m) {
			for (int r = 0; r < 8; ++r) {
				for (int c = 0; c < 8; ++c) {
					if (b[r][c] == m) {
						for (int i = 1; i <= 8; ++i) {
							for (int j = 0; j < 4; ++j) {
								int dx[] = { -1, -1, 1, 1 };
								int dy[] = { -1, 1, -1, 1 };
								int x = c + dx[j] * i, y = r + dy[j] * i;
								if (x >= 0 && y >= 0 && x < 8 && y < 8 && b[y][x] < 0) {
									b[y][x] = m + 1;
								}
							}
						}
					}
				}
			}
		}
		return b[r2][c2];
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
			int Arg0 = 4;
			int Arg1 = 6;
			int Arg2 = 7;
			int Arg3 = 3;
			int Arg4 = 1;

			verify_case(n, Arg4, howManyMoves(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 5;
			int Arg2 = 2;
			int Arg3 = 5;
			int Arg4 = 0;

			verify_case(n, Arg4, howManyMoves(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 3;
			int Arg2 = 5;
			int Arg3 = 5;
			int Arg4 = 2;

			verify_case(n, Arg4, howManyMoves(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 6;
			int Arg2 = 7;
			int Arg3 = 4;
			int Arg4 = -1;

			verify_case(n, Arg4, howManyMoves(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BishopMove ___test;
	___test.run_test(-1);
}
// END CUT HERE
