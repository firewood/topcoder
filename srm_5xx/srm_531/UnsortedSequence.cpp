// BEGIN CUT HERE
/*
// SRM 531 Div2 Easy (250)

問題

N個の配列がある。
ソート順でない順番で、辞書順最小のものを求める。

*/
// END CUT HERE
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
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

typedef long long LL;
typedef vector<int> IntVec;
typedef vector<string> StrVec;

class UnsortedSequence {

public:
	vector <int> getUnsorted(vector <int> s) {
		IntVec res;

		int len = s.size();
		if (len <= 1) {
			return res;
		}

		sort(s.begin(), s.end());
		int e = *(s.rbegin());
		int i;
		for (i = len - 1; i >= 0; --i) {
			if (s[i] < e) {
				swap(s[i], s[i+1]);
				return s;
			}
		}

		return res;
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
			int Arr0[] = {1,2};
			int Arr1[] = {2, 1 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getUnsorted(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2,3};
			int Arr1[] = {1, 3, 2 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getUnsorted(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {7,2,2};
			int Arr1[] = {2, 7, 2 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getUnsorted(Arg0));
		}
		n++;

/*
		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1000};
			int Arr1[] = { };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getUnsorted(Arg0));
		}
		n++;
*/

/*
		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1};
			int Arr1[] = { };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getUnsorted(Arg0));
		}
		n++;
*/

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2,4,3};
			int Arr1[] = {1, 2, 4, 3 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getUnsorted(Arg0));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,8,5,1,10,5,9,9,3,10,5,6,6,2,8,2,10};
			int Arr1[] = {1, 2, 2, 2, 3, 5, 5, 5, 6, 6, 8, 8, 9, 10, 9, 10, 10 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getUnsorted(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	UnsortedSequence ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
