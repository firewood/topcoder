// BEGIN CUT HERE
/*
TCO18 Fun Round Beijing Easy (250)

問題
-Jackは蛙を飼っている
-毎日距離DISTだけジャンプする
-ただしKの倍数の日だけはジャンプしない
-N日目に合計どれだけジャンプしたか求めよ

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

class JumpingJackDiv1 {
public:
	int getLocationOfJack(int dist, int k, int x) {
		int ans = 0;
		for (int i = 0; i <= x; ++i) {
			if (i % k) {
				ans += dist;
			}
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
			int Arg0 = 2;
			int Arg1 = 2;
			int Arg2 = 0;
			int Arg3 = 0;

			verify_case(n, Arg3, getLocationOfJack(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 2;
			int Arg2 = 1;
			int Arg3 = 2;

			verify_case(n, Arg3, getLocationOfJack(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 2;
			int Arg2 = 2;
			int Arg3 = 2;

			verify_case(n, Arg3, getLocationOfJack(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 2;
			int Arg2 = 3;
			int Arg3 = 4;

			verify_case(n, Arg3, getLocationOfJack(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 2;
			int Arg2 = 4;
			int Arg3 = 4;

			verify_case(n, Arg3, getLocationOfJack(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 7;
			int Arg2 = 10;
			int Arg3 = 27;

			verify_case(n, Arg3, getLocationOfJack(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 2;
			int Arg2 = 10;
			int Arg3 = 25;

			verify_case(n, Arg3, getLocationOfJack(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	JumpingJackDiv1 ___test;
	___test.run_test(-1);
}
// END CUT HERE
