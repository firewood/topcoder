// BEGIN CUT HERE
/*
SRM 674 Div1 Easy (250)

PROBLEM STATEMENT
You are a genealogist specializing in family trees of vampires. Vampire family trees differ from human family trees.
In particular, vampires are "born" in a different way.
The only way to create a new vampire is that an existing vampire turns a living human into a new vampire.
Whenever this happens, we say that the older vampire is the master and the newly created vampire is the servant of that master.

Given a particular family of vampires, the distance between two vampires is
the smallest number of steps along the family tree we need to make in order to get from one vampire to the other.
Formally, in each step you can move from the current vampire to any of its servants,
or to its master (if it has one). Note that for each vampire V the distance between V and V is zero.

You are now studying one particular family of vampires.
These vampires have all been created from a single vampire: the True Ancestor.
This special vampire has no master.
You know that there are n vampires in the family, and you have numbered them 0 through n-1 (in no particular order).

You do not know the master/servant relationships between the vampires in the family.
The only information you have is a vector <int> num with n elements.
For each valid i, the following statement is true: "If vampire i is the True Ancestor, he has exactly num[i] servants.
Otherwise, he has exactly (num[i] - 1) servants."

Consider all valid family trees that are consistent with this information.
If there are no such trees, return -1. Otherwise, find and return the maximum distance between any two vampires in any of those family trees.
(In other words, for each of the corresponding trees determine the maximum distance, and return the maximum of those maximums.)


DEFINITION
Class:VampireTree
Method:maxDistance
Parameters:vector <int>
Returns:int
Method signature:int maxDistance(vector <int> num)


CONSTRAINTS
-num will contain between 2 and 20 elements, inclusive.
-Each element of num will be between 1 and n-1, inclusive.


EXAMPLES

0)
{1, 2, 1}

Returns: 2

One possible solution is that vampire 1 is the True Ancestor, and vampires 0 and 2 are its servants.


1)
{2, 2, 2}

Returns: -1

At least two of the vampires must have two servants, but there needs to be at least 5 vampires for such a situation to happen (excluding the True Ancestor).


2)
{1, 1, 1, 1, 4}

Returns: 2


3)
{1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19}

Returns: -1

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class VampireTree {
public:
	int maxDistance(vector <int> num) {
		int ans = 1, sum = 0;
		for (int n : num) {
			sum += n;
			if (n > 1) {
				++ans;
			}
		}
		return sum == ((num.size() - 1) * 2) ? ans : -1;
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
			int Arr0[] = {1, 2, 1};
			int Arg1 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxDistance(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2, 2, 2};
			int Arg1 = -1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxDistance(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 1, 1, 1, 4};
			int Arg1 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxDistance(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
			int Arg1 = -1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxDistance(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	VampireTree ___test;
	___test.run_test(-1);
}
// END CUT HERE
