// BEGIN CUT HERE
/*
SRM 632 Div2 Medium (500)

PROBLEM STATEMENT

We have a sequence of N positive integers: a[0] through a[N-1].
You do not know these integers.
All you know is the number of trailing zeros in their binary representations.
You are given a vector <int> d with N elements.
For each i, d[i] is the number of trailing zeros in the binary representation of a[i].

For example, suppose that a[0]=40.
In binary, 40 is 101000 which ends in three zeros.
Therefore, d[0] will be 3.

You like geometric sequences.
(See the Notes section for a definition of a geometric sequence.)
You would like to count all non-empty contiguous subsequences of the sequence a[0], a[1], ..., a[N-1] that can be geometric sequences (given the information you have in d).

More precisely:
For each pair (i,j) such that 0 <= i <= j <= N-1, we ask the following question: "Given the values d[i] through d[j], is it possible that the values a[i] through a[j] form a geometric sequence?"

For example, suppose that d = {0,1,2,3,2}.
For i=0 and j=3 the answer is positive: it is possible that the values a[0] through a[3] are {1,2,4,8} which is a geometric sequence.
For i=1 and j=4 the answer is negative: there is no geometric sequence with these numbers of trailing zeros in binary.

Compute and return the number of contiguous subsequences of a[0], a[1], ..., a[N-1] that can be geometric sequences.


DEFINITION
Class:PotentialGeometricSequence
Method:numberOfSubsequences
Parameters:vector <int>
Returns:int
Method signature:int numberOfSubsequences(vector <int> d)


NOTES
-A geometric sequence is any sequence g[0], g[1], ..., g[k-1] such that there is a real number q (the quotient) with the property that for each valid i, g[i+1] = g[i]*q. For example, {1,2,4,8} is a geometric sequence with q=2, {7,7,7} is a geometric sequence with q=1, and {18,6,2} is a geometric sequence with q=1/3.


CONSTRAINTS
-N will be between 1 and 50, inclusive.
-d will contain exactly N elements.
-Each element of d will be between 0 and 100, inclusive.


EXAMPLES

0)
{0,1,2}

Returns: 6

One possibility is that a[0]=3, a[1]=6, and a[2]=12. In this case, all contiguous subsequences of this sequence are geometric.


1)
{1,2,4}

Returns: 5

All one-element and two-element subsequences are geometric. The entire sequence cannot be geometric.


2)
{3,2,1,0}

Returns: 10


3)
{1,2,4,8,16}

Returns: 9


4)
{1,3,5,5,5,5,64,4,23,2,3,4,5,4,3}

Returns: 37

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class PotentialGeometricSequence {
public:
	int numberOfSubsequences(vector <int> d) {
		int N = (int)d.size();
		int ans = N;
		for (int i = 0; i < N; ++i) {
			for (int len = 2; len <= N - i; ++len) {
				int a = d[i + 1] - d[i];
				int b = d[i + len - 1] - d[i + len - 2];
				if (a != b) {
					break;
				}
				++ans;
			}
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
			int Arr0[] = {0,1,2};
			int Arg1 = 6;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, numberOfSubsequences(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2,4};
			int Arg1 = 5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, numberOfSubsequences(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3,2,1,0};
			int Arg1 = 10;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, numberOfSubsequences(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2,4,8,16};
			int Arg1 = 9;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, numberOfSubsequences(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,3,5,5,5,5,64,4,23,2,3,4,5,4,3};
			int Arg1 = 37;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, numberOfSubsequences(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PotentialGeometricSequence ___test;
	___test.run_test(-1);
}
// END CUT HERE
