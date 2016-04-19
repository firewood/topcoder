// BEGIN CUT HERE
/*
SRM 668 Div1 Easy (250)

問題
-R×Cの升目がある
-1升ずつ移動して、全ての升目をちょうどK回通ることができるかどうかを求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class PaintTheRoom {
public:
	string canPaintEvenly(int R, int C, int K) {
		return K <= 1 || ((R * C) % 2) == 0 ? "Paint" : "Cannot paint";
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
			int Arg0 = 1;
			int Arg1 = 1;
			int Arg2 = 1;
			string Arg3 = "Paint";

			verify_case(n, Arg3, canPaintEvenly(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 1;
			int Arg2 = 2;
			string Arg3 = "Cannot paint";

			verify_case(n, Arg3, canPaintEvenly(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 2;
			int Arg2 = 2;
			string Arg3 = "Paint";

			verify_case(n, Arg3, canPaintEvenly(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 2;
			int Arg2 = 3;
			string Arg3 = "Paint";

			verify_case(n, Arg3, canPaintEvenly(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PaintTheRoom ___test;
	___test.run_test(-1);
}
// END CUT HERE
