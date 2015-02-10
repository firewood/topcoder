// BEGIN CUT HERE
/*
SRM 648 Div2 Easy (250)

問題
-予算T円でりんごを買う
-1個目はK円、2個目は2K円、それ以降1個ごとに2倍になる
-買える最大の個数を求める

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class KitayutaMart2 {
public:
	int numBought(int K, int T) {
		int ans = 0;
		while (T >= K) {
			++ans;
			T -= K;
			K *= 2;
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
			int Arg0 = 100;
			int Arg1 = 100;
			int Arg2 = 1;

			verify_case(n, Arg2, numBought(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 100;
			int Arg1 = 300;
			int Arg2 = 2;

			verify_case(n, Arg2, numBought(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 150;
			int Arg1 = 1050;
			int Arg2 = 3;

			verify_case(n, Arg2, numBought(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 160;
			int Arg1 = 163680;
			int Arg2 = 10;

			verify_case(n, Arg2, numBought(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	KitayutaMart2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
