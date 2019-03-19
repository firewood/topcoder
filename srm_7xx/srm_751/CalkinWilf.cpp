// BEGIN CUT HERE
/*
SRM 751 Div2 Easy (250)

PROBLEM STATEMENT

The Calkin-Wilf tree is a rooted tree that contains each positive rational number exactly once.
The definition of the tree is really simple: 

The root of the tree contains the value 1/1.
Each node in the tree has one left child and one right child.
If a node contains the fraction a/b, its left child contains the fraction a/(a+b) and its right child contains the fraction (a+b)/b.

Here is an ASCII art drawing of the first few levels of the tree:


                ____________1/1____________
               /                           \
        ____1/2____                     ____2/1____
       /           \                   /           \
    1/3             3/2             2/3             3/1
   /   \           /   \           /   \           /   \
1/4     4/3     3/5     5/2     2/5     5/3     3/4     4/1


You are given the string path that describes a path down the tree.
We start in the root and we read the characters of path one at a time.
Here, 'L' means "go to the left child" and 'R' means "go to the right child".


Find the fraction a/b that will be written in the last node we visit.
Return the vector <int> {a, b}.


DEFINITION
Class:CalkinWilf
Method:findRational
Parameters:string
Returns:vector <int>
Method signature:vector <int> findRational(string path)


NOTES
-The return value should be a vector <int> with two elements. Element 0 should be the numerator and element 1 should be the denominator of the fraction.


CONSTRAINTS
-path will contain between 0 and 30 characters, inclusive.
-Each character in path will be either 'L' or 'R'.


EXAMPLES

0)
""

Returns: {1, 1 }

If the path is empty, we end where we started: in the root.


1)
"R"

Returns: {2, 1 }

Taking a single step right takes us to the node with the value 2/1.


2)
"LRR"

Returns: {5, 2 }

This time we go 1/1 -> left to 1/2 -> right to 3/2 -> right to 5/2.


3)
"LRLRLRLRLRLRLRLRLRLRLRLRLRLRLR"

Returns: {2178309, 1346269 }

This is one possible longest valid input.

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

class CalkinWilf {
public:
	vector <int> findRational(string path) {
		int a = 1, b = 1;
		for (char c : path) {
			if (c == 'L') {
				b += a;
			} else {
				a += b;
			}
		}
		return { a, b };
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
			string Arg0 = "";
			int Arr1[] = {1, 1 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, findRational(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "R";
			int Arr1[] = {2, 1 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, findRational(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "LRR";
			int Arr1[] = {5, 2 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, findRational(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "LRLRLRLRLRLRLRLRLRLRLRLRLRLRLR";
			int Arr1[] = {2178309, 1346269 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, findRational(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	CalkinWilf ___test;
	___test.run_test(-1);
}
// END CUT HERE
