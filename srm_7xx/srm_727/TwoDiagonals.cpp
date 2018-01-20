// BEGIN CUT HERE
/*
SRM 727 Div2 Medium (500)

問題
- Bearlandの各都市はN個の異なる点で表される
- 向きが斜め45°で、直交する無限の長さの二本の道路をひく
- いずれかの道路に交わる都市の数を最大化するとき、総数を求めよ

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class TwoDiagonals {
public:
	int maxPoints(vector <int> x, vector <int> y) {
		vector<vector<int> > ao, bo;
		for (int i = -2000; i <= 2000; ++i) {
			vector<int> as, bs;
			for (int j = 0; j < (int)x.size(); ++j) {
				if (y[j] == x[j] + i) {
					as.push_back(j);
				}
				if (y[j] == -x[j] + i) {
					bs.push_back(j);
				}
			}
			if (as.size() > 0) {
				ao.push_back(as);
			}
			if (bs.size() > 0) {
				bo.push_back(bs);
			}
		}
		int ans = 0;
		for (int i = 0; i < (int)ao.size(); ++i) {
			for (int j = 0; j < (int)bo.size(); ++j) {
				vector<int> s = ao[i];
				s.insert(s.end(), bo[j].begin(), bo[j].end());
				sort(s.begin(), s.end());
				ans = max(ans, (int)(unique(s.begin(), s.end()) - s.begin()));
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
			int Arr0[] = {1, 4, 4, 5};
			int Arr1[] = {3, 0, 2, 3};
			int Arg2 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maxPoints(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 1, 2, 3, 4, 5};
			int Arr1[] = {2, 2, 2, 2, 2, 2};
			int Arg2 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maxPoints(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2, 2, 3, 3};
			int Arr1[] = {2, 3, 2, 3};
			int Arg2 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maxPoints(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10, 0, 15, 9};
			int Arr1[] = {10, 0, 15, 11};
			int Arg2 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maxPoints(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {273, 100, 999, 789, 105};
			int Arr1[] = {838, 200, 999, 0, 560};
			int Arg2 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maxPoints(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 2, 0, 2, 1}
;
			int Arr1[] = {0, 0, 2, 2, 1};
			int Arg2 = 5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maxPoints(Arg0, Arg1));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {500, 503, 501};
			int Arr1[] = {200, 197, 199};
			int Arg2 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maxPoints(Arg0, Arg1));
		}
		n++;

		// test_case_7
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 2, 4};
			int Arr1[] = {0, 3, 6};
			int Arg2 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maxPoints(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 0 };
			int Arr1[] = { 0 };
			int Arg2 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maxPoints(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TwoDiagonals ___test;
	___test.run_test(-1);
}
// END CUT HERE
