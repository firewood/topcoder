// BEGIN CUT HERE
/*
SRM 592 Div2 Medium (500)

PROBLEM STATEMENT

This problem statement contains superscripts and/or subscripts. These may not display properly outside the applet.

Little Elephant from the Zoo of Lviv likes permutations.
A permutation of size N is a sequence (a1, ..., aN) that contains each of the numbers from 1 to N exactly once.
For example, (3,1,4,5,2) is a permutation of size 5.

Given two permutations A = (a1, ..., aN) and B = (b1, ..., bN), the value magic(A,B) is defined as follows:
magic(A,B) = max(a1,b1) + max(a2,b2) + ... + max(aN,bN).

You are given the int N.
You are also given another int K.
Return the number of pairs (A,B) such that both A and B are permutations of size N, and magic(A,B) is greater than or equal to K.
(Note that A and B are not required to be distinct.)


DEFINITION
Class:LittleElephantAndPermutationDiv2
Method:getNumber
Parameters:int, int
Returns:long long
Method signature:long long getNumber(int N, int K)


CONSTRAINTS
-N will be between 1 and 10, inclusive.
-K will be between 1 and 100, inclusive.


EXAMPLES

0)
1
1

Returns: 1

For N=1 the only pair of permutations is ( (1), (1) ).
The magic of this pair of permutations is 1, so we count it.


1)
2
1

Returns: 4

Now there are four possible pairs of permutations. They are shown below, along with their magic value.

magic( (1,2), (1,2) ) = 1+2 = 3
magic( (1,2), (2,1) ) = 2+2 = 4
magic( (2,1), (1,2) ) = 2+2 = 4
magic( (2,1), (2,1) ) = 2+1 = 3

In all four cases the magic value is greater than or equal to K.


2)
3
8

Returns: 18

When A = (1,2,3), there are 3 possibilities for B: (2,3,1), (3,1,2) and (3,2,1). For each of the other 5 values of A, it can be shown that there are 3 possibilities for B as well. Therefore the answer is 3*6 = 18.


3)
10
47

Returns: 13168189440000

*/
// END CUT HERE
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

class LittleElephantAndPermutationDiv2 {
public:
	long long getNumber(int N, int K) {
		LL ans = 0;
		int b[10] = {1,2,3,4,5,6,7,8,9,10};
		int i;
		LL k = 1;
		for (i = 1; i <= N; ++i) {
			k *= i;
		}
		do {
			int sum = 0;
			for (i = 0; i < N; ++i) {
				sum += max(i+1, b[i]);
			}
			if (sum >= K) {
				ans += k;
			}
		} while(next_permutation(b, b + N));
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
			int Arg0 = 1;
			int Arg1 = 1;
			long long Arg2 = 1LL;

			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 1;
			long long Arg2 = 4LL;

			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 8;
			long long Arg2 = 18LL;

			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arg1 = 47;
			long long Arg2 = 13168189440000LL;

			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	LittleElephantAndPermutationDiv2 ___test;
//	___test.run_test(0);
//	___test.run_test(1);
//	___test.run_test(2);
//	___test.run_test(3);
//	___test.run_test(4);
//	___test.run_test(5);
	___test.run_test(-1);
}
// END CUT HERE
