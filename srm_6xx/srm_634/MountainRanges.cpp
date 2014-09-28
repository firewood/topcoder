// BEGIN CUT HERE
/*
SRM 634 Div2 Easy (250)

PROBLEM STATEMENT

Tom is in charge of a tourist agency.
He has a lovely picture of the local mountain range.
He would like to sell it to the tourists but first he needs to know how many peaks are visible in the picture.

The mountain range in the picture can be seen as a sequence of heights.
You are given these heights as a vector <int> height.
An element of height is called a peak if its value is strictly greater than each of the values of adjacent elements.
Compute and return the number of peaks in the given mountain range.


DEFINITION
Class:MountainRanges
Method:countPeaks
Parameters:vector <int>
Returns:int
Method signature:int countPeaks(vector <int> heights)


CONSTRAINTS
-heights will contain between 1 and 50 elements, inclusive.
-Each element of heights will be between 1 and 100, inclusive.


EXAMPLES

0)
{5, 6, 2, 4}

Returns: 2

Element 1 (0-based index) is a peak.
Its height is 6, which is strictly greater than each of its neighbors' heights (5 and 2). 
Element 3 is also a peak since its height is 4 and that is strictly greater than its neighbor's height (which is 2).


1)
{1, 1, 1, 1, 1, 1, 1}

Returns: 0

This is a very flat mountain with no peaks.


2)
{2, 1}

Returns: 1

Element 0 is a peak.


3)
{2,5,3,7,2,8,1,3,1}

Returns: 4

The peaks here are the elements with 0-based indices 1, 3, 5, and 7. Their heights are 5, 7, 8, and 3, respectively.


4)
{1}

Returns: 1

Element 0 is a peak. Even though it has no neighbors, the condition from the problem statement is still satisfied.


5)
{1,2,3,4,4,3,2,1}

Returns: 0

According to our definition there is no peak in this mountain range.

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class MountainRanges {
public:
	int countPeaks(vector <int> heights) {
		heights.insert(heights.begin(), 0);
		heights.push_back(0);
		int ans = 0;
		for (int i = 1; i < heights.size() - 1; ++i) {
			ans += (heights[i - 1] < heights[i] && heights[i] > heights[i + 1]);
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
			int Arr0[] = {5, 6, 2, 4};
			int Arg1 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, countPeaks(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 1, 1, 1, 1, 1, 1};
			int Arg1 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, countPeaks(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2, 1};
			int Arg1 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, countPeaks(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,5,3,7,2,8,1,3,1};
			int Arg1 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, countPeaks(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1};
			int Arg1 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, countPeaks(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2,3,4,4,3,2,1};
			int Arg1 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, countPeaks(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MountainRanges ___test;
	___test.run_test(-1);
}
// END CUT HERE
