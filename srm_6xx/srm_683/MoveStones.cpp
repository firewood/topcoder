// BEGIN CUT HERE
/*
SRM 683 Div1 Easy (250)

問題
-何個かの石からなる山がN個あり、円環状に並んでいる
-各山の個数は配列a[0],a[1],...a[N-1]で与えられる
-1ターンに、1個の石を隣に移動できる
-山の個数をb[0],b[1],...b[N-1]にするための最小ターン数を求める

*/
// END CUT HERE
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef long long LL;
typedef vector<LL> LLVec;

class MoveStones {
public:
	long long get(vector <int> a, vector <int> b) {
		if (a == b) {
			return 0;
		}
		if (accumulate(a.begin(), a.end(), 0LL) != accumulate(b.begin(), b.end(), 0LL)) {
			return -1;
		}
		int N = (int)a.size();
		LLVec v(N + 1);
		for (int i = 0; i < N; ++i) {
			v[i + 1] = v[i] + a[i] - b[i];
		}
		v.erase(v.begin());
		sort(v.begin(), v.end());
		LL m = v[N / 2];
		LL ans = 0;
		for (LL c : v) {
			ans += abs(c - m);
		}
		return ans;
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
			int Arr0[] = {12};
			int Arr1[] = {12};
			long long Arg2 = 0LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, get(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10};
			int Arr1[] = {9};
			long long Arg2 = -1LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, get(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 5};
			int Arr1[] = {5, 0};
			long long Arg2 = 5LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, get(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 2, 3};
			int Arr1[] = {3, 1, 2};
			long long Arg2 = 2LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, get(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 0, 1, 1, 0}
;
			int Arr1[] = {0, 3, 0, 0, 0};
			long long Arg2 = 4LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, get(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1000000000, 0, 0, 0, 0, 0};
			int Arr1[] = {0, 0, 0, 1000000000, 0, 0};
			long long Arg2 = 3000000000LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, get(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arr0[] = { 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 2 };
			;
			int Arr1[] = { 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0 };
			long long Arg2 = 5LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, get(Arg0, Arg1));
		}
		n++;

	}


// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MoveStones ___test;
	___test.run_test(-1);
}
// END CUT HERE
