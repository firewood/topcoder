// BEGIN CUT HERE
/*
SRM 570 Div2 Hard (1000)

問題
-株式会社ケンタウロスにはN台のサーバがある
-会社を株式会社人間と株式会社馬に分割することにした
-各サーバは木構造で接続されている
-各サーバはそれぞれのどちらかに所属する
-分割後、元々接続されていなかったサーバはケーブルが必要になる
-馬は十分なケーブルを持っているが人間は持っていない
-人間側がケーブルを必要とする分割はできない
-有効な分割が何通りか求める

*/
// END CUT HERE
#include <string>
#include <numeric>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;
typedef vector<int> IntVec;

class CentaurCompanyDiv2 {

	IntVec _a;
	IntVec _b;
	LL dp[51];

	LL dfs(int parent, int node) {
		LL res = 1;
		for (int i = 0; i < (int)_a.size(); ++i) {
			if (_a[i] == node) {
				if (_b[i] != parent) {
					res *= (dfs(node, _b[i]) + 1);
				}
			}
			if (_b[i] == node) {
				if (_a[i] != parent) {
					res *= (dfs(node, _a[i]) + 1);
				}
			}
		}
		return dp[node - 1] = res;
	}

public:
	long long count(vector <int> a, vector <int> b) {
		_a = a, _b = b;
		dfs(-1, 1);
		return accumulate(dp, dp + a.size() + 1, 0LL) + 1;
	}


// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1};
			int Arr1[] = {2};
			long long Arg2 = 4LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,2};
			int Arr1[] = {1,3};
			long long Arg2 = 7LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2,3,4,5,6,7,8,9};
			int Arr1[] = {2,3,4,5,6,7,8,9,10};
			long long Arg2 = 56LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
			int Arr1[] = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51};
			long long Arg2 = 1125899906842675LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10, 7, 2, 5, 6, 2, 4, 9, 7};
			int Arr1[] = {8, 10, 10, 4, 1, 6, 2, 2, 3};
			long long Arg2 = 144LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	CentaurCompanyDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
