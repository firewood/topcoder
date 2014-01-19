// BEGIN CUT HERE
/*
SRM 589 Div2 Medium (500)

問題
-N個のギアがある
-最後のギアと最初のギアはつながっている
-ギアの向きが与えられる
-全てのギアがまわるようにするために取り除かなければならない個数を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class GearsDiv2 {
public:
	int getmin(string Directions) {
		int a = 0;
		string s = Directions;
		s += Directions[0];
		for (int i = 1; i < (int)s.length(); ++i) {
			if (s[i-1] == s[i]) {
				++a;
				s[i] = 'x';
			}
		}

		int b = 1;
		s = Directions;
		for (int i = 2; i < (int)s.length(); ++i) {
			if (s[i-1] == s[i]) {
				++b;
				s[i] = 'x';
			}
		}

		return min(a, b);
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
			string Arg0 = "LRRR";
			int Arg1 = 1;

			verify_case(n, Arg1, getmin(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "RRR";
			int Arg1 = 2;

			verify_case(n, Arg1, getmin(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "LRLR";
			int Arg1 = 0;

			verify_case(n, Arg1, getmin(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "LRLLRRLLLRRRLLLL";
			int Arg1 = 6;

			verify_case(n, Arg1, getmin(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "RRRRRRRLRRRRRRRLRLRLLRLRLRLRRLRLRLLLRLRLLRLLRRLRRR";
			int Arg1 = 14;

			verify_case(n, Arg1, getmin(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			string Arg0 = "RRRRLLLRLLR";
			int Arg1 = 4;

			verify_case(n, Arg1, getmin(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	GearsDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
