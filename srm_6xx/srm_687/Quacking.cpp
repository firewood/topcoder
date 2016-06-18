// BEGIN CUT HERE
/*
SRM 687 Div2 Medium (500)

問題
-アヒルは"quack"と鳴く
-何匹かの鳴き声が混ざった文字列が与えられる
-最低何匹いるかを求める

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

class Quacking {
public:
	int quack(string s) {
		int len = (int)s.length(), r = len;
		int u[2500] = {};
		const char quack[] = "quack";
		int ans = 0;
		while (r > 0) {
			++ans;
			int p = 0;
			for (int i = 0; i < len; ++i) {
				if (!u[i]) {
					if (s[i] == quack[p % 5]) {
						--r;
						u[i] = 1;
						++p;
					} else if (p == 0) {
						return -1;
					}
				}
			}
			if (p % 5) {
				return -1;
			}
		}
		return r > 0 ? -1 : ans;
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
			string Arg0 = "quqacukqauackck";
			int Arg1 = 2;

			verify_case(n, Arg1, quack(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "kcauq";
			int Arg1 = -1;

			verify_case(n, Arg1, quack(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "quackquackquackquackquackquackquackquackquackquack";
			int Arg1 = 1;

			verify_case(n, Arg1, quack(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "qqqqqqqqqquuuuuuuuuuaaaaaaaaaacccccccccckkkkkkkkkk";
			int Arg1 = 10;

			verify_case(n, Arg1, quack(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "quqaquuacakcqckkuaquckqauckack";
			int Arg1 = 3;

			verify_case(n, Arg1, quack(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "quackqauckquack";
			int Arg1 = -1;

			verify_case(n, Arg1, quack(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Quacking ___test;
	___test.run_test(-1);
}
// END CUT HERE
