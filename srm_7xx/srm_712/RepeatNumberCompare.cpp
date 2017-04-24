// BEGIN CUT HERE
/*
SRM 712 Div2 Easy (250)

問題
-v1を数x1をk1回繰り返した数値、v2を数x2をk2回繰り返した数値とする
-v1とv2の大小関係を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class RepeatNumberCompare {
public:
	string compare(int x1, int k1, int x2, int k2) {
		string a, b;
		stringstream sa, sb;
		for (int i = 0; i < k1; ++i) {
			sa << x1;
		}
		sa >> a;
		for (int i = 0; i < k2; ++i) {
			sb << x2;
		}
		sb >> b;
		string ans;
		if (a == b) {
			ans = "Equal";
		} else if (a.length() < b.length()) {
			ans = "Less";
		} else if (a.length() > b.length()) {
			ans = "Greater";
		} else {
			ans = a < b ? "Less" : "Greater";
		}
		return ans;
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
			int Arg0 = 1234;
			int Arg1 = 3;
			int Arg2 = 70;
			int Arg3 = 4;
			string Arg4 = "Greater";

			verify_case(n, Arg4, compare(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1010;
			int Arg1 = 3;
			int Arg2 = 101010;
			int Arg3 = 2;
			string Arg4 = "Equal";

			verify_case(n, Arg4, compare(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1234;
			int Arg1 = 10;
			int Arg2 = 456;
			int Arg3 = 20;
			string Arg4 = "Less";

			verify_case(n, Arg4, compare(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 9;
			int Arg2 = 555555555;
			int Arg3 = 1;
			string Arg4 = "Equal";

			verify_case(n, Arg4, compare(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 9;
			int Arg2 = 555555554;
			int Arg3 = 1;
			string Arg4 = "Greater";

			verify_case(n, Arg4, compare(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 9;
			int Arg2 = 555555556;
			int Arg3 = 1;
			string Arg4 = "Less";

			verify_case(n, Arg4, compare(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1000000000;
			int Arg1 = 50;
			int Arg2 = 1000000000;
			int Arg3 = 50;
			string Arg4 = "Equal";

			verify_case(n, Arg4, compare(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	RepeatNumberCompare ___test;
	___test.run_test(-1);
}
// END CUT HERE
