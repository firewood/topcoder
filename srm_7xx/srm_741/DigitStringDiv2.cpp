// BEGIN CUT HERE
/*
SRM 741 Div2 Easy (250)

問題
-文字列Sと数値Xが与えられる
-Sの連続する部分を取り出した文字列のうち先頭が0でなくXより大きいものの個数を求めよ

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class DigitStringDiv2 {
public:
	int count(string S, int X) {
		int len = (int)S.length();
		int ans = 0;
		for (int i = 0; i < len; ++i) {
			if (S[i] != '0') {
				int k = 0;
				for (int j = i; j < len; ++j) {
					k = k * 10 + S[j] - '0';
					ans += k > X;
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
			string Arg0 = "0";
			int Arg1 = 1;
			int Arg2 = 0;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "10";
			int Arg1 = 9;
			int Arg2 = 1;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "471";
			int Arg1 = 47;
			int Arg2 = 2;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "2222";
			int Arg1 = 97;
			int Arg2 = 3;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DigitStringDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
