// BEGIN CUT HERE
/*
SRM 599 Div2 Easy (250)

問題
-みかんを食べた量だけ体重が増える
-体重は5000グラムを超えてはならない
-食べられる最大の個数を求める

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

class MiniatureDachshund {
public:
	int maxMikan(vector <int> mikan, int weight) {
		sort(mikan.begin(), mikan.end());
		int ans = 0;
		for (int i = 0; i < (int)mikan.size(); ++i) {
			weight += mikan[i];
			if (weight > 5000) {
				break;
			}
			++ans;
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
			int Arr0[] = {100, 100, 100, 100, 100};
			int Arg1 = 4750;
			int Arg2 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, maxMikan(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {100, 100, 100, 100, 50};
			int Arg1 = 4750;
			int Arg2 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, maxMikan(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {120, 90, 130, 100, 110, 80};
			int Arg1 = 3000;
			int Arg2 = 6;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, maxMikan(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {50};
			int Arg1 = 5000;
			int Arg2 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, maxMikan(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {200, 50, 200, 50, 200, 50, 200, 50};
			int Arg1 = 4800;
			int Arg2 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, maxMikan(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MiniatureDachshund ___test;
	___test.run_test(0);
//	___test.run_test(1);
//	___test.run_test(2);
//	___test.run_test(3);
//	___test.run_test(4);
//	___test.run_test(5);
	___test.run_test(-1);
}
// END CUT HERE
