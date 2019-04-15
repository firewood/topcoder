// BEGIN CUT HERE
/*
SRM 755 Div1 Easy (250)

PROBLEM STATEMENT
Misof recently had an accident in which he managed to cut his left hand on some broken glass. He is now "all right" - meaning that he can only use his right hand for a while. Help him with some issues he has.
Misof needs to sort the objects on his shelf. The shelf has N+1 slots, numbered 0 through N from the left to the right. Slot N is currently empty and it should be empty once the shelf is sorted. Slots 0 through N-1 contain objects: for each i, slot i currently contains an object that belongs into slot target[i].
As Misof only has one working hand, he can only rearrange the shelf in one way: he can pick up any object and move it from its current slot into the one slot that is currently empty.
You are given the vector <int> target with at most 500 elements. Find any sequence of at most 1500 actions that will sort the shelf. Return a vector <int> containing instructions for Misof. Each element x of the return value represents the instruction "pick up the element that is currently in slot x and move it into the slot that is currently empty".

DEFINITION
Class:OneHandSort
Method:sortShelf
Parameters:vector <int>
Returns:vector <int>
Method signature:vector <int> sortShelf(vector <int> target)


NOTES
-While sorting the shelf. Misof can (and often has to) move some of the objects more than once.
-You are not required to minimize the number of moves.


CONSTRAINTS
-N will be between 1 and 500, inclusive.
-target will contain exactly N elements.
-Each element of target will be between 0 and N-1, inclusive.
-All elements of target will be distinct.


EXAMPLES

0)
{0, 1, 2}

Returns: { }

The shelf is already sorted, Misof can simply do nothing.

1)
{1, 2, 3, 0}

Returns: {2, 1, 0, 3, 4 }


In the beginning, the shelf looks as follows:


| 1 | 2 | 3 | 0 |   |
+---+---+---+---+---+


The return value describes the following solution:


Misof moves the object from slot 2. (This is the object that belongs into slot 3. Misof moves it to the empty slot 4.)
Misof moves the object from slot 1. (This is the object that belongs into slot 2. Misof moves it to the empty slot 2, where it belongs.)
Misof moves the object from slot 0. (This is the object that belongs into slot 1. Misof moves it to the empty slot 1, where it belongs.)
Misof moves the object from slot 3. (This is the object that belongs into slot 0. Misof moves it to the empty slot 0, where it belongs.)
Misof moves the object from slot 4. (This is the object that belongs into slot 3 - the one we already moved once at the beginning. Misof moves it to the empty slot 3, where it belongs.)

Other valid solutions exist.


2)
{1, 0, 3, 2}

Returns: {0, 1, 4, 2, 3, 4 }

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

class OneHandSort {
public:
	vector <int> sortShelf(vector <int> target) {
		int n = (int)target.size();
		vector <int> ans;
		vector <int> e = target;
		sort(e.begin(), e.end());
		target.push_back(-1);
		e.push_back(-1);
		while (target != e) {
			for (int i = 0; i < n; ++i) {
				if (target[i] != i) {
					int a = find(target.begin(), target.end(), i) - target.begin();
					int b = find(target.begin(), target.end(), -1) - target.begin();
					if (b == i) {
						ans.push_back(a);
						swap(target[i], target[a]);
					} else {
						ans.push_back(i);
						swap(target[i], target[b]);
						ans.push_back(a);
						swap(target[i], target[a]);
					}
				}
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
			int Arr0[] = {0, 1, 2};
///			int Arr1[] = { };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
//			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg1;
			verify_case(n, Arg1, sortShelf(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 2, 3, 0};
			int Arr1[] = {2, 1, 0, 3, 4 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, sortShelf(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 0, 3, 2};
			int Arr1[] = {0, 1, 4, 2, 3, 4 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, sortShelf(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	OneHandSort ___test;
	___test.run_test(-1);
}
// END CUT HERE
