// BEGIN CUT HERE
/*
SRM 643 Div1 Easy (250)
SRM 643 Div2 Medium (500)

問題
-数Nを素因数分解したい
-奇数番目の素因数が与えられる
-全ての素因数を昇順に求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

class TheKingsFactorization {
public:
	vector<long long> getVector(long long N, vector<long long> primes) {
		vector<long long> ans;
		for (LL p : primes) {
			while ((N % p) == 0) {
				N /= p;
				ans.push_back(p);
			}
		}
		for (LL i = 2; i < 1000000 && N > 1; ++i) {
			while ((N % i) == 0) {
				N /= i;
				ans.push_back(i);
			}
		}
		if (N > 1) {
			ans.push_back(N);
		}
		sort(ans.begin(), ans.end());
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector<long long> &Expected, const vector<long long> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 12LL;
			long Arr1[] = {2, 3};
			long Arr2[] = {2, 2, 3 };

			vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, getVector(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 7LL;
			long Arr1[] = {7};
			long Arr2[] = {7 };

			vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, getVector(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 1764LL;
			long Arr1[] = {2, 3, 7};
			long Arr2[] = {2, 2, 3, 3, 7, 7 };

			vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, getVector(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 49LL;
			long Arr1[] = {7};
			long Arr2[] = {7, 7 };

			vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, getVector(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 210LL;
			long Arr1[] = {2, 5};
			long Arr2[] = {2, 3, 5, 7 };

			vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, getVector(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 100000LL;
			long Arr1[] = {2, 2, 2, 5, 5};
			long Arr2[] = {2, 2, 2, 2, 2, 5, 5, 5, 5, 5 };

			vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, getVector(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			long long Arg0 = 686083302272203078;
			long Arr1[] = { 2, 700027 };
			long Arr2[] = { 2, 700001, 700027, 700057 };

			vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, getVector(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			long long Arg0 = 999999724000019044;
			long Arr1[] = { 2, 499999931 };
			long Arr2[] = { 2, 2, 499999931, 499999931 };

			vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, getVector(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			long long Arg0 = 999999943999999559;
			long Arr1[] = { 999999937 };
			long Arr2[] = { 999999937, 1000000007 };

			vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, getVector(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TheKingsFactorization ___test;
	___test.run_test(-1);
}
// END CUT HERE
