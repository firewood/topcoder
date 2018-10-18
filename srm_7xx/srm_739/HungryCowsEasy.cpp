// BEGIN CUT HERE
/*
SRM 739 Div2 Easy (250)

問題
-直線状の農場に牛がいる
-えさ場の座標が与えられる
-牛は最も近いえさ場に移動する
-同じ距離の場合、座標が小さいほうに移動する
-それぞれの牛がどこに行くか求めよ

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class HungryCowsEasy {
public:
	vector <int> findFood(vector <int> cowPositions, vector <int> barnPositions) {
		int n = (int)cowPositions.size();
		vector <int> ans(n);
		for (int i = 0; i < n; ++i) {
			int m = 1 << 30;
			for (int j = 0; j < (int)barnPositions.size(); ++j) {
				int d = abs(cowPositions[i] - barnPositions[j]);
				if (d < m || (d == m && barnPositions[j] < barnPositions[ans[i]])) {
					ans[i] = j;
					m = d;
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
			int Arr0[] = {0};
			int Arr1[] = {-5, 5};
			int Arr2[] = {0 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, findFood(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {7, 7};
			int Arr1[] = {7, 10000};
			int Arr2[] = {0, 0 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, findFood(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2, 6, 0, 4, 8};
			int Arr1[] = {3, -1, 5, 1, 7};
			int Arr2[] = {3, 2, 1, 0, 4 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, findFood(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	HungryCowsEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
