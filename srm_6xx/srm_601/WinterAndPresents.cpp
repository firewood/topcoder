// BEGIN CUT HERE
/*
SRM 601 Div1 Easy (250)

PROBLEM STATEMENT

It's winter time!
You need to prepare a Christmas gift for your friend.

You have several bags arranged in a row.
The bags only contain apples and oranges.
You are given an vector <int> apple and an vector <int> orange.
For each i, the i-th element of apple represents the number of apples in the i-th bag, and the i-th element of orange represents the number of oranges in the i-th bag.

You will choose the gift using the following procedure:
First, you will choose any positive integer X such that there are at least X pieces of fruit in each bag.
Then, you will take exactly X pieces of fruit out of each bag, and combine all the fruit into one present.
Return the number of different gifts that may be produced by following the given procedure.
(Two gifts are considered different if they contain a different number of apples or a different number of oranges.)


DEFINITION
Class:WinterAndPresents
Method:getNumber
Parameters:vector <int>, vector <int>
Returns:long long
Method signature:long long getNumber(vector <int> apple, vector <int> orange)


CONSTRAINTS
-apple will contain between 1 and 50 elements, inclusive.
-orange will contain between 1 and 50 elements, inclusive.
-apple and orange will contain the same number of elements.
-Each element of apple and orange will be between 0 and 1,000,000, inclusive.


EXAMPLES

0)
{1}
{1}

Returns: 3

Three different presents are possible in this case: 

0 apples and 1 orange

1 apple and 0 oranges

1 apple and 1 orange


1)
{1, 2, 0, 3}
{4, 5, 0, 6}

Returns: 0

As there is an empty bag, there is no way to choose the present.


2)
{2, 2, 2}
{2, 2, 2}

Returns: 16


3)
{7, 4, 5}
{1, 10, 2}

Returns: 46


4)
{1000000}
{1000000}

Returns: 1000002000000

*/
// END CUT HERE

#include <string> 
#include <vector> 
#include <iostream> 
#include <sstream> 

using namespace std; 

typedef long long LL;

class WinterAndPresents {
	public:
	long long getNumber(vector <int> apple, vector <int> orange) {
		LL ans = 0; 
		for (int m = 1; ; ++m) {
			int l = 0, r = 0; 
			for (int i = 0; i < (int)apple.size(); ++i) { 
				if ((apple[i]+orange[i]) < m) {
					return ans;
				}
				l += max(0, m-orange[i]);
				r += min(m, apple[i]);
			} 
			ans += (r-l+1); 
		} 
		return 0;
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
			int Arr0[] = {1};
			int Arr1[] = {1};
			long long Arg2 = 3LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 2, 0, 3};
			int Arr1[] = {4, 5, 0, 6};
			long long Arg2 = 0LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2, 2, 2};
			int Arr1[] = {2, 2, 2};
			long long Arg2 = 16LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {7, 4, 5};
			int Arr1[] = {1, 10, 2};
			long long Arg2 = 46LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1000000};
			int Arr1[] = {1000000};
			long long Arg2 = 1000002000000LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE


};
// BEGIN CUT HERE 
int main() {
	WinterAndPresents ___test;
	___test.run_test(-1);

}
// END CUT HERE

