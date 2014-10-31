// BEGIN CUT HERE
/*
SRM 613 Div2 Easy (250)

問題
-文字列Sが与えられる
-任意のアルファベットを全て除去することができる
-Sを“CAT”にできるかどうかを求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class TaroString {
public:
	string getAnswer(string S) {
		string s;
		for (char c : S) {
			switch (c) {
			case 'C':
			case 'A':
			case 'T':
				s += c;
				break;
			}
		}
		return s == "CAT" ? "Possible" : "Impossible";
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
			string Arg0 = "XCYAZTX";
			string Arg1 = "Possible";

			verify_case(n, Arg1, getAnswer(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "CTA";
			string Arg1 = "Impossible";

			verify_case(n, Arg1, getAnswer(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ACBBAT";
			string Arg1 = "Impossible";

			verify_case(n, Arg1, getAnswer(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "SGHDJHFIOPUFUHCHIOJBHAUINUIT";
			string Arg1 = "Possible";

			verify_case(n, Arg1, getAnswer(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "CCCATT";
			string Arg1 = "Impossible";

			verify_case(n, Arg1, getAnswer(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TaroString ___test;
	___test.run_test(-1);
}
// END CUT HERE
