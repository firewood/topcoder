// BEGIN CUT HERE
/*
SRM 605 Div2 Easy (250)

問題
-エイリアンのフレッドは地球を破壊しようとしている
-しかし惑星破壊装置を起動するパスワードを忘れてしまった
-文字列Sが与えられる
-Sから1文字削除すると正しいパスワードになる
-異なるパスワードが何通り生成できるか求める

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef set<string> StrSet;

class AlienAndPassword {
public:
	int getNumber(string S) {
		StrSet s;
		for (auto i = 0; i < S.length(); ++i) {
			s.insert(S.substr(0, i) + S.substr(i + 1));
		}
		return s.size();
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
			string Arg0 = "A";
			int Arg1 = 1;

			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ABA";
			int Arg1 = 3;

			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "AABACCCCABAA";
			int Arg1 = 7;

			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "AGAAGAHHHHFTQLLAPUURQQRRRUFJJSBSZVJZZZ";
			int Arg1 = 26;

			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ";
			int Arg1 = 1;

			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	AlienAndPassword ___test;
	___test.run_test(-1);
}
// END CUT HERE
