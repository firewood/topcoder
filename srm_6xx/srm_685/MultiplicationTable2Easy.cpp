// BEGIN CUT HERE
/*
SRM 685 Div2 Easy (250)

問題
-[0,n)の集合Sがある
-Sの任意の要素i,jに対して演算(i $ j)を定義する
-Sの部分集合Tが与えられる
-Tの任意の2要素i,jが常にTの要素になるかどうかを求める

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class MultiplicationTable2Easy {
public:
	string isGoodSet(vector <int> table, vector <int> t) {
		int N = (int)sqrt(table.size() + 0.1);
		set<int> s(t.begin(), t.end());
		for (int i : t) {
			for (int j : t) {
				if (s.find(table[i * N + j]) == s.end()) {
					return "Not Good";
				}
			}
		}
		return "Good";
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
			int Arr0[] = {1, 1, 2, 3,
 1, 0, 2, 3,
 3, 3, 0, 3,
 2, 2, 2, 0}
;
			int Arr1[] = {1,0};
			string Arg2 = "Good";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, isGoodSet(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 1, 2, 3,
 1, 0, 2, 3,
 3, 3, 0, 3,
 2, 2, 2, 0};
			int Arr1[] = {2, 3};
			string Arg2 = "Not Good";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, isGoodSet(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 1, 2, 3,
 1, 0, 2, 3,
 3, 3, 0, 3,
 2, 2, 2, 0}
;
			int Arr1[] = {0,1,2,3};
			string Arg2 = "Good";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, isGoodSet(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 1, 2, 3,
 1, 0, 2, 3,
 3, 3, 0, 3,
 2, 2, 2, 0}
;
			int Arr1[] = {1};
			string Arg2 = "Not Good";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, isGoodSet(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,2,2,2,2,2,
 2,2,2,2,2,2,
 2,2,2,2,2,2,
 2,2,2,2,2,2,
 2,2,2,2,2,2,
 2,2,2,2,2,2};
			int Arr1[] = {2,4,5};
			string Arg2 = "Good";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, isGoodSet(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,2,2,2,2,2,
 2,2,2,2,2,2,
 2,2,2,2,2,2,
 2,2,2,2,2,2,
 2,2,2,2,2,2,
 2,2,2,2,2,2};
			int Arr1[] = {0,1,3,4,5};
			string Arg2 = "Not Good";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, isGoodSet(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MultiplicationTable2Easy ___test;
	___test.run_test(-1);
}
// END CUT HERE
