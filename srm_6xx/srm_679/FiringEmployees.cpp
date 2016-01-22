// BEGIN CUT HERE
/*
SRM 679 Div1 Easy (250)

問題
-社長とN人の社員がいる
-それぞれのボス、給与、生産力が与えられる
-生産力から給与をひいたものが利益となる
-任意の社員を解雇できる
-ただし部下がいる社員を解雇すると部下も解雇する必要がある
-利益の最大値を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class FiringEmployees {
public:
	int fire(vector <int> m, vector <int> s, vector <int> p) {
		int N = (int)m.size();
		int a[2560] = {};
		for (int i = N; i > 0; --i) {
			int d = p[i - 1] - s[i - 1];
			int boss = m[i - 1];
			a[i] += d;
			if (a[i] > 0) {
				a[boss] += a[i];
			}
		}
		return a[0];
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
			int Arr0[] = {0,0,0};
			int Arr1[] = {1,2,3};
			int Arr2[] = {3,2,1};
			int Arg3 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, fire(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,1,2,3};
			int Arr1[] = {4,3,2,1};
			int Arr2[] = {2,3,4,5};
			int Arg3 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, fire(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,1};
			int Arr1[] = {1,10};
			int Arr2[] = {5,5};
			int Arg3 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, fire(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,1,2,1,2,3,4,2,3};
			int Arr1[] = {5,3,6,8,4,2,4,6,7};
			int Arr2[] = {2,5,7,8,5,3,5,7,9};
			int Arg3 = 6;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, fire(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,0,1,1,2,2};
			int Arr1[] = {1,1,1,2,2,2};
			int Arr2[] = {2,2,2,1,1,1};
			int Arg3 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, fire(Arg0, Arg1, Arg2));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			vector <int> Arg[3];
			for (int i = 0; i < 2500; ++i) {
				Arg[0].push_back(i);
				Arg[1].push_back(1);
				Arg[2].push_back(1);
			}
			Arg[2].back() = 100;
			int Arg3 = 99;

			verify_case(n, Arg3, fire(Arg[0], Arg[1], Arg[2]));
		}
		n++;
	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FiringEmployees ___test;
	___test.run_test(-1);
}
// END CUT HERE
