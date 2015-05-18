// BEGIN CUT HERE
/*
SRM 655 Div2 Medium (500)

問題
-幅W高さHの長方形の紙を縦または横に折りたたむ
-整数の単位で折りたためる
-面積Aに折りたたむ最小手数を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class FoldingPaper2 {
public:
	int solve(int W, int H, int A) {
		int ans = -1;
		for (int h = 1; h <= A; ++h) {
			if (h > H) {
				break;
			}
			int w = A / h;
			if (w * h != A || w > W) {
				continue;
			}
			int c = 0, x = W, y = H;
			while (x > w) {
				x -= x / 2;
				c += 1;
			}
			while (y > h) {
				y -= y / 2;
				c += 1;
			}
			if (ans < 0) {
				ans = c;
			} else {
				ans = min(ans, c);
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
			int Arg0 = 5;
			int Arg1 = 3;
			int Arg2 = 12;
			int Arg3 = 1;

			verify_case(n, Arg3, solve(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 2;
			int Arg2 = 3;
			int Arg3 = -1;

			verify_case(n, Arg3, solve(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 4;
			int Arg2 = 1;
			int Arg3 = 4;

			verify_case(n, Arg3, solve(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 127;
			int Arg1 = 129;
			int Arg2 = 72;
			int Arg3 = 8;

			verify_case(n, Arg3, solve(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 100000;
			int Arg2 = 100000;
			int Arg3 = 0;

			verify_case(n, Arg3, solve(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 1;
			int Arg2 = 2;
			int Arg3 = -1;

			verify_case(n, Arg3, solve(Arg0, Arg1, Arg2));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 999999999;
			int Arg1 = 999999999;
			int Arg2 = 55566;
			int Arg3 = -1;

			verify_case(n, Arg3, solve(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FoldingPaper2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
