// BEGIN CUT HERE
/*
SRM 591 Div1 Easy (275)

PROBLEM STATEMENT
Manao is working in the Tree Research Center.
It may come as a surprise that the trees they research are not the ones you can see in a park.
Instead, they are researching special graphs.
(See Notes for definitions of terms related to these trees.)

Manao's daily job is reconstructing trees, given some partial information about them.
Today Manao faced a difficult task.
He needed to find the maximum possible diameter of a tree, given the following information:


Some vertex in the tree is called V.
The distance between V and the farthest vertex from V is D.
For each x between 1 and D, inclusive, Manao knows the number of vertices such that their distance from V is x.


You are given a vector <int> cnt containing D strictly positive integers.
For each i, the i-th element of cnt is equal to the number of vertices which have distance i+1 from V.
Please help Manao with his task.
Return the maximum possible diameter of a tree that matches the given information.


DEFINITION
Class:TheTree
Method:maximumDiameter
Parameters:vector <int>
Returns:int
Method signature:int maximumDiameter(vector <int> cnt)


NOTES
-A tree is a connected graph with no cycles. Note that each tree with N vertices has precisely N-1 edges.
-The distance between two vertices of a tree is the smallest number of edges one has to traverse in order to get from one of the vertices to the other one.
-The diameter of a tree is the maximum of all pairwise distances. In other words, the diameter is the distance between the two vertices that are the farthest away from each other.


CONSTRAINTS
-cnt will contain between 1 and 50 elements, inclusive.
-Each element of cnt will be between 1 and 1000, inclusive.


EXAMPLES

0)
{3}

Returns: 2

The only tree that matches the given information is shown below. The vertex V is red.


1)
{2, 2}

Returns: 4

There are two trees which correspond to the given partial information:

The tree on the left has diameter 3 and the tree on the right has diameter 4.


2)
{4, 1, 2, 4}

Returns: 5

This is one example of a tree that corresponds to the given constraints and has the largest possible diameter.


3)
{4, 2, 1, 3, 2, 5, 7, 2, 4, 5, 2, 3, 1, 13, 6}

Returns: 21

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class TheTree {
public:
	int maximumDiameter(vector <int> cnt) {
		int h = (int)cnt.size();
		int ans = 0;
		int i, j;
		for (i = 0; i < h; ++i) {
			int sum = h-i;
			for (j = i; j < h; ++j) {
				if (cnt[j] <= 1) {
					break;
				}
				++sum;
			}
			ans = max(ans, sum);
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
			int Arr0[] = {3};
			int Arg1 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maximumDiameter(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2, 2};
			int Arg1 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maximumDiameter(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4, 1, 2, 4};
			int Arg1 = 5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maximumDiameter(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4, 2, 1, 3, 2, 5, 7, 2, 4, 5, 2, 3, 1, 13, 6};
			int Arg1 = 21;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maximumDiameter(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TheTree ___test;
	___test.run_test(-1);
}
// END CUT HERE
