// BEGIN CUT HERE
/*
SRM 747 Div1 Easy (250)

PROBLEM STATEMENT

You are given the ints n and d.
Return any vector <int> with the following properties:

The number of elements is n.
Each element is between 0 and 10^9, inclusive.
All elements are distinct.
No element is divisible by 10.
If we take all n*(n-1)/2 possible sums of two elements and look at the last digit of each of them, the digit d will be the unique most frequent one.


DEFINITION
Class:MostFrequentLastDigit
Method:generate
Parameters:int, int
Returns:vector <int>
Method signature:vector <int> generate(int n, int d)


CONSTRAINTS
-n will be between 2 and 200, inclusive.
-d will be between 0 and 9, inclusive.


EXAMPLES

0)
4
7

Returns: {1, 6, 13, 4 }

The pairwise sums are 7, 14, 5, 19, 10, and 17. The last digit 7 appears in two of them, and each other digit appears at most once as a last digit of one of these sums.


1)
2
8

Returns: {44, 444 }

Note that {4, 4} is not a valid return value because all numbers must be distinct.}


2)
7
2

Returns: {109, 22, 74, 23, 29, 9, 1003 }

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

bool eval(int n, int d, const vector<int> &v) {
	int cnt[10] = {};
	for (int i = 0; i < n; ++i) {
		if (v[i] % 10 == 0) {
			return false;
		}
		for (int j = i + 1; j < n; ++j) {
			cnt[(v[i] + v[j]) % 10] += 1;
		}
	}
	int m = cnt[d];
	for (int i = 0; i < 10; ++i) {
		if (i != d && cnt[i] >= m) {
			return false;
		}
	}
	return true;
}

class MostFrequentLastDigit {
public:
	vector <int> generate(int n, int d) {
		vector <int> ans(n * 2);
		while (true) {
			for (int i = 0; i < n * 2; ++i) {
				while (true) {
					ans[i] = rand() % 1000;
					if (ans[i] % 10) {
						break;
					}
				}
			}
			sort(ans.begin(), ans.end());
			size_t sz = unique(ans.begin(), ans.end()) - ans.begin();
			if ((int)sz >= n) {
				if (eval(n, d, ans)) {
					ans.resize(n);
					break;
				}
			}
		}
		return ans;
	}

	// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) {
		cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else {
			cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl;
		}
	}

public:
	void run_test(int Case) {
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)) {
			int Arg0 = 4;
			int Arg1 = 7;
			int Arr2[] = { 1, 6, 13, 4 };

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, generate(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)) {
			int Arg0 = 2;
			int Arg1 = 8;
			int Arr2[] = { 44, 444 };

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, generate(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)) {
			int Arg0 = 7;
			int Arg1 = 2;
			int Arr2[] = { 109, 22, 74, 23, 29, 9, 1003 };

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, generate(Arg0, Arg1));
		}
		n++;

	}

	// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MostFrequentLastDigit ___test;
	___test.run_test(-1);
}
// END CUT HERE
