// BEGIN CUT HERE
/*
SRM 601 Div2 Medium (500)

PROBLEM STATEMENT

It's winter time!
You have some candies arranged in a row and now you want to choose some of them and give them to your friend.

You are given a vector <int> type.
Each candy has a type, which is some positive integer.
For each i, type[i] represents the type of i-th candy.
You want to choose some non-empty subset of candies with the following property:
if the number of candies you choose is K, their types must be precisely all the numbers from 1 to K, inclusive.
Return the number of different ways to do that.
(Two ways are considered different if there exists some candy that is chosen in only one of them.)


DEFINITION
Class:WinterAndCandies
Method:getNumber
Parameters:vector <int>
Returns:int
Method signature:int getNumber(vector <int> type)


NOTES
-The answer will always fit in a signed 32-bit integer.


CONSTRAINTS
-type will contain between 1 and 50 elements, inclusive.
-Each element of type will be between 1 and 50, inclusive.


EXAMPLES

0)
{1, 3, 2}

Returns: 3

There are 7 possible non-empty subsets in this case:

(1)

(3)

(2)

(1, 3)

(1, 2)

(3, 2)

(1, 3, 2)

Out of them, only first, fifth and seventh are valid. Thus, the answer is 3.


1)
{1, 1, 2}

Returns: 4

Note that the chosen subset can never contain two elements with the same type.


2)
{1, 3, 2, 5, 7, 4, 5, 4}

Returns: 9


3)
{1, 1, 2, 2, 3, 3, 4, 4, 5, 5}

Returns: 62


4)
{2}

Returns: 0

*/
// END CUT HERE

#include <string> 
#include <vector> 
#include <iostream> 
#include <sstream> 

using namespace std; 

class WinterAndCandies {
	public:
	int getNumber(vector <int> type) {
		int c[64] = {};
		for (int i = 0; i < (int)type.size(); ++i) {
			c[type[i]] += 1;
		}
		int ans = 0;
		int s = 1;
		for (int i = 1; i <= 50; ++i) {
			s *= c[i];
			ans += s;
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
			int Arr0[] = {1, 3, 2};
			int Arg1 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 1, 2};
			int Arg1 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 3, 2, 5, 7, 4, 5, 4};
			int Arg1 = 9;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
			int Arg1 = 62;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2};
			int Arg1 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

	}

// END CUT HERE


};
// BEGIN CUT HERE 
int main() {
	WinterAndCandies ___test;
	___test.run_test(-1);
}
// END CUT HERE
