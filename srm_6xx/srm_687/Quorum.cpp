// BEGIN CUT HERE
/*
SRM 687 Div2 Easy (250)

PROBLEM STATEMENT

In one organization they have n different committees.
The organization has a very large number of employees.
Each employee is a member of each committee.

Each committee has a quorum: the smallest number of members that have to be present to have an official meeting.
You are given a vector <int> arr with n elements.
Each element of arr is the quorum of one committee.

You are also given an int k.
Yesterday, k different committees had an official meeting, all at the same time.
Obviously, each person attended at most one of those meetings.
Compute and return the smallest possible number of people who attended a meeting yesterday.


DEFINITION
Class:Quorum
Method:count
Parameters:vector <int>, int
Returns:int
Method signature:int count(vector <int> arr, int k)


NOTES
-The value of n is not given explicitly. Instead, you can determine it as the number of elements in arr.


CONSTRAINTS
-arr will contain between 1 and 50 elements, inclusive.
-Each element of arr will be between 1 and 50.
-k will be between 1 and the number of elements of arr, inclusive.


EXAMPLES

0)
{5,2,3}
1

Returns: 2

There are three committees.
The first committee requires 5 members to start a meeting, the second requires 2, and the third requires 3 members.
As k=1, there was one meeting yesterday.
The smallest possible solution is that it was a meeting of the second committee and that exactly 2 employees attended that meeting.


1)
{1,1,1,1,1}
5

Returns: 5

All five committees had a meeting yesterday.
We need at least one person per meeting.
No person can attend more than one meeting.
Hence, there must have been at least 5 different people.


2)
{50,2,9,49,38}
3

Returns: 49


3)
{20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1}
14

Returns: 105

*/
// END CUT HERE
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class Quorum {
public:
	int count(vector <int> arr, int k) {
		sort(arr.begin(), arr.end());
		return accumulate(arr.begin(), arr.begin() + k, 0);
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
			int Arr0[] = {5,2,3};
			int Arg1 = 1;
			int Arg2 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1,1,1,1};
			int Arg1 = 5;
			int Arg2 = 5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {50,2,9,49,38};
			int Arg1 = 3;
			int Arg2 = 49;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
			int Arg1 = 14;
			int Arg2 = 105;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Quorum ___test;
	___test.run_test(-1);
}
// END CUT HERE
