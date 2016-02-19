// BEGIN CUT HERE
/*
SRM 680 Div2 Medium (500)

問題
-無限個の椅子がある
-N匹の熊が順番にやってきて、隣の熊と距離がd以上離れていて、最も入り口に近い椅子に座る
-それぞれの熊が座る位置を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class BearChairs {
public:
	vector <int> findPositions(vector <int> atLeast, int d) {
		vector <int> ans;
		vector <int> sorted;
		for (int a : atLeast) {
			for (int i = 0; i != sorted.size(); ++i) {
				if (sorted[i] + d < a) {
					;
				} else if ((sorted[i] <= a && a <= sorted[i] + d) || (a < sorted[i] && sorted[i] < a + d)) {
					a = sorted[i] + d;
				}
			}
			sorted.push_back(a);
			sort(sorted.begin(), sorted.end());
			ans.push_back(a);
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
			int Arr0[] = {1,21,11,7};
			int Arg1 = 10;
			int Arr2[] = {1, 21, 11, 31 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, findPositions(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,21,11,7};
			int Arg1 = 11;
			int Arr2[] = {1, 21, 32, 43 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, findPositions(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1000000,1000000,1000000,1};
			int Arg1 = 1000000;
			int Arr2[] = {1000000, 2000000, 3000000, 4000000 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, findPositions(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1000000,1000000,1000000,1};
			int Arg1 = 999999;
			int Arr2[] = {1000000, 1999999, 2999998, 1 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, findPositions(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BearChairs ___test;
	___test.run_test(-1);
}
// END CUT HERE
