// BEGIN CUT HERE
/*
// SRM 559 Div1 Easy (250)

問題
チェス盤の大きさと(±a,±b)で動けるナイトが与えられる。
移動可能な先がちょうどk箇所ある升目の総数を求める。

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

class HyperKnight {

public:
	long long countCells(int a, int b, int numRows, int numColumns, int k) {
		LL res = 0;
		LL A = min(a, b);
		LL B = max(a, b);
		LL H = numRows;
		LL W = numColumns;
		LL dx[] = {A,A,-A,-A,B,B,-B,-B};
		LL dy[] = {B,-B,B,-B,A,-A,A,-A};
		LL bh[] = {0,A,B,H-B,H-A,H};
		LL bw[] = {0,A,B,W-B,W-A,W};
		int i, j, l, c;
		for (i = 0; i < 5; ++i) {
			for (j = 0; j < 5; ++j) {
				c = 0;
				for (l = 0; l < 8; ++l) {
					LL x = bw[j] + dx[l];
					LL y = bh[i] + dy[l];
					if (x >= 0 && x < W && y >= 0 && y < H) {
						++c;
					}
				}
				if (c == k) {
					res += (bh[i+1] - bh[i]) * (bw[j+1] - bw[j]);
				}
			}
		}
		return res;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 1;
			int Arg2 = 8;
			int Arg3 = 8;
			int Arg4 = 4;
			long long Arg5 = 20LL;

			verify_case(n, Arg5, countCells(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 2;
			int Arg2 = 8;
			int Arg3 = 8;
			int Arg4 = 2;
			long long Arg5 = 16LL;

			verify_case(n, Arg5, countCells(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 3;
			int Arg2 = 7;
			int Arg3 = 11;
			int Arg4 = 0;
			long long Arg5 = 0LL;

			verify_case(n, Arg5, countCells(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 2;
			int Arg2 = 10;
			int Arg3 = 20;
			int Arg4 = 8;
			long long Arg5 = 56LL;

			verify_case(n, Arg5, countCells(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 4;
			int Arg2 = 100;
			int Arg3 = 10;
			int Arg4 = 6;
			long long Arg5 = 564LL;

			verify_case(n, Arg5, countCells(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 3;
			int Arg2 = 1000000000;
			int Arg3 = 1000000000;
			int Arg4 = 8;
			long long Arg5 = 999999988000000036LL;

			verify_case(n, Arg5, countCells(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	HyperKnight ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
