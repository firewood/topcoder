// BEGIN CUT HERE
/*
SRM 626 Div2 Easy (250)

PROBLEM STATEMENT

You are given a vector <int> array.
At any moment, you may choose a nonempty contiguous subsequence of array.
Whenever you do so, you will gain power equal to the sum of all elements in the chosen subsequence.

You chose each possible contiguous subsequence exactly once, each time gaining some power.
Compute and return the total amount of power you gained.


DEFINITION
Class:SumOfPower
Method:findSum
Parameters:vector <int>
Returns:int
Method signature:int findSum(vector <int> array)


CONSTRAINTS
-array will contain between 1 and 50 elements, inclusive.
-Each element in array will be between 1 and 100, inclusive.


EXAMPLES

0)
{1,2}

Returns: 6

We have the following three contiguous subsequences:

 {1} => 1 
 {2} => 2 
 {1,2} => 3 

Thus, the sum of all possible powers is 1+2+3=6.


1)
{1,1,1}

Returns: 10

A 3-element sequence has 6 possible nonempty contiguous subsequences.
For the sequence {1,1,1} these are the subsequences: {1}, {1}, {1}, {1,1}, {1,1}, and {1,1,1}.
Their sums are 1, 1, 1, 2, 2, and 3.
If you choose each of them once, the total power you'll gain is 1+1+1+2+2+3 = 10.


2)
{3,14,15,92,65}

Returns: 1323


3)
{1,2,3,4,5,6,7,8,9,10}

Returns: 1210

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class SumOfPower {
public:
	int findSum(vector <int> array) {
		int s[64] = { 0 };
		int N = (int)array.size();
		for (int i = 0; i < N; ++i) {
			s[i+1] = s[i] + array[i];
		}
		int ans = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = i; j < N; ++j) {
				ans += s[j+1] - s[i];
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
			int Arr0[] = {1,2};
			int Arg1 = 6;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findSum(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1,1};
			int Arg1 = 10;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findSum(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3,14,15,92,65};
			int Arg1 = 1323;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findSum(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2,3,4,5,6,7,8,9,10};
			int Arg1 = 1210;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findSum(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SumOfPower ___test;
	___test.run_test(-1);
}
// END CUT HERE
