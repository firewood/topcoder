// BEGIN CUT HERE
/*
SRM 663 Div1 Easy (250)

問題
-文字列initialが与えられる
-文字Aを末尾に加えるか、文字Bを末尾に加えて全体を反転する
-文字列targetにできるかどうかを求める

*/
// END CUT HERE
#include <algorithm>
#include <cstring>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class ABBADiv1 {

	string init;
	string t;
	int init_len;
	int target_len;

	bool dfs(int dir, int st, int ed) {
		int len = ed - st;
		if (len == init_len) {
			string s = t.substr(st, init_len);
			if (dir) {
				reverse(s.begin(), s.end());
			}
			return init == s;
		}
		bool result = false;
		if (len > init_len) {
			if (!dir) {
				if (t[st] == 'B') {
					result |= dfs(1, st + 1, ed);
				}
				if (t[ed - 1] == 'A') {
					result |= dfs(0, st, ed - 1);
				}
			} else {
				if (t[ed - 1] == 'B') {
					result |= dfs(0, st, ed - 1);
				}
				if (t[st] == 'A') {
					result |= dfs(1, st + 1, ed);
				}
			}
		}
		return result;
	}

public:
	string canObtain(string initial, string target) {
		init = initial;
		t = target;
		init_len = initial.length();
		target_len = target.length();
		return dfs(0, 0, target_len) ? "Possible" : "Impossible";
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
			string Arg0 = "A";
			string Arg1 = "BABA";
			string Arg2 = "Possible";

			verify_case(n, Arg2, canObtain(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "BAAAAABAA";
			string Arg1 = "BAABAAAAAB";
			string Arg2 = "Possible";

			verify_case(n, Arg2, canObtain(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "A";
			string Arg1 = "ABBA";
			string Arg2 = "Impossible";

			verify_case(n, Arg2, canObtain(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "AAABBAABB";
			string Arg1 = "BAABAAABAABAABBBAAAAAABBAABBBBBBBABB";
			string Arg2 = "Possible";

			verify_case(n, Arg2, canObtain(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "AAABAAABB";
			string Arg1 = "BAABAAABAABAABBBAAAAAABBAABBBBBBBABB";
			string Arg2 = "Impossible";

			verify_case(n, Arg2, canObtain(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			string Arg0 = "B";
			string Arg1 = "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB";
			string Arg2 = "Possible";

			verify_case(n, Arg2, canObtain(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ABBADiv1 ___test;
	___test.run_test(-1);
}
// END CUT HERE
