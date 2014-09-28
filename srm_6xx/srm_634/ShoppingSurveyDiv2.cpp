// BEGIN CUT HERE
/*
SRM 634 Div2 Medium (500)

PROBLEM STATEMENT

A store sells M different items, conveniently numbered 0 through M-1.
For a shopping survey you interviewed N customers.
Each customer responded to the survey with a list of items they've bought.
Each customer bought at most one of each item.
It is possible that some customers did not buy anything at all.

After collecting the responses, you've summed up the results and found that s[i] people have bought item i.
Due to an unfortunate accident, you've then lost the actual survey responses.
All you have left are the values s[i] you computed.

You are now supposed to report the number of big shoppers among the survey respondents.
A big shopper is defined as a customer who has bought all M items.
Of course, having lost the detailed responses, you might be unable to determine the actual number of big shoppers.

You are given the int N and the vector <int> s with M elements.
Compute and return the smallest possible number of big shoppers.


DEFINITION
Class:ShoppingSurveyDiv2
Method:minValue
Parameters:int, vector <int>
Returns:int
Method signature:int minValue(int N, vector <int> s)


CONSTRAINTS
-N will be between 1 and 100, inclusive.
-s will contain between 1 and 100 elements, inclusive.
-Each element in s will be between 0 and N, inclusive.


EXAMPLES

0)
5
{3, 3}

Returns: 1

There are 5 customers and 2 items in the store.
Each of the items was bought by three of the customers.
Since there are five people and a total of six bought items, we must have at least one big shopper.
And we can easily verify that there could have been exactly one big shopper and four other customers who have bought one item each.


1)
100
{97}

Returns: 97


2)
10
{9, 9, 9, 9, 9}

Returns: 5


3)
7
{1, 2, 3}

Returns: 0


4)
5
{3, 3, 3}

Returns: 0

*/
// END CUT HERE
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class ShoppingSurveyDiv2 {
public:
	int minValue(int N, vector <int> s) {
		int M = (int)s.size();
		int mx = *min_element(s.begin(), s.end());
		int sum = accumulate(s.begin(), s.end(), 0);
		int ans;
		for (ans = 0; ans <= mx; ++ans) {
			if ((sum - (ans * M)) <= ((N - ans) * (M - 1))) {
				break;
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
			int Arg0 = 5;
			int Arr1[] = {3, 3};
			int Arg2 = 1;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minValue(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 100;
			int Arr1[] = {97};
			int Arg2 = 97;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minValue(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arr1[] = {9, 9, 9, 9, 9};
			int Arg2 = 5;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minValue(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 7;
			int Arr1[] = {1, 2, 3};
			int Arg2 = 0;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minValue(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arr1[] = {3, 3, 3};
			int Arg2 = 0;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minValue(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ShoppingSurveyDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
