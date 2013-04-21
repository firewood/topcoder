// BEGIN CUT HERE
/*
SRM 575 Div1 Easy (250)

問題
-数nをめぐって2人で交互にゲームをする
-数nから、1とn以外の約数を引くことができる
-引けなくなったら負け
-最適手において先手必勝かどうかを求める

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class TheNumberGameDivOne {

public:
	string find(long long n) {
		while (n % 8 == 0) {
			n /= 4;
		}
		return (n % 2) == 0 && n != 2 ? "John" : "Brus";
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
			long long Arg0 = 6LL;
			string Arg1 = "John";

			verify_case(n, Arg1, find(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 2LL;
			string Arg1 = "Brus";

			verify_case(n, Arg1, find(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 747LL;
			string Arg1 = "Brus";

			verify_case(n, Arg1, find(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 128LL;
			string Arg1 = "Brus";

			verify_case(n, Arg1, find(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			long long Arg0 = 4LL;
			string Arg1 = "John";
			verify_case(n, Arg1, find(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			long long Arg0 = 8LL;
			string Arg1 = "Brus";
			verify_case(n, Arg1, find(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			long long Arg0 = 16LL;
			string Arg1 = "John";
			verify_case(n, Arg1, find(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			long long Arg0 = 32LL;
			string Arg1 = "Brus";
			verify_case(n, Arg1, find(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			long long Arg0 = 64LL;
			string Arg1 = "John";
			verify_case(n, Arg1, find(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TheNumberGameDivOne ___test;
	___test.run_test(-1);
}
// END CUT HERE
