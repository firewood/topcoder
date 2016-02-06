// BEGIN CUT HERE
/*
SRM 680 Div2 Easy (250)

問題
-文字列s内で、異なる2文字の最大の長さを求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class BearPair {
public:
	int bigDistance(string s) {
		int ans = -1;
		for (int i = 0; i != s.length(); ++i) {
			for (int j = i + 1; j != s.length(); ++j) {
				if (s[i] != s[j]) {
					ans = max(ans, j - i);
				}
			}
		}
		return ans;
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
			string Arg0 = "bear";
			int Arg1 = 3;

			verify_case(n, Arg1, bigDistance(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abcba";
			int Arg1 = 3;

			verify_case(n, Arg1, bigDistance(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "oooohyeahpotato";
			int Arg1 = 13;

			verify_case(n, Arg1, bigDistance(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "zzzzzzzzzzzzzzzzzzzzz";
			int Arg1 = -1;

			verify_case(n, Arg1, bigDistance(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "qw";
			int Arg1 = 1;

			verify_case(n, Arg1, bigDistance(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "xxyyxyxyyyyyyxxxyxyxxxyxyxyyyyyxxxxxxyyyyyyyyxxxxx";
			int Arg1 = 47;

			verify_case(n, Arg1, bigDistance(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BearPair ___test;
	___test.run_test(-1);
}
// END CUT HERE
