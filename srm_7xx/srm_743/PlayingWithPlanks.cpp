// BEGIN CUT HERE
/*
SRM 743 Div2 Easy (250)

問題
-長さがplankLengthの木材がある
-全ての長さが整数かつ異なるように切るとき、pieces本に分割できるかどうかを求めよ

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class PlayingWithPlanks {
public:
	string canItBeDone(int plankLength, int pieces) {
		int i;
		for (i = 1; i <= plankLength; ++i) {
			plankLength -= i;
		}
		return i > pieces ? "possible" : "impossible";
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
			int Arg0 = 9;
			int Arg1 = 3;
			string Arg2 = "possible";

			verify_case(n, Arg2, canItBeDone(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 12;
			int Arg1 = 1;
			string Arg2 = "possible";

			verify_case(n, Arg2, canItBeDone(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 9;
			int Arg1 = 4;
			string Arg2 = "impossible";

			verify_case(n, Arg2, canItBeDone(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arg1 = 4;
			string Arg2 = "possible";

			verify_case(n, Arg2, canItBeDone(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 750932;
			int Arg1 = 901;
			string Arg2 = "possible";

			verify_case(n, Arg2, canItBeDone(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 54;
			int Arg1 = 10;
			string Arg2 = "impossible";

			verify_case(n, Arg2, canItBeDone(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PlayingWithPlanks ___test;
	___test.run_test(-1);
}
// END CUT HERE
