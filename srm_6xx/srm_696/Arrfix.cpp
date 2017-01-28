// BEGIN CUT HERE
/*
SRM 696 Div2 Medium (500)

問題
-配列AとBがある
-配列の違いとは、値が異なるインデックスの総数である
-Aを変更してBとの違いを最小化したい
-いくつかのステッカーがある
-それぞれのステッカーは値を持っていて、ひとつの要素を一回だけその値にできる
-一つの要素に複数のステッカーは使用できない
-ステッカーを全て適用したあと、違いの最小値を求める

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class Arrfix {
public:
	int mindiff(vector <int> A, vector <int> B, vector <int> F) {
		int ua[64] = {}, uf[64] = {};
		for (int stage = 0; stage != 4; ++stage) {
			for (int i = 0; i != F.size(); ++i) {
				for (int j = 0; !uf[i] && j != A.size(); ++j) {
					if (!ua[j]) {
						switch (stage) {
						case 0:
							if (A[j] != F[i] && B[j] == F[i]) {
								ua[j] = 1, uf[i] = 1, A[j] = F[i];
							}
							break;
						case 1:
							if (A[j] == F[i] && B[j] == F[i]) {
								ua[j] = 1, uf[i] = 1, A[j] = F[i];
							}
							break;
						case 2:
							if (A[j] != B[j]) {
								ua[j] = 1, uf[i] = 1, A[j] = F[i];
							}
							break;
						case 3:
							ua[j] = 1, uf[i] = 1, A[j] = F[i];
							break;
						}
					}
				}
			}
		}
		int ans = 0;
		for (int i = 0; i != A.size(); ++i) {
			ans += A[i] != B[i];
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
			int Arr0[] = {1,1,1};
			int Arr1[] = {2,2,2};
			int Arr2[] = {2};
			int Arg3 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, mindiff(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1,1};
			int Arr1[] = {2,2,1};
			int Arr2[] = {2,2};
			int Arg3 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, mindiff(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2,3};
			int Arr1[] = {3,2,1};
			// int Arr2[] = {};
			int Arg3 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2;
			verify_case(n, Arg3, mindiff(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,2,2};
			int Arr1[] = {2,2,2};
			int Arr2[] = {1,2,3};
			int Arg3 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, mindiff(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,3,3,3};
			int Arr1[] = {2,3,3,3};
			int Arr2[] = {2,2};
			int Arg3 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, mindiff(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Arrfix ___test;
	___test.run_test(-1);
}
// END CUT HERE
