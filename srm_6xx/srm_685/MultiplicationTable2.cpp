// BEGIN CUT HERE
/*
SRM 685 Div1 Easy (250)

問題
-[0,n)の集合Sがある
-Sの任意の要素i,jに対して演算(i $ j)を定義する
-Sの部分集合Tの任意の2要素i,jが常にTの要素となるとき、Tの要素数の最小値を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class MultiplicationTable2 {

public:
	int minimalGoodSet(vector <int> table) {
		int N = (int)sqrt(table.size() + 0.1);
		int ans = N;
		for (int i = 0; i < N; ++i) {
			set<int> s, m;
			m.insert(i);
			m.insert(table[N * i + i]);
			while (m.size()) {
				for (int a : m) {
					s.insert(a);
				}
				m.clear();
				for (int a : s) {
					for (int b : s) {
						if (s.find(table[N * a + b]) == s.end()) {
							m.insert(table[N * a + b]);
						}
					}
				}
			}
			ans = min(ans, (int)s.size());
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
			int Arr0[] = {1,1,2,3,
 1,0,3,2,
 2,0,1,3,
 1,2,3,0};
			int Arg1 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimalGoodSet(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,1,2,3,
 1,2,3,0,
 2,3,0,1,
 3,0,1,2};
			int Arg1 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimalGoodSet(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1,1,1,
 2,2,2,2,
 3,3,3,3,
 0,0,0,0};
			int Arg1 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimalGoodSet(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0};
			int Arg1 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimalGoodSet(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MultiplicationTable2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
