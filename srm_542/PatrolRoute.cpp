// BEGIN CUT HERE
/*
// SRM 542 Div1 Easy (250)

問題
X*Yの大きさの空間がある。
x座標とy座標がそれぞれ異なる任意の3点を選ぶ。
それらをユークリッド距離が最短かつループするように結ぶ。
最短距離minTと最大距離maxTが与えられるとき、3点の選び方が何通りあるか求める。

*/
// END CUT HERE
#include <cmath>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

#define MOD 1000000007LL
typedef long long LL;

class PatrolRoute {

public:
	int countRoutes(int X, int Y, int minT, int maxT) {
		LL res = 0;
		int w, h;
		for (h = 2; h < Y; ++h) {
			for (w = 2; w < X; ++w) {
				int d = (h+w)*2;
				if (d >= minT && d <= maxT) {
					LL a = (Y-h)*(X-w);
					LL b = (h-1)*(w-1);
					res = (res + (a*b*6)) % MOD;
				}
			}
		}
		return (int)res;
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
			int Arg1 = 3;
			int Arg2 = 1;
			int Arg3 = 20000;
			int Arg4 = 6;

			verify_case(n, Arg4, countRoutes(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 3;
			int Arg2 = 4;
			int Arg3 = 7;
			int Arg4 = 0;

			verify_case(n, Arg4, countRoutes(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 6;
			int Arg2 = 9;
			int Arg3 = 12;
			int Arg4 = 264;

			verify_case(n, Arg4, countRoutes(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 7;
			int Arg1 = 5;
			int Arg2 = 13;
			int Arg3 = 18;
			int Arg4 = 1212;

			verify_case(n, Arg4, countRoutes(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4000;
			int Arg1 = 4000;
			int Arg2 = 4000;
			int Arg3 = 14000;
			int Arg4 = 859690013;

			verify_case(n, Arg4, countRoutes(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PatrolRoute ___test;
	___test.run_test(0);
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
