// BEGIN CUT HERE
/*
SRM 618 Div2 Easy (250)

問題
-携帯電話で文字列を入力する
-ボタンはひとつだけで、Aは1回、Zは26回押す必要がある
-与えられた文字列を入力するのに必要な回数を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class WritingWords {
public:
	int write(string word) {
		int ans = 0;
		for (char c : word) {
			ans += c - 'A' + 1;
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
			string Arg0 = "A";
			int Arg1 = 1;

			verify_case(n, Arg1, write(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ABC";
			int Arg1 = 6;

			verify_case(n, Arg1, write(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "VAMOSGIMNASIA";
			int Arg1 = 143;

			verify_case(n, Arg1, write(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "TOPCODER";
			int Arg1 = 96;

			verify_case(n, Arg1, write(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "SINGLEROUNDMATCH";
			int Arg1 = 183;

			verify_case(n, Arg1, write(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ";
			int Arg1 = 1300;

			verify_case(n, Arg1, write(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	WritingWords ___test;
	___test.run_test(-1);
}
// END CUT HERE
