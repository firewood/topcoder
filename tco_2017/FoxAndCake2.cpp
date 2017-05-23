// BEGIN CUT HERE
/*
TCO 2017 R2A Easy (250)

問題
-C個のさくらんぼとS個のいちごがある
-1個以上のさくらんぼと1個以上のいちごを使っていくつかのケーキを作る
-ただし個数が互いに素でないこと
-さくらんぼといちごを使い切ることが可能かどうかを求める

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class FoxAndCake2 {

	bool possible(int c, int s) {
		if (c > s) {
			swap(c, s);
		}
		switch (c) {
		case 0:
		case 1:
			return false;
		case 2:
		case 4:
			return s % 2 == 0;
		case 3:
			return s % 3 == 0;
		case 5:
			return s != 6;
		case 6:
			return (s % 6) != 1 && (s % 6) != 5;
		}
		return true;
	}

public:
	string isPossible(int c, int s) {
		return possible(c, s) ? "Possible" : "Impossible";
	}

private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 74;
			int Arg1 = 109;
			string Arg2 = "Possible";

			verify_case(n, Arg2, isPossible(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1000000000;
			int Arg1 = 1000000000;
			string Arg2 = "Possible";

			verify_case(n, Arg2, isPossible(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 58;
			string Arg2 = "Impossible";

			verify_case(n, Arg2, isPossible(Arg0, Arg1));
		}
		n++;
	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FoxAndCake2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
