// BEGIN CUT HERE
/*
SRM 708 Div2 Easy (250)

問題
-Limakはカジノに来ている
-bドル持っている
-いかなる瞬間にもaドルを下回りたくない
-賭けに勝つと掛け金が2倍になって返ってくる
-cドルにするための最小回数を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class SafeBetting {
	public:
	int minRounds(int a, int b, int c) {
		int ans = 0;
		while (b < c) {
			++ans;
			b += (b - a);
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
			int Arg0 = 15;
			int Arg1 = 20;
			int Arg2 = 48;
			int Arg3 = 3;

			verify_case(n, Arg3, minRounds(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arg1 = 400;
			int Arg2 = 560;
			int Arg3 = 1;

			verify_case(n, Arg3, minRounds(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 7;
			int Arg2 = 21;
			int Arg3 = 3;

			verify_case(n, Arg3, minRounds(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 7;
			int Arg2 = 22;
			int Arg3 = 4;

			verify_case(n, Arg3, minRounds(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 17;
			int Arg1 = 30;
			int Arg2 = 1000;
			int Arg3 = 7;

			verify_case(n, Arg3, minRounds(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SafeBetting ___test;
	___test.run_test(-1);
}
// END CUT HERE
