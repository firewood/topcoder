// BEGIN CUT HERE
/*
SRM 593 Div2 Medium (500)

問題
-数nを選び、n個のwとn個のoとn個のlとn個のfを連結する
-そのような文字列を1回以上連結する
-上記の操作でできる文字列かどうかを判定する

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class WolfDelaymaster {
public:
	string check(string str) {
		bool result = true;
		const char *s = str.c_str();
		string wolf = "wolf";
		while (*s) {
			int count[4] = {};
			for (int i = 0; i < 4; ++i) {
				while (*s && *s == wolf[i]) {
					++s;
					++count[i];
				}
				if (count[0] != count[i]) {
					result = false;
				}
			}
		}
		return result ? "VALID" : "INVALID";
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
			string Arg0 = "wolf";
			string Arg1 = "VALID";

			verify_case(n, Arg1, check(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "wwolfolf";
			string Arg1 = "INVALID";

			verify_case(n, Arg1, check(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "wolfwwoollffwwwooolllfffwwwwoooollllffff";
			string Arg1 = "VALID";

			verify_case(n, Arg1, check(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "flowolf";
			string Arg1 = "INVALID";

			verify_case(n, Arg1, check(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			string Arg0 = "wwwooolllff";
			string Arg1 = "INVALID";

			verify_case(n, Arg1, check(Arg0));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	WolfDelaymaster ___test;
	___test.run_test(-1);
}
// END CUT HERE
