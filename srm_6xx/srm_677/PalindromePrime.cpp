// BEGIN CUT HERE
/*
SRM 677 Div2 Easy (250)

問題
-LからRまでの間にある左右対称な素数の総数を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class PalindromePrime {

	bool isPalindrome(int n) {
		stringstream ss;
		ss << n;
		string a = ss.str();
		string b = a;
		reverse(b.begin(), b.end());
		return a == b;
	}

public:
	int count(int L, int R) {
		int f[1001] = {}, s[1001] = {};
		int pars = 0;
		for (int n = 2; n < 1001; ++n) {
			if (!f[n]) {
				for (int i = n; i < 1001; i += n) {
					f[i] = 1;
				}
				pars += isPalindrome(n);
			}
			s[n] = pars;
		}
		return s[R] - s[L - 1];
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
			int Arg0 = 100;
			int Arg1 = 150;
			int Arg2 = 2;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 9;
			int Arg2 = 4;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 929;
			int Arg1 = 929;
			int Arg2 = 1;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 1;
			int Arg2 = 0;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 1000;
			int Arg2 = 20;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PalindromePrime ___test;
	___test.run_test(-1);
}
// END CUT HERE
