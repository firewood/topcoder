// BEGIN CUT HERE
/*
SRM 758 Div2 Medium (500)

PROBLEM STATEMENT

A sequence of distinct integers is called wild if it has the following properties:

It never increases twice in a row.
It never decreases twice in a row.

For example, {4, 7, 3, 9, 1, 5, 2} is a wild sequence but {4, 7, 3, 6, 9, 1, 5, 2} is not, as it increases twice in a row: from 3 to 6 and then from 6 to 9.

You are given the int head and the vector <int> rest.
Construct any wild sequence that begins with head and continues with the elements of rest, in an order of your choice. You must use each element of rest exactly once and you cannot use any other numbers in your sequence.
Return the answer as a vector <int>.
Any valid wild sequence will be accepted.
If there is no valid wild sequence, return an empty vector <int> instead.


DEFINITION
Class:WildSequence
Method:construct
Parameters:int, vector <int>
Returns:vector <int>
Method signature:vector <int> construct(int head, vector <int> rest)


CONSTRAINTS
-head will be between 0 and 10^6, inclusive.
-rest will contain between 0 and 49 elements, inclusive.
-Each element of rest will be between 0 and 10^6, inclusive.
-The elements of rest will be distinct.
-head will be distinct from all elements of rest.


EXAMPLES

0)
20
{10, 30}

Returns: {20, 10, 30 }

Both {20, 10, 30} and {20, 30, 10} are correct answers. You may return either of them.


1)
20
{10, 30, 40}

Returns: {20, 10, 40, 30 }

This time, there are three correct answers: {20, 10, 40, 30}, {20, 30, 10, 40}, and {20, 40, 10, 30}. You may return any one of these sequences.


2)
4
{1, 2, 3, 6, 7, 5}

Returns: {4, 7, 5, 6, 1, 3, 2 }

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class WildSequence {
public:
	vector <int> construct(int head, vector <int> rest) {
		vector <int> ans;
		sort(rest.begin(), rest.end());
		ans.push_back(head);
		if (rest.size()) {
			int left = -1, right = rest.size();
			bool dir = head > rest[0];
			while (left < right - 1) {
				if (dir) {
					ans.push_back(rest[++left]);
				} else {
					ans.push_back(rest[--right]);
				}
				dir = !dir;
			}
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 20;
			int Arr1[] = {10, 30};
			int Arr2[] = {20, 10, 30 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, construct(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 20;
			int Arr1[] = {10, 30, 40};
			int Arr2[] = {20, 10, 40, 30 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, construct(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arr1[] = {1, 2, 3, 6, 7, 5};
			int Arr2[] = {4, 7, 5, 6, 1, 3, 2 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, construct(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	WildSequence ___test;
	___test.run_test(-1);
}
// END CUT HERE
