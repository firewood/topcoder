// BEGIN CUT HERE
/*
SRM 644 Div2 Easy (250)

PROBLEM STATEMENT
Cat Snuke and Wolf Sothe came to an okonomiyaki restaurant.
(Okonomiyaki is a Japanese pancake.)
The restaurant makes several types of okonomiyaki.
Each type of okonomiyaki has its specific size.
You are given the sizes of all okonomiyaki types as a vector <int> osize.

The restaurant offers a discount if you order a meal for two persons.
Each such order must consist of two okonomiyakis of different types.
Additionally, the sizes of the two okonomiyakis must differ by K or less.

You are given the vector <int> osize and the int K.
Compute and return the number of different two-person meals offered by the restaurant.


DEFINITION
Class:OkonomiyakiShop
Method:count
Parameters:vector <int>, int
Returns:int
Method signature:int count(vector <int> osize, int K)


CONSTRAINTS
-osize will contain between 2 and 50 elements, inclusive.
-Each element in osize will be between 1 and 10,000, inclusive.
-K will be between 1 and 10,000, inclusive.


EXAMPLES

0)
{1,4,6,7,9}
3

Returns: 6

There are five types of okonomiyaki.
Let's call them types A, B, C, D, and E.
(Type A has size 1, type B has size 4, and so on.)
There are 6 valid two-person meals: A+B, B+C, B+D, C+D, C+E, and D+E.

Note that B+A is the same order as A+B: you get one pancake of type A and one pancake of type B.


1)
{1,1,3,3,3}
2

Returns: 10

Different types of okonomiyaki may have equal sizes.
A two-person meal may contain two okonomiyaki of the same size, they are only required to have a different type.
Therefore, in this test case each pair of different okonomiyaki can be ordered as a two-person meal.


2)
{1,5,9,14,20}
3

Returns: 0

In this test case there is no valid two-person meal: the differences in pancake sizes are all greater than K.


3)
{7,2,6,3,4,2,7,8,3,4,9,1,8,4,3,7,5,2,1,9,9,4,5}
6

Returns: 234

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class OkonomiyakiShop {
public:
	int count(vector <int> osize, int K) {
		int ans = 0;
		int N = (int)osize.size();
		for (int i = 0; i < N; ++i) {
			for (int j = i + 1; j < N; ++j) {
				ans += (abs(osize[i] - osize[j]) <= K);
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
			int Arr0[] = {1,4,6,7,9};
			int Arg1 = 3;
			int Arg2 = 6;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1,3,3,3};
			int Arg1 = 2;
			int Arg2 = 10;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,5,9,14,20};
			int Arg1 = 3;
			int Arg2 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {7,2,6,3,4,2,7,8,3,4,9,1,8,4,3,7,5,2,1,9,9,4,5};
			int Arg1 = 6;
			int Arg2 = 234;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	OkonomiyakiShop ___test;
	___test.run_test(-1);
}
// END CUT HERE
