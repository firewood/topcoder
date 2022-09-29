// BEGIN CUT HERE
/*
SRM 837 Div1 Easy (250)

PROBLEM STATEMENT

A perfect staircase made of unit cubes looks as follows:
It goes from the left to the right.
The first step is just a single cube, and each following step is built using one more cube than the previous one.

An example of such a staircase is shown below:

      #
     ##
    ###
   ####
  #####
 ######

(This is a 6-step staircase. It is built using 1+2+3+4+5+6 unit cubes.)

We can also use larger blocks when building such staircases.
Each of these blocks will be a cuboid with two parameters: width (measured left to right) and height (measured bottom to top).

These blocks are too heavy to lift, we can only push them around. Thus, all blocks must always stand on the ground, they cannot be placed on top of other blocks and/or unit cubes.

Below is another example staircase. This one is built out of a 1x3 block (width 1, height 3, denoted '0'), a 3x2 block (denoted '1') and some unit cubes (denoted '#').

      #
     ##
    ###
   0###
  #0111
 ##0111

You are given a collection of blocks: for each valid i you have a block that's W[i] units wide and H[i] units tall.

Calculate and return the minimum number of additional unit size cubes we need in order to build a perfect staircase that contains all of the given blocks.

(The staircase must go left to right. The blocks may appear inside the staircase in any order, and they don't have to be next to each other - see examples.)


DEFINITION
Class:StairsFromBlocks
Method:build
Parameters:vector <int>, vector <int>
Returns:long long
Method signature:long long build(vector <int> W, vector <int> H)


NOTES
-The blocks are also too heavy to tilt, so we cannot rotate them. E.g., a 3x2 block cannot be flipped and used as a 2x3 block.


CONSTRAINTS
-W will have between 1 and 100 elements, inclusive.
-H will have the same number of elements as W.
-All elements of W and H will be positive integers.
-For each i, W[i] * H[i] will be greater than 1.
-The sum of W will not exceed 10^9.
-The sum of H will not exceed 10^9.


EXAMPLES

0)
{3}
{3}

Returns: 6

We have a single 3x3 block. The best way to convert it into a complete valid staircase is shown below ('0's denote the block, '#'s are added unit cubes).


      #
     ##
    000
   #000
  ##000


1)
{1, 1, 1}
{3, 3, 4}

Returns: 5

A similar input to Example 0. Instead of a single block of width 3 we have three blocks of width 1 each that can be arranged into a similar shape. One optimal solution is shown below (using '0', '1' and '2' for the three blocks in the order in which they were given):


      #
     2#
    021
   #021
  ##021

(Note that we can put the blocks in any order we like, we don't have to preserve their original order.


2)
{2, 2}
{2, 5}

Returns: 7

One optimal solution is shown below.
Note that there may be gaps between the blocks.

       #
      11
     #11
    ##11
   00#11
  #00#11


3)
{6}
{1}

Returns: 15

Here it's optimal to build the entire staircase on top of the given block. The block will be the only thing touching the ground.


4)
{2, 2, 2}
{1, 1, 1}

Returns: 15

We put the three blocks next to each other and we get the situation from the previous example.


5)
{1234567}
{2345678}

Returns: 3513178688464

Watch out for integer overflow.

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

typedef long long LL;

typedef pair<LL, LL> II;

class StairsFromBlocks {
public:
	long long build(vector <int> W, vector <int> H) {
		int N = int(W.size());
		long long ans = 0, sum = 0;
		vector<II> v;
		for (int i = 0; i < N; ++i) {
			v.emplace_back(II(H[i], W[i]));
			sum += LL(H[i]) * W[i];
		}
		sort(v.rbegin(), v.rend());
		LL mh = v[0].first, mr = 0, r = 0;
		for (int i = 0; i < N; ++i) {
			r += v[i].second;
			mh = max(mh, v[i].first + (r - 1));
		}
		ans = mh * (mh + 1) / 2 - sum;
		return ans;
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
			int Arr0[] = {3};
			int Arr1[] = {3};
			long long Arg2 = 6LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, build(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 1, 1};
			int Arr1[] = {3, 3, 4};
			long long Arg2 = 5LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, build(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2, 2};
			int Arr1[] = {2, 5};
			long long Arg2 = 7LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, build(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {6};
			int Arr1[] = {1};
			long long Arg2 = 15LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, build(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2, 2, 2};
			int Arr1[] = {1, 1, 1};
			long long Arg2 = 15LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, build(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1234567};
			int Arr1[] = {2345678};
			long long Arg2 = 3513178688464LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, build(Arg0, Arg1));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	StairsFromBlocks ___test;
	___test.run_test(-1);
}
// END CUT HERE
