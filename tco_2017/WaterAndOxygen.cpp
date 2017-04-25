// BEGIN CUT HERE
/*
TCO 2017 R1B Easy (250)

問題
-宇宙船の中にいる
-毎日costH2Oの水とcostO2の酸素を消費する
-remainH2Oの水とremainO2の酸素がタンクにある
-水を電気分解して、半分の量の酸素を作ることができる
-何日間生き残れるかを求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class WaterAndOxygen {
public:
	double maxDays(int remainH20, int remainO2, int costH2O, int costO2) {
		double ans = min(1.0 * remainH20 / costH2O, 1.0 * remainO2 / costO2);
		ans += (remainH20 - ans * costH2O) / (costH2O + costO2 * 2.0);
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 64;
			int Arg1 = 70;
			int Arg2 = 3;
			int Arg3 = 7;
			double Arg4 = 12.0;

			verify_case(n, Arg4, maxDays(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 99;
			int Arg1 = 102;
			int Arg2 = 1;
			int Arg3 = 1;
			double Arg4 = 99.0;

			verify_case(n, Arg4, maxDays(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 101;
			int Arg1 = 99;
			int Arg2 = 1;
			int Arg3 = 1;
			double Arg4 = 99.66666666666667;

			verify_case(n, Arg4, maxDays(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 123456789;
			int Arg1 = 987654321;
			int Arg2 = 123;
			int Arg3 = 456;
			double Arg4 = 1003713.731707317;

			verify_case(n, Arg4, maxDays(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 987654321;
			int Arg1 = 123456789;
			int Arg2 = 456;
			int Arg3 = 123;
			double Arg4 = 1758643.7307692308;

			verify_case(n, Arg4, maxDays(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 0;
			int Arg1 = 0;
			int Arg2 = 13;
			int Arg3 = 27;
			double Arg4 = 0.0;

			verify_case(n, Arg4, maxDays(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	WaterAndOxygen ___test;
	___test.run_test(-1);
}
// END CUT HERE
