// BEGIN CUT HERE
/*
TCO 2014 Round 1A Easy (250)

問題
-文字列を変更する装置がある
-先頭のN文字をそのまま、途中のL文字をソートして、末尾を削除できる
-何回でも適用できる
-適用結果のうちの辞書順最小のものを求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class EllysSortingTrimmer {
public:
	string getMin(string S, int L) {
		for (int i = S.length() - L; i >= 0; --i) {
			sort(S.begin() + i, S.begin() + i + L);
		}
		return S.substr(0, L);
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
			string Arg0 = "ABRACADABRA";
			int Arg1 = 5;
			string Arg2 = "AAAAA";

			verify_case(n, Arg2, getMin(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ESPRIT";
			int Arg1 = 3;
			string Arg2 = "EIP";

			verify_case(n, Arg2, getMin(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "BAZINGA";
			int Arg1 = 7;
			string Arg2 = "AABGINZ";

			verify_case(n, Arg2, getMin(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
			int Arg1 = 13;
			string Arg2 = "ABCDEFGHIJKLM";

			verify_case(n, Arg2, getMin(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "GOODLUCKANDHAVEFUN";
			int Arg1 = 10;
			string Arg2 = "AACDDEFGHK";

			verify_case(n, Arg2, getMin(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "AAAWDIUAOIWDESBEAIWODJAWDBPOAWDUISAWDOOPAWD";
			int Arg1 = 21;
			string Arg2 = "AAAAAAAAABBDDDDDDDEEI";

			verify_case(n, Arg2, getMin(Arg0, Arg1));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			string Arg0 = "TOPCODER";
			int Arg1 = 3;
			string Arg2 = "CDT";

			verify_case(n, Arg2, getMin(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EllysSortingTrimmer ___test;
	___test.run_test(-1);
}
// END CUT HERE
