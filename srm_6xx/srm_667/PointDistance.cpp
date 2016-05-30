// BEGIN CUT HERE
/*
SRM 667 Div2 Easy (250)

問題
-二次元平面上に点A,Bがあり、座標が与えられる
-A-Cの距離がB-Cの距離より長くなるような点Cの座標を求める

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

class PointDistance {
public:
	vector <int> findPoint(int x1, int y1, int x2, int y2) {
		vector <int> ans(2);
		for (int y = -100; y <= 100; ++y) {
			if (y == y1 || y == y2) {
				continue;
			}
			for (int x = -100; x <= 100; ++x) {
				if (x == x1 || x == x2) {
					continue;
				}
				int r1 = (x1 - x) * (x1 - x) + (y1 - y) * (y1 - y);
				int r2 = (x2 - x) * (x2 - x) + (y2 - y) * (y2 - y);
				if (r1 > r2) {
					ans[0] = x;
					ans[1] = y;
					return ans;
				}
			}
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = -1;
			int Arg1 = 0;
			int Arg2 = 1;
			int Arg3 = 0;
			int Arr4[] = {8, 48 };

			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			verify_case(n, Arg4, findPoint(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 1;
			int Arg2 = -1;
			int Arg3 = -1;
			int Arr4[] = {25, -63 };

			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			verify_case(n, Arg4, findPoint(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 0;
			int Arg1 = 1;
			int Arg2 = 2;
			int Arg3 = 3;
			int Arr4[] = {41, 65 };

			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			verify_case(n, Arg4, findPoint(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = -4;
			int Arg2 = -2;
			int Arg3 = 5;
			int Arr4[] = {68, 70 };

			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			verify_case(n, Arg4, findPoint(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = -50;
			int Arg1 = -50;
			int Arg2 = 50;
			int Arg3 = -50;
			int Arr4[] = {67, 4 };

			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			verify_case(n, Arg4, findPoint(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = -50;
			int Arg1 = 50;
			int Arg2 = -49;
			int Arg3 = 49;
			int Arr4[] = {73, -25 };

			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			verify_case(n, Arg4, findPoint(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PointDistance ___test;
	___test.run_test(-1);
}
// END CUT HERE
