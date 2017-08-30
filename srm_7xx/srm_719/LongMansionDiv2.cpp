// BEGIN CUT HERE
/*
SRM 719 Div2 Medium (500)

問題
-N行M列のマス目がある
-各マスでは、行の位置に応じた滞在コストがかかる
-行0,列0から行N-1,列M-1へ移動するときの滞在コストの合計の最小値を求める

*/
// END CUT HERE

#include <algorithm>
#include <iostream>
#include <sstream>
#include <numeric>
#include <vector>

using namespace std;

class LongMansionDiv2 {
	public:
	long long minimalTime(int M, vector <int> t) {
        long long ans = accumulate(t.begin(), t.end(), 0LL);
        long long m = *min_element(t.begin(), t.end());
        ans += m * (M - 1);
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
			int Arg0 = 3;
			int Arr1[] = {1, 2, 1};
			long long Arg2 = 6LL;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalTime(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arr1[] = {3, 2, 4, 2};
			long long Arg2 = 17LL;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalTime(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arr1[] = {3, 2, 5, 4, 2, 8};
			long long Arg2 = 32LL;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalTime(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1000000000;
			int Arr1[] = {1000};
			long long Arg2 = 1000000000000LL;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalTime(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arr1[] = {1};
			long long Arg2 = 1LL;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalTime(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE
};

// BEGIN CUT HERE
int main() {
	LongMansionDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
