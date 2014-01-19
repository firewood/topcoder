// BEGIN CUT HERE
/*
// SRM 538 Div1 Easy (250)

問題
N個の点が与えられる。
初期位置が(0,0)で、N個の点の全部を1回だけ経由するものとする。
位置のパリティがwantedParityと一致するかどうかを求める。

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

typedef long long LL;
typedef vector<int> IntVec;
typedef vector<LL> LLVec;
typedef vector<string> StrVec;
typedef set<int> IntSet;
typedef set<LL> LLSet;

class EvenRoute {

public:
	string isItPossible(vector <int> x, vector <int> y, int wantedParity) {
		int i;
		for (i = 0; i < (int)x.size(); ++i) {
			if (((x[i] + y[i]) & 1) == wantedParity) {
				return "CAN";
			}
		}
		return "CANNOT";
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
			int Arr0[] = {-1,-1,1,1};
			int Arr1[] = {-1,1,1,-1};
			int Arg2 = 0;
			string Arg3 = "CAN";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, isItPossible(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-5,-3,2};
			int Arr1[] = {2,0,3};
			int Arg2 = 1;
			string Arg3 = "CAN";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, isItPossible(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1001, -4000};
			int Arr1[] = {0,0};
			int Arg2 = 1;
			string Arg3 = "CAN";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, isItPossible(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {11, 21, 0};
			int Arr1[] = {-20, 42, 7};
			int Arg2 = 0;
			string Arg3 = "CANNOT";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, isItPossible(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 6};
			int Arr1[] = {10, -20};
			int Arg2 = 1;
			string Arg3 = "CANNOT";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, isItPossible(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EvenRoute ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
