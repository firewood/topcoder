// BEGIN CUT HERE
/*
SRM 682 Div1 Easy (300)

問題
-友人関係の双方向のグラフが与えられる
-友人関係を4つたどって異なる5人にたどりつけるかどうかを求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef vector<int> IntVec;

class SmilesTheFriendshipUnicorn {

	bool check(int N, IntVec &A, IntVec &B) {
		IntVec edge[2000];
		for (int i = 0; i != A.size(); ++i) {
			edge[A[i]].push_back(B[i]);
			edge[B[i]].push_back(A[i]);
		}
		for (int a = 0; a < N; ++a) {
			const IntVec &p = edge[a];
			for (int j = 0; j != p.size(); ++j) {
				int b = p[j];
				for (int k = j + 1; k != p.size(); ++k) {
					int c = p[k];
					for (int d : edge[b]) {
						if (a == d || c == d) {
							continue;
						}
						for (int e : edge[c]) {
							if (a != e && b != e && d != e) {
								return true;
							}
						}
					}
				}
			}
		}
		return false;
	}

public:
	string hasFriendshipChain(int N, vector <int> A, vector <int> B) {
		return check(N, A, B) ? "Yay!" : ":(";
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
			int Arg0 = 5;
			int Arr1[] = {0, 1, 2, 3};
			int Arr2[] = {1, 2, 3, 4};
			string Arg3 = "Yay!";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, hasFriendshipChain(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arr1[] = {0, 1, 2, 3, 1};
			int Arr2[] = {1, 2, 3, 0, 4};
			string Arg3 = "Yay!";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, hasFriendshipChain(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			int Arr1[] = {0, 0, 0, 0, 0};
			int Arr2[] = {1, 2, 3, 4, 5};
			string Arg3 = ":(";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, hasFriendshipChain(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 8;
			int Arr1[] = {1, 3, 4, 3, 4, 3, 0, 2};
			int Arr2[] = {7, 7, 7, 4, 6, 5, 4, 7};
			string Arg3 = "Yay!";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, hasFriendshipChain(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 7;
			int Arr1[] = {0, 1, 1, 5, 4, 5};
			int Arr2[] = {5, 2, 3, 6, 1, 1};
			string Arg3 = ":(";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, hasFriendshipChain(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 42;
			int Arr1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41}
;
			int Arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 0};
			string Arg3 = "Yay!";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, hasFriendshipChain(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SmilesTheFriendshipUnicorn ___test;
	___test.run_test(-1);
}
// END CUT HERE
