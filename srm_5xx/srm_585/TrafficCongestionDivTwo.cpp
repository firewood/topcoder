// BEGIN CUT HERE
/*
SRM 585 Div2 Medium (500)

問題
-都市と道路がある
-車が都市から都市へ道路を通る
-それぞれの都市で、通る車は1台だけとする
-都市を節点、道路を辺として、完全2分木をなす
-高さが与えられる
-最小の車の台数を求める

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

class TrafficCongestionDivTwo {
public:
	long long theMinCars(int treeHeight) {
		LL ans = 1;
		LL x = 1LL << treeHeight;
		while (x > 3) {
			ans += (x >> 1);
			x >>= 2;
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			long long Arg1 = 1LL;

			verify_case(n, Arg1, theMinCars(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			long long Arg1 = 3LL;

			verify_case(n, Arg1, theMinCars(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			long long Arg1 = 5LL;

			verify_case(n, Arg1, theMinCars(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			long long Arg1 = 683LL;

			verify_case(n, Arg1, theMinCars(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 60;
			long long Arg1 = 768614336404564651LL;

			verify_case(n, Arg1, theMinCars(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			long long Arg1 = 11LL;

			verify_case(n, Arg1, theMinCars(Arg0));
		}
		n++;



		if ((Case == -1) || (Case == n)){
			int Arg0 = 0;
			long long Arg1 = 1LL;

			verify_case(n, Arg1, theMinCars(Arg0));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TrafficCongestionDivTwo ___test;
	___test.run_test(-1);
}
// END CUT HERE
