// BEGIN CUT HERE
/*
TCO18 R1A Easy (250)

問題
-宿屋にN人いて、コインがC枚ある
-半分(端数切り上げ)のコインを宿屋が取る
-残りのコインのうち、Nで割り切れる部分を、N人に均等にわける
-残りを宿屋が取る
-各人の取り分がX枚だったとき、Cの最大値を求めよ

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

class RedDragonInn {
public:
	int maxGold(int N, int X) {
		int t;
		for (t = N * X; ; ++t) {
			int r = t / 2;
			int c = r / N;
			if (c > X) {
				break;
			}
		}
		return t - 1;
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
			int Arg2 = 17;

			verify_case(n, Arg2, maxGold(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 8;
			int Arg1 = 13;
			int Arg2 = 223;

			verify_case(n, Arg2, maxGold(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 42;
			int Arg1 = 1234;
			int Arg2 = 103739;

			verify_case(n, Arg2, maxGold(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	RedDragonInn ___test;
	___test.run_test(-1);
}
// END CUT HERE
