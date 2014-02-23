// BEGIN CUT HERE
/*
SRM 598 Div2 Easy (250)

問題
-誕生日に文字列をもらった
-長すぎるので、連続する2文字を削除していくことにした
-最終的に得られる文字列を求める

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class ErasingCharacters {
public:
	string simulate(string s) {
		bool found = true;
		while (found) {
			found = false;
			for (int i = 0; i < (int)s.length()-1; ++i) {
				if (s[i] == s[i+1]) {
					s = s.substr(0, i) + s.substr(i+2);
					found = true;
					break;
				}
			}
		}
		return s;
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
			string Arg0 = "cieeilll";
			string Arg1 = "cl";

			verify_case(n, Arg1, simulate(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "topcoder";
			string Arg1 = "topcoder";

			verify_case(n, Arg1, simulate(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abcdefghijklmnopqrstuvwxyyxwvutsrqponmlkjihgfedcba";
			string Arg1 = "";

			verify_case(n, Arg1, simulate(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "bacaabaccbaaccabbcabbacabcbba";
			string Arg1 = "bacbaca";

			verify_case(n, Arg1, simulate(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "eel";
			string Arg1 = "l";

			verify_case(n, Arg1, simulate(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ErasingCharacters ___test;
	___test.run_test(-1);
}
// END CUT HERE
