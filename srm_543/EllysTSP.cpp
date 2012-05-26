// BEGIN CUT HERE
/*
// SRM 543 Div2 Easy (250)

問題
町と村の数が与えられる
町と村を交互に移動する場合、最大何回移動できるかを求める

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class EllysTSP {

public:
	int getMax(string places) {
		int c[256] = {};
		for (int i = 0; i < (int)places.length(); ++i) {
			c[places[i]] += 1;
		}
		int Min = min(c['C'], c['V']);
		int Max = max(c['C'], c['V']);
		return Min + min(Min+1, Max);
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
			string Arg0 = "CVVVC";
			int Arg1 = 5;

			verify_case(n, Arg1, getMax(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "VVV";
			int Arg1 = 1;

			verify_case(n, Arg1, getMax(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "VVVVCVV";
			int Arg1 = 3;

			verify_case(n, Arg1, getMax(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "CVCVCVC";
			int Arg1 = 7;

			verify_case(n, Arg1, getMax(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "V";
			int Arg1 = 1;

			verify_case(n, Arg1, getMax(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			string Arg0 = "CVVC";
			int Arg1 = 4;

			verify_case(n, Arg1, getMax(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EllysTSP ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
