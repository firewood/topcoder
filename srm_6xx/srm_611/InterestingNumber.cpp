// BEGIN CUT HERE
/*
SRM 611 Div2 Easy (250)

問題
-41312432は面白い数である
-1の間に1個の数があり、2の間に2個の数がある
-数値Xが与えられる
-Xの各桁Dについて、同じ数値が2個だけ出現し、かつ、その間にD個の数があるかどうかを求める

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class InterestingNumber {
public:

	bool check(string x) {
		for (int i = 0; i <= 9; ++i) {
			char c = i + '0';
			int a = x.find(c);
			int b = x.rfind(c);
			if (a < 0) {
				continue;
			}
			if (b - a != i + 1) {
				return false;
			}
			for (int j = a + 1; j < b; ++j) {
				if (x[j] == c) {
					return false;
				}
			}
		}
		return true;
	}

	string isInteresting(string x) {
		return check(x) ? "Interesting" : "Not interesting";
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
			string Arg0 = "2002";
			string Arg1 = "Interesting";

			verify_case(n, Arg1, isInteresting(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "1001";
			string Arg1 = "Not interesting";

			verify_case(n, Arg1, isInteresting(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "41312432";
			string Arg1 = "Interesting";

			verify_case(n, Arg1, isInteresting(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "611";
			string Arg1 = "Not interesting";

			verify_case(n, Arg1, isInteresting(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "64200246";
			string Arg1 = "Interesting";

			verify_case(n, Arg1, isInteresting(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "631413164";
			string Arg1 = "Not interesting";

			verify_case(n, Arg1, isInteresting(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	InterestingNumber ___test;
	___test.run_test(-1);
}
// END CUT HERE
