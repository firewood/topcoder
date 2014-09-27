// BEGIN CUT HERE
/*
SRM 634 Div1 Easy (250)

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
A big shopper is defined as a customer who has bought K or more items.
Of course, having lost the detailed responses, you might be unable to determine the actual number of big shoppers.

You are given the ints N and K, and the vector <int> s with M elements.
Compute and return the smallest possible number of big shoppers.


DEFINITION
Class:ShoppingSurveyDiv1
Method:minValue
Parameters:int, int, vector <int>
Returns:int
Method signature:int minValue(int N, int K, vector <int> s)


CONSTRAINTS
-N will be between 1 and 500, inclusive.
-s will contain between 1 and 500 elements, inclusive.
-Each element in s will be between 0 and N, inclusive.
-K will be between 1 and the length of s, inclusive.


EXAMPLES

0)
10
2
{1, 2, 3}

Returns: 0

There are 10 customers.
Item 0 was bought by 1 customer, item 1 by 2 customers, and item 2 by 3 of the customers.
A big shopper is a customer who bought at least 2 items.
Given this data it is possible that there are no big shoppers at all.
(There could have been six customers who bought one item each, and four other customers who didn't buy anything at all.)


1)
5
2
{1, 2, 3}

Returns: 1


2)
4
4
{4, 4, 4, 2}

Returns: 2


3)
20
3
{1, 10, 3, 4, 8, 15, 3, 16, 18, 2, 7, 3}

Returns: 10


4)
4
2
{1, 2, 1, 1, 3, 1, 2, 2, 1, 2, 1}

Returns: 2


5)
2
3
{1, 1, 1, 2}

Returns: 1

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class ShoppingSurveyDiv1 {
public:

	int minValue(int N, int K, vector <int> s) {
		int ans;
		for (ans = 0; ans < N; ++ans) {
			int sum = 0;
			for (int x : s) {
				sum += max(0, x - ans);
			}
			if (sum <= (K - 1) * (N - ans)) {
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
			int Arg0 = 10;
			int Arg1 = 2;
			int Arr2[] = {1, 2, 3};
			int Arg3 = 0;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, minValue(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 2;
			int Arr2[] = {1, 2, 3};
			int Arg3 = 1;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, minValue(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 4;
			int Arr2[] = {4, 4, 4, 2};
			int Arg3 = 2;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, minValue(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 20;
			int Arg1 = 3;
			int Arr2[] = {1, 10, 3, 4, 8, 15, 3, 16, 18, 2, 7, 3};
			int Arg3 = 10;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, minValue(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 2;
			int Arr2[] = {1, 2, 1, 1, 3, 1, 2, 2, 1, 2, 1};
			int Arg3 = 2;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, minValue(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 3;
			int Arr2[] = {1, 1, 1, 2};
			int Arg3 = 1;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, minValue(Arg0, Arg1, Arg2));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 3;
			int Arr2[] = { 3, 3, 3 };
			int Arg3 = 3;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, minValue(Arg0, Arg1, Arg2));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 2;
			int Arr2[] = { 1, 2, 3 };
			int Arg3 = 2;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, minValue(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ShoppingSurveyDiv1 ___test;
	___test.run_test(-1);
}
// END CUT HERE
