// BEGIN CUT HERE
/*
SRM 669 Div1 Easy (250)

問題
-大きさSのスライムがある
-1ターンで任意のスライムを選び、大きさxとyの二つに分割する
-その際スコアx×yが得られる
-スコアを計M以上得るための最小のターン数Kを求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class SubdividedSlimes {
public:
	int needCut(int S, int M) {
		for (int d = 2; d <= S; ++d) {
			int sum = 0, t = 0;
			int r = S % d;
			for (int i = 0; i < d; ++i) {
				int a = (S / d) + (i < r);
				sum += t * a;
				t += a;
			}
			if (sum >= M) {
				return d - 1;
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
			int Arg0 = 3;
			int Arg1 = 2;
			int Arg2 = 1;

			verify_case(n, Arg2, needCut(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 3;
			int Arg2 = 2;

			verify_case(n, Arg2, needCut(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 4;
			int Arg2 = -1;

			verify_case(n, Arg2, needCut(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 765;
			int Arg1 = 271828;
			int Arg2 = 14;

			verify_case(n, Arg2, needCut(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SubdividedSlimes ___test;
	___test.run_test(-1);
}
// END CUT HERE
