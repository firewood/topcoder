// BEGIN CUT HERE
/*
SRM 675 Div1 Easy (300)

PROBLEM STATEMENT
You are given an int s.
Your task is to construct an undirected tree such that:

The number of nodes is between 1 and 500, inclusive.
The number of simple paths of length 3 in the tree is exactly s.

Note that the direction of the simple path does not matter: A-B-C-D is the same simple path as D-C-B-A.

It is guaranteed that for the constraints used in this task a tree with the required properties always exists.
Find one such tree.

If your tree has n nodes, they must be labeled 0 through n-1.
Return a vector <int> with (n-1)*2 elements.
For each valid i, elements 2i and 2i+1 of the return value should be the endpoints of one of the edges in your tree.
If there are multiple correct solutions, you may return any of them.


DEFINITION
Class:TreeAndPathLength3
Method:construct
Parameters:int
Returns:vector <int>
Method signature:vector <int> construct(int s)


CONSTRAINTS
-s will be between 1 and 10,000, inclusive.


EXAMPLES

0)
1

Returns: {0, 1, 1, 2, 2, 3 }

The return value has 6 elements, so it has to describe a tree on 4 vertices.
This tree contains the edges 0-1, 1-2, and 2-3.
We can easily verify that this tree does indeed contain exactly one simple path of length 3: the path 0-1-2-3.


1)
2

Returns: {0, 1, 1, 2, 2, 3, 3, 4 }

The returned tree has 5 vertices.
The two simple paths of length 3 in this tree are the paths 0-1-2-3 and 1-2-3-4.


2)
6

Returns: {0, 1, 1, 2, 0, 3, 3, 4, 0, 5, 5, 6 }

The six simple paths of length 3 in this tree are the following paths:
2-1-0-3, 2-1-0-5, 4-3-0-1, 4-3-0-5, 6-5-0-1, and 6-5-0-3.


3)
8

Returns: {0, 1, 1, 2, 1, 3, 3, 4, 3, 5, 5, 6, 5, 7 }

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

class TreeAndPathLength3 {
public:
	vector <int> construct(int s) {
		vector <int> ans;
		if (s <= 100) {
			for (int i = 0; i < s + 2; ++i) {
				ans.push_back(i);
				ans.push_back(i + 1);
			}
		} else {
			int r = sqrt(s);
			int n = 0;
			for (int i = 1; i <= r + 1; ++i) {
				ans.push_back(0);
				ans.push_back(++n);
			}
			for (int i = 1; i < r; ++i) {
				ans.push_back(1);
				ans.push_back(++n);
			}
			ans.push_back(2);
			ans.push_back(++n);
			int t = r * r;
			while (t < s) {
				ans.push_back(n);
				ans.push_back(++n);
				++t;
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
			int Arg0 = 1;
			int Arr1[] = {0, 1, 1, 2, 2, 3 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arr1[] = {0, 1, 1, 2, 2, 3, 3, 4 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			int Arr1[] = {0, 1, 1, 2, 0, 3, 3, 4, 0, 5, 5, 6 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 8;
			int Arr1[] = {0, 1, 1, 2, 1, 3, 3, 4, 3, 5, 5, 6, 5, 7 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TreeAndPathLength3 ___test;
	___test.run_test(-1);
}
// END CUT HERE
