// BEGIN CUT HERE
/*
SRM 698 Div2 Easy (250)

問題
-単語を空白で区切った文字列が与えられる
-各単語の頭文字を結合したものを求める

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

class Initials {
public:
	string getInitials(string name) {
		string ans;
		char prev = ' ';
		for (char c : name) {
			if (prev == ' ') {
				ans += c;
			}
			prev = c;
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
			string Arg0 = "john fitzgerald kennedy";
			string Arg1 = "jfk";

			verify_case(n, Arg1, getInitials(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "single";
			string Arg1 = "s";

			verify_case(n, Arg1, getInitials(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "looks good to me";
			string Arg1 = "lgtm";

			verify_case(n, Arg1, getInitials(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "single round match";
			string Arg1 = "srm";

			verify_case(n, Arg1, getInitials(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "a aa aaa aa a bbb bb b bb bbb";
			string Arg1 = "aaaaabbbbb";

			verify_case(n, Arg1, getInitials(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Initials ___test;
	___test.run_test(-1);
}
// END CUT HERE
