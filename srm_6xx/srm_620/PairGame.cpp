// BEGIN CUT HERE
/*
SRM 620 Div1 Easy (250)

問題
-1以上の二つの整数のペアx,yがある
-次のターンで(x+y,y)か(x,x+y)のどちらかにできる
-(x,y)からはじめて(a,b)と(c,d)のどちらにでも到達できる数のうちx+yの最大値を求める

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class PairGame {

public:
	int maxSum(int a, int b, int c, int d) {
		while (a > 0 && b > 0 && c > 0 && d > 0) {
			if (a == c && b == d) {
				return a + b;
			}
			if (a > c || b > d) {
				if (a > b){
					a -= b;
				} else {
					b -= a;
				}
			} else {
				if (c > d) {
					c -= d;
				} else {
					d -= c;
				}
			}
		}
		return -1;
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
			int Arg1 = 2;
			int Arg2 = 2;
			int Arg3 = 1;
			int Arg4 = 2;

			verify_case(n, Arg4, maxSum(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 15;
			int Arg1 = 4;
			int Arg2 = 10;
			int Arg3 = 7;
			int Arg4 = 7;

			verify_case(n, Arg4, maxSum(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 1;
			int Arg2 = 10;
			int Arg3 = 10;
			int Arg4 = -1;

			verify_case(n, Arg4, maxSum(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1000;
			int Arg1 = 1001;
			int Arg2 = 2000;
			int Arg3 = 2001;
			int Arg4 = 1001;

			verify_case(n, Arg4, maxSum(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10944;
			int Arg1 = 17928;
			int Arg2 = 7704;
			int Arg3 = 21888;
			int Arg4 = 144;

			verify_case(n, Arg4, maxSum(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 1;
			int Arg2 = 1;
			int Arg3 = 1;
			int Arg4 = 2;

			verify_case(n, Arg4, maxSum(Arg0, Arg1, Arg2, Arg3));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 1000000;
			int Arg2 = 1;
			int Arg3 = 6;
			int Arg4 = 7;

			verify_case(n, Arg4, maxSum(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 1000000;
			int Arg2 = 1000000;
			int Arg3 = 1;
			int Arg4 = 2;

			verify_case(n, Arg4, maxSum(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 1;
			int Arg2 = 1000000;
			int Arg3 = 999998;
			int Arg4 = -1;

			verify_case(n, Arg4, maxSum(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arg0 = 1000000;
			int Arg1 = 1;
			int Arg2 = 999999;
			int Arg3 = 2;
			int Arg4 = 2;

			verify_case(n, Arg4, maxSum(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 999999;
			int Arg2 = 2;
			int Arg3 = 1000000;
			int Arg4 = -1;

			verify_case(n, Arg4, maxSum(Arg0, Arg1, Arg2, Arg3));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PairGame ___test;
	___test.run_test(-1);
}
// END CUT HERE
