// BEGIN CUT HERE
/*
SRM 665 Div2 Easy (250)

問題
-各桁が4か7だけからなる数がラッキーナンバー
-数aが与えられる
-a XOR bがラッキーナンバーとなる1以上100以下のbがあるかどうか求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class LuckyXor {

	inline bool isLucky(int a) {
		while (a > 0) {
			int r = a % 10;
			if (r != 4 && r != 7) {
				return false;
			}
			a /= 10;
		}
		return true;
	}

public:
	int construct(int a) {
		for (int b = a + 1; b <= 100; ++b) {
			if (isLucky(a ^ b)) {
				return b;
			}
		}
		return -1;
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
			int Arg0 = 4;
			int Arg1 = 40;

			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 19;
			int Arg1 = 20;

			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 88;
			int Arg1 = 92;

			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 36;
			int Arg1 = -1;

			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	LuckyXor ___test;
	___test.run_test(-1);
}
// END CUT HERE
