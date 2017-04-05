// BEGIN CUT HERE
/*
TCO 2017 R1A Medium (500)

問題
-A×B×Cの大きさのチーズを切る
-どれかの面に平行に切る必要がある
-切断後の長さが整数の値であること
-3辺のうちいちばん小さい値を厚みとする
-残りの辺の積をチーズの面積とする
-厚みがS以上の塊に切るとき、面積の合計の最大値を求める

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

class CheeseSlicing {

	int s;
	int memo[101][101][101];
	int g(int a, int b, int c) {
		if (c < b) {
			swap(b, c);
		}
		if (b < a) {
			swap(a, b);
		}
		int &r = memo[a][b][c];
		if (r < 0) {
			r = a >= s ? b * c : 0;
			for (int i = s; (i + s) <= a; ++i) {
				r = max(r, g(i, b, c) + g(a - i, b, c));
			}
			for (int i = s; (i + s) <= b; ++i) {
				r = max(r, g(a, i, c) + g(a, b - i, c));
			}
			for (int i = s; (i + s) <= c; ++i) {
				r = max(r, g(a, b, i) + g(a, b, c - i));
			}
		}
		return r;
	}

public:
	int totalArea(int A, int B, int C, int S) {
		s = S;
		memset(memo, -1, sizeof(memo));
		return g(A, B, C);
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
			int Arg0 = 1;
			int Arg1 = 3;
			int Arg2 = 3;
			int Arg3 = 2;
			int Arg4 = 0;

			verify_case(n, Arg4, totalArea(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 3;
			int Arg2 = 5;
			int Arg3 = 3;
			int Arg4 = 25;

			verify_case(n, Arg4, totalArea(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 5;
			int Arg2 = 5;
			int Arg3 = 2;
			int Arg4 = 58;

			verify_case(n, Arg4, totalArea(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 49;
			int Arg1 = 92;
			int Arg2 = 20;
			int Arg3 = 3;
			int Arg4 = 30045;

			verify_case(n, Arg4, totalArea(Arg0, Arg1, Arg2, Arg3));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 100;
			int Arg1 = 100;
			int Arg2 = 100;
			int Arg3 = 2;
			int Arg4 = 4*50*50*50;

			verify_case(n, Arg4, totalArea(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 100;
			int Arg1 = 100;
			int Arg2 = 100;
			int Arg3 = 1;
			int Arg4 = 100 * 100 * 100;

			verify_case(n, Arg4, totalArea(Arg0, Arg1, Arg2, Arg3));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	CheeseSlicing ___test;
	___test.run_test(-1);
}
// END CUT HERE
