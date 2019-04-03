// BEGIN CUT HERE
/*
SRM 754 Div2 Easy (250)

PROBLEM STATEMENT

One of Snow White's seven dwarves has gone missing!
She is sure he will turn up eventually, but she needs to know his height because she is knitting him a sweater.
Here is what she remembers about the heights:


The missing dwarf is strictly taller than any of the other six dwarves.
The height of each dwarf is a positive integer.
The average of all seven heights is also a positive integer.


You are given the vector <int> otherHeights.
The elements of otherHeights are the heights of the other six dwarves.
Determine the height of the missing dwarf.
As there are always multiple possibilitities, return the smallest one that matches the information you have.
(After all, dwarves are small.)


DEFINITION
Class:MissingDwarf
Method:getHeight
Parameters:vector <int>
Returns:int
Method signature:int getHeight(vector <int> otherHeights)


CONSTRAINTS
-otherHeights will contain exactly 6 elements.
-Each element of otherHeights will be between 1 and 1000, inclusive.


EXAMPLES

0)
{1,2,3,4,5,6}

Returns: 7

The height of the missing dwarf is 7. (The average height of a dwarf is exactly 4.)


1)
{6,5,4,3,2,1}

Returns: 7

The six heights can be given in any order.


2)
{10,10,20,20,30,30}

Returns: 34

Sometimes some of the six heights given as the input can be equal.


3)
{7,7,7,7,7,7}

Returns: 14

The missing dwarf must be taller than each of the six remaining dwarves.

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class MissingDwarf {
public:
	int getHeight(vector <int> otherHeights) {
		int ans = 0, sum = 0, n = (int)otherHeights.size() + 1;
		for (int h : otherHeights) {
			ans = max(ans, h + 1);
			sum += h;
		}
		int avg = (ans + sum + n - 1) / n;
		return avg * n - sum;
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
			int Arr0[] = {1,2,3,4,5,6};
			int Arg1 = 7;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getHeight(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {6,5,4,3,2,1};
			int Arg1 = 7;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getHeight(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10,10,20,20,30,30};
			int Arg1 = 34;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getHeight(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {7,7,7,7,7,7};
			int Arg1 = 14;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getHeight(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MissingDwarf ___test;
	___test.run_test(-1);
}
// END CUT HERE
