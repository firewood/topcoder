// BEGIN CUT HERE
/*
SRM 712 Div1 Easy (300)

PROBLEM STATEMENT
We have a cyclic array A of length n.
For each valid i, element i-1 the left neighbor of element i.
Additionally, element n-1 is the left neighbor of element 0.

You are given two vector<long long>s s and t, each with n elements.
Currently, we have A[i] = s[i] for each valid i.
Our goal is to have A[i] = t[i] for each valid i.

We can use two operations that modify the contents of A:

Operation L: Each element is increased by the value of its left neighbor.
Operation R: Each element is increased by the value of its right neighbor.

Note that all changes happen simultaneously. For example, if you use the operation L, the new value of A[7] is computed as the sum of the old value of A[7] and the old value of A[6].

If there is no way to reach the desired goal state, return "No solution".
Otherwise return any valid way of doing so by using at most 100 operations.
More precisely, return one valid sequence of operations encoded as a string of 'L's and 'R's.


If there are multiple valid solutions, you may return any of them.
In particular, you are not required to find the shortest valid solution.
Any valid solution will be accepted as long as its length does not exceed 100.
We can prove that if there is an valid solution then there must exist one with length at most 100.


DEFINITION
Class:LR
Method:construct
Parameters:vector<long long>, vector<long long>
Returns:string
Method signature:string construct(vector<long long> s, vector<long long> t)


CONSTRAINTS
-s will contain between 2 and 50 elements, inclusive.
-s and t will contain the same number of elements.
-Each element in s will be between 0 and 1,000,000,000,000,000 (10^15) inclusive.
-Each element in t will be between 0 and 1,000,000,000,000,000 (10^15) inclusive.


EXAMPLES

0)
{0,1,0,0,0}
{0,1,2,1,0}

Returns: "LL"

The first operation L will change A into {0,1,1,0,0} and then the second operation L will produce the array we wanted.


1)
{0,0,0,1}
{0,1,0,0}

Returns: "No solution"

Even though A is cyclic, the precise indices matter. Here, s and t are two different configurations, and there is no valid way to change this s into this t.


2)
{1,2,3,4,5,6,7,8,9,10}
{12,24,56,95,12,78,0,100,54,88}

Returns: "No solution"

Regardless of the type and order of operations all elements of A will always remain positive.
However, t contains a zero.
Therefore, t cannot be reached.


3)
{1,0,0}
{11,11,10}

Returns: "RRRRR"

The sequence of five operations R will change the array A as follows: 
{1,0,0} -> {1,0,1} -> {1,1,2} -> {2,3,3} -> {5,6,5} -> {11,11,10}.


4)
{1,1}
{562949953421312,562949953421312}

Returns: "RLLLRRRLLRRRLRLRRLLLLRLLRRLRRRLRRLRRLLRRRLLRRRLLL"

We start with A[0] = A[1] = 1, and we want A[0] = A[1] = 2^49.
We can easily verify that in this case each operation changes A from {x, x} into {2x, 2x}.
Therefore, any string of exactly 49 'L's and 'R's is a valid answer.


5)
{0,0,0,0,0}
{0,0,0,1,0}

Returns: "No solution"


6)
{123,456}
{123,456}

Returns: ""


*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef long long LL;
typedef vector<LL> LLVec;

class LR {
public:
	string construct(vector<long long> s, vector<long long> t) {
		int N = (int)s.size();
		string w;
		LLVec a = s;
		for (int l = 0; l <= 100; ++l) {
			string ans = w;
			LLVec b = a;
			for (int r = 0; l + r <= 100; ++r) {
				if (b == t) {
					return ans;
				}
				LLVec c = b;
				for (int i = 0; i < N; ++i) {
					b[i] += c[(i + 1) % N];
				}
				if (*max_element(b.begin(), b.end()) > *max_element(t.begin(), t.end())) {
					break;
				}
				ans += "R";
			}
			LLVec c = a;
			for (int i = 0; i < N; ++i) {
				a[i] += c[(i - 1 + N) % N];
			}
			if (*max_element(a.begin(), a.end()) > *max_element(t.begin(), t.end())) {
				break;
			}
			w += "L";
		}
		return "No solution";
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
			long Arr0[] = {0,1,0,0,0};
			long Arr1[] = {0,1,2,1,0};
			string Arg2 = "LL";

			vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, construct(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			long Arr0[] = {0,0,0,1};
			long Arr1[] = {0,1,0,0};
			string Arg2 = "No solution";

			vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, construct(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			long Arr0[] = {1,2,3,4,5,6,7,8,9,10};
			long Arr1[] = {12,24,56,95,12,78,0,100,54,88};
			string Arg2 = "No solution";

			vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, construct(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			long Arr0[] = {1,0,0};
			long Arr1[] = {11,11,10};
			string Arg2 = "RRRRR";

			vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, construct(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			LL Arr0[] = {1,1};
			LL Arr1[] = {562949953421312,562949953421312};
			string Arg2 = "RLLLRRRLLRRRLRLRRLLLLRLLRRLRRRLRRLRRLLRRRLLRRRLLL";

			vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, construct(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			long Arr0[] = {0,0,0,0,0};
			long Arr1[] = {0,0,0,1,0};
			string Arg2 = "No solution";

			vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, construct(Arg0, Arg1));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			long Arr0[] = {123,456};
			long Arr1[] = {123,456};
			string Arg2 = "";

			vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, construct(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	LR ___test;
	___test.run_test(-1);
}
// END CUT HERE
