// BEGIN CUT HERE
/*
// SRM 539 Div1 Easy (250)

問題
手持ちの岩がいくつかあり、9001個以上所有しているように見せかけたい。
n個の箱があり、それぞれa個以上b個以下の岩が入っているように見せかけることができる。
9001個以上の数値が何通り作れるかを求める。

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

typedef pair<int, int> II;
typedef vector<II> IIVec;

class Over9000Rocks {

public:
	int countPossibilities(vector <int> lowerBound, vector <int> upperBound) {
		int N = lowerBound.size();
		int i, j, k = 0, sz = (1<<N)-1;
		IIVec v(sz);
		for (i = 0; i < N; ++i) {
			for (j = 0; j < k; ++j) {
				v[j+k].first = v[j].first + lowerBound[i];
				v[j+k].second = v[j].second + upperBound[i];
			}
			v[j+k].first = lowerBound[i];
			v[j+k].second = upperBound[i];
			k = k*2+1;
		}
		sort(v.begin(), v.end());

		int res = 0;
		int x = 9001;
		for (i = 0; i < sz; ++i) {
			int l = v[i].first;
			int u = v[i].second;
			if (l > x) {
				x = l;
			}
			if (u >= x) {
				res += (u - x) + 1;
				x = u + 1;
			}
		}
		return res;
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
			int Arr0[] = {9000};
			int Arr1[] = {9001};
			int Arg2 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, countPossibilities(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {9000, 1, 10};
			int Arr1[] = {9000, 2, 20};
			int Arg2 = 15;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, countPossibilities(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1001, 2001, 3001, 3001};
			int Arr1[] = {1003, 2003, 3003, 3003};
			int Arg2 = 9;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, countPossibilities(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {9000,90000,1,10};
			int Arr1[] = {9000,90000,3,15};
			int Arg2 = 38;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, countPossibilities(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1,1,1,1,1};
			int Arr1[] = {3,4,5,6,7,8};
			int Arg2 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, countPossibilities(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arr0[] = {9002};
			int Arr1[] = {9002};
			int Arg2 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, countPossibilities(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
			int Arr1[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
			int Arg2 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, countPossibilities(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Over9000Rocks ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
