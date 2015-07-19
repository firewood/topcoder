// BEGIN CUT HERE
/*

SRM 662 Div2 Easy (250)

問題
-バイナリを16進数表記にしたとき、読めそうなものがある
-0をO、1をIとして、16進数表記がO、I、A-Fだけからなる場合、その文字列を返す。

*/
// END CUT HERE
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class Hexspeak {
	public:
	string decode(long long ciphertext) {
		static const string hex = "OI********ABCDEF";
		string ans;
		while (ciphertext) {
			char c = hex[ciphertext & 15];
			ciphertext >>= 4;
			if (c == '*') {
				return "Error!";
			}
			ans = c + ans;
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
			long long Arg0 = 257LL;
			string Arg1 = "IOI";

			verify_case(n, Arg1, decode(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 258LL;
			string Arg1 = "Error!";

			verify_case(n, Arg1, decode(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 3405691582LL;
			string Arg1 = "CAFEBABE";

			verify_case(n, Arg1, decode(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 2882400001LL;
			string Arg1 = "ABCDEFOI";

			verify_case(n, Arg1, decode(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 999994830345994239LL;
			string Arg1 = "DEOBIFFFFFFFFFF";

			verify_case(n, Arg1, decode(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 1000000000000000000LL;
			string Arg1 = "Error!";

			verify_case(n, Arg1, decode(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Hexspeak ___test;
	___test.run_test(-1);
}
// END CUT HERE
