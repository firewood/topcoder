// BEGIN CUT HERE
/*
SRM 609 Div2 Easy (250)

問題
-'<'と'>'だけからなる文字列がある
-連続するk個の'>'と連続するk個の'<'だけからなる文字列にしたい
-変更する個数を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class MagicalStringDiv2 {
public:
	int minimalMoves(string S) {
		int ans = 0;
		int len = (int)S.length();
		for (int i = 0; i < len / 2; ++i) {
			ans += S[i] != '>';
		}
		for (int i = len / 2; i < len; ++i) {
			ans += S[i] != '<';
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
			string Arg0 = ">><<><";
			int Arg1 = 2;

			verify_case(n, Arg1, minimalMoves(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = ">>>><<<<";
			int Arg1 = 0;

			verify_case(n, Arg1, minimalMoves(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "<<>>";
			int Arg1 = 4;

			verify_case(n, Arg1, minimalMoves(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "<><<<>>>>><<>>>>><>><<<>><><><><<><<<<<><<>>><><><";
			int Arg1 = 20;

			verify_case(n, Arg1, minimalMoves(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MagicalStringDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
