// BEGIN CUT HERE
/*
SRM 587 Div1 Medium (550)

問題
-高さ1、幅Wの長方形に三角形をXORで塗っていく
-面積の整数部分を求める

*/
// END CUT HERE
#include <algorithm>
#include <numeric>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class TriangleXor {
public:
	int theArea(int W) {
		double w = W;
		double sum = w * (w+1) * 0.5;
		double sign = -1.0;
		for (int i = 1; i <= W; ++i) {
			double h = 1.0 - i / (w + i);
			sum += w * h * 0.5 * (w - i + 1) * 2.0 * sign;
			sign = -sign;
		}
		return (int)sum;
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
			int Arg1 = 0;

			verify_case(n, Arg1, theArea(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 1;

			verify_case(n, Arg1, theArea(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 1;

			verify_case(n, Arg1, theArea(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 2;

			verify_case(n, Arg1, theArea(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 2;

			verify_case(n, Arg1, theArea(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 12345;
			int Arg1 = 4629;

			verify_case(n, Arg1, theArea(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 62678;
			int Arg1 = 39173;

			verify_case(n, Arg1, theArea(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TriangleXor ___test;
	___test.run_test(-1);
}
// END CUT HERE
