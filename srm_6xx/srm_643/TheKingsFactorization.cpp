// BEGIN CUT HERE
/*
SRM 643 Div1 Easy (250)
SRM 643 Div2 Medium (500)

PROBLEM STATEMENT

The King of Byteland likes integer factorization.
Your task is to help him factor the number N.
You will be given the long long N and you should return a vector<long long> containing all prime factors of N sorted in non-decreasing order.
Note that some primes may occur multiple times in the prime factorization of N.
For example, for N = 60 the only correct return value is {2, 2, 3, 5} because 2*2*3*5 = 60.

To make this task easier, the King has decided to give you a hint.
He already knows the correct factorization and he will tell you every second number in the correct return value.
More precisely, in addition to N you will be given a vector<long long> primes.
The number of elements in primes will be (M+1)/2, rounded down, where M is the number of elements in the correct return value.
For each valid i, primes[i] will be equal to the element 2i of the correct return value.
(All indices are 0-based.)

Given N and primes, return the vector<long long> containing the factorization of N.


DEFINITION
Class:TheKingsFactorization
Method:getVector
Parameters:long long, vector<long long>
Returns:vector<long long>
Method signature:vector<long long> getVector(long long N, vector<long long> primes)


CONSTRAINTS
-N will be between 2 and 1,000,000,000,000,000,000 (10^18), inclusive.
-primes will contain the correct prime factors (as defined in the problem statement).


EXAMPLES

0)
12
{2, 3}

Returns: {2, 2, 3 }


1)
7
{7}

Returns: {7 }


2)
1764
{2, 3, 7}

Returns: {2, 2, 3, 3, 7, 7 }


3)
49
{7}

Returns: {7, 7 }


4)
210
{2, 5}

Returns: {2, 3, 5, 7 }


5)
100000
{2, 2, 2, 5, 5}

Returns: {2, 2, 2, 2, 2, 5, 5, 5, 5, 5 }

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
