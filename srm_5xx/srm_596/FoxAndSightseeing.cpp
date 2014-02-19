// BEGIN CUT HERE
/*
SRM 596 Div2 Easy (250)

問題
-N個の都市の位置が与えられる
-一つだけ飛ばしてN-1個の都市を順番に観光したい
-移動距離の最小値を求める

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

class FoxAndSightseeing {
public:
	int getMin(vector <int> position) {
		int ans = 999999;
		for (int i = 1; i < ((int)position.size()-1); ++i) {
			int pos = position[0];
			int c = 0;
			for (int j = 1; j < (int)position.size(); ++j) {
				if (i != j) {
					c += abs(pos - position[j]);
					pos = position[j];
				}
			}
			ans = min(ans, c);
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
			int Arr0[] = {1, 4, -1, 3};
			int Arg1 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-2, 4, 3};
			int Arg1 = 5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
			int Arg1 = 9;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {100, -100, 99, -99};
			int Arg1 = 199;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {74,84,92,23,5,-70,-47,-59,24,-86,-39,99,85,-42,54,100,47,-3,42,38};
			int Arg1 = 836;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,-3,5,7,-11,-13,17,-19,23,29,-31,-37,-41,43,-47,-53,-59,61,-67,71};
			int Arg1 = 535;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FoxAndSightseeing ___test;
	___test.run_test(-1);
}
// END CUT HERE
