// BEGIN CUT HERE
/*
SRM 633 Div2 Medium (500)

問題
-二次元平面上に蛙がいる
-ジャンプできる距離の配列が与えられる
-ジャンプする方向はx軸またはy軸に平行でなくてよい
-(x,y)に到達できるかどうかを求める

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

class Jumping {

	bool can(double d, vector <int> jumpLengths) {
		int sum = accumulate(jumpLengths.begin(), jumpLengths.end(), 0);
		int m = *max_element(jumpLengths.begin(), jumpLengths.end());
		return sum >= d && m <= (d + sum - m);
	}

public:
	string ableToGet(int x, int y, vector <int> jumpLengths) {
		return can(sqrt(x*x + y*y), jumpLengths) ? "Able" : "Not able";
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
			int Arg0 = 5;
			int Arg1 = 4;
			int Arr2[] = {2, 5};
			string Arg3 = "Able";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, ableToGet(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 4;
			int Arr2[] = {4};
			string Arg3 = "Not able";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, ableToGet(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 4;
			int Arr2[] = {6};
			string Arg3 = "Not able";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, ableToGet(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 0;
			int Arg1 = 1;
			int Arr2[] = {100, 100};
			string Arg3 = "Able";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, ableToGet(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 300;
			int Arg1 = 400;
			int Arr2[] = {500};
			string Arg3 = "Able";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, ableToGet(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 11;
			int Arg1 = 12;
			int Arr2[] = {1,2,3,4,5,6,7,8,9,10};
			string Arg3 = "Able";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, ableToGet(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			int Arg0 = 11;
			int Arg1 = 12;
			int Arr2[] = {1,2,3,4,5,6,7,8,9,100};
			string Arg3 = "Not able";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, ableToGet(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Jumping ___test;
	___test.run_test(-1);
}
// END CUT HERE
