// BEGIN CUT HERE
/*
SRM 583 Div2 Easy (250)

問題
-数値が文字列として与えられる
-任意の2桁の数値を交換して、最小の数値を求める
-ただし先頭は0とならないこと

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class SwappingDigits {
public:
	string minNumber(string num) {
		string ans = num;
		int len = num.length();
		for (int i = 0; i < len; ++i) {
			for (int j = i + 1; j < len; ++j) {
				if (i == 0 && num[j] == '0') {
					continue;
				}
				string s = num;
				s[i] = num[j], s[j] = num[i];
				if (s < ans) {
					ans = s;
				}
			}
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
			string Arg0 = "596";
			string Arg1 = "569";

			verify_case(n, Arg1, minNumber(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "93561";
			string Arg1 = "13569";

			verify_case(n, Arg1, minNumber(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "5491727514";
			string Arg1 = "1491727554";

			verify_case(n, Arg1, minNumber(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "10234";
			string Arg1 = "10234";

			verify_case(n, Arg1, minNumber(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "93218910471211292416";
			string Arg1 = "13218910471211292496";

			verify_case(n, Arg1, minNumber(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SwappingDigits ___test;
	___test.run_test(-1);
}
// END CUT HERE
