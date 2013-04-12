// BEGIN CUT HERE
/*
SRM 574 Div1 Easy (275)

問題
-2人でそれぞれ任意の数値を決めてゲームをする
-交互にターンが来たら、数字を反転するか1/10する
-同じ数になったら先手の勝ち
-最善手で先手が勝つかどうかを求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class TheNumberGame {

public:
	string determineOutcome(int A, int B) {
		char a[64];
		sprintf(a, "%d", A);
		char b[64];
		sprintf(b, "%d", B);
		string r = a;
		reverse(r.begin(), r.end());
		return (strstr(a, b) != NULL || strstr(r.c_str(), b) != NULL)
				? "Manao wins" : "Manao loses";
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
			int Arg0 = 45;
			int Arg1 = 4;
			string Arg2 = "Manao wins";

			verify_case(n, Arg2, determineOutcome(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 45;
			int Arg1 = 5;
			string Arg2 = "Manao wins";

			verify_case(n, Arg2, determineOutcome(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 99;
			int Arg1 = 123;
			string Arg2 = "Manao loses";

			verify_case(n, Arg2, determineOutcome(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2356236;
			int Arg1 = 5666;
			string Arg2 = "Manao loses";

			verify_case(n, Arg2, determineOutcome(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 12345;
			int Arg1 = 54321;
			string Arg2 = "Manao wins";

			verify_case(n, Arg2, determineOutcome(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arg0 = 12345;
			int Arg1 = 12345;
			string Arg2 = "Manao wins";

			verify_case(n, Arg2, determineOutcome(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 11112;
			int Arg1 = 112;
			string Arg2 = "Manao wins";

			verify_case(n, Arg2, determineOutcome(Arg0, Arg1));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TheNumberGame ___test;
	___test.run_test(-1);
}
// END CUT HERE
