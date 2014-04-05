// BEGIN CUT HERE
/*
SRM 602 Div2 Medium (500)

PROBLEM STATEMENT
Snake Snuke has N rectangles cut out of paper.
The rectangles are labeled 0 through N-1.
You are given vector <int>s X and Y with N elements each.
For each i, the sides of rectangle i have lengths X[i] and Y[i].

Snake Snuke will choose some of his rectangles and place them onto a table, one rectangle at a time, in any order he likes.
Each rectangle (except for the first one) must overlap the immediately previous one, so at the end Snuke will have a pile of rectangles.
Snuke may rotate the rectangles, but once placed, the sides of each rectangle must be parallel to the sides of the table.
(I.e., he may only swap the width and height of some rectangles he places.)
After placing all the rectangles, Snuke computes the area that is covered by all N rectangles.
(Formally, the area of their intersection.)

You are also given an int limit.
The area computed by Snuke must be greater than or equal to limit.

Return the largest positive R such that Snuke can select some R of his rectangles and place them in such a way that the area of their intersection is at least limit. If there is no such R, return -1 instead.


DEFINITION
Class:PilingRectsDiv2
Method:getmax
Parameters:vector <int>, vector <int>, int
Returns:int
Method signature:int getmax(vector <int> X, vector <int> Y, int limit)


CONSTRAINTS
-X and Y will contain between 1 and 50 elements, inclusive.
-X and Y will contain the same number of elements.
-Each element of X and Y will be between 1 and 200, inclusive.
-limit will be between 1 and 40000, inclusive.


EXAMPLES

0)
{1,2,3,1}
{3,2,4,4}
3

Returns: 3

He can choose rectangles 0, 2, and 3. These three rectangles can then be placed in such a way that both rectangle 2 and rectangle 3 cover rectangle 0 completely. For this placement, the area of their intersection will be exactly 3.

1)
{4,7}
{7,4}
25

Returns: 2

Note that he can rotate rectangles.

2)
{10}
{10}
9999

Returns: -1

There is no possible choice.

3)
{10}
{3}
30

Returns: 1



4)
{3,6,5,8,2,9,14}
{14,6,13,8,15,6,3}
27

Returns: 4



5)
{121,168,86,106,36,10,125,97,53,26,148,129,41,18,173,55,13,73,91,174,177,190,28,164,122,92,5,26,58,188,14,67,48,196,41,94,24,89,54,117,12,6,155,103,200,128,184,29,92,149}
{199,182,43,191,2,145,15,53,38,37,61,45,157,129,119,123,177,178,183,188,132,108,112,137,92,59,75,196,102,152,114,121,181,93,32,3,24,116,4,163,96,159,196,43,59,150,79,113,20,146}
5345

Returns: 24



*/
// END CUT HERE

#include <string> 
#include <vector> 
#include <iostream> 
#include <sstream> 

using namespace std; 

class PilingRectsDiv2 {
	public:
	int getmax(vector <int> X, vector <int> Y, int limit) {
		int ans = -1;
		int N = (int)X.size();
		for (int y = 1; y <= 200; ++y) {
			for (int x = y; x <= 200; ++x) {
				if (x*y >= limit) {
					int c = 0;
					for (int i = 0; i < N; ++i) {
						int a = min(X[i], Y[i]);
						int b = max(X[i], Y[i]);
						c += a >= y && b >= x;
					}
					if (c > 0) {
						ans = max(ans, c);
					}
				}
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
			int Arr0[] = {1,2,3,1};
			int Arr1[] = {3,2,4,4};
			int Arg2 = 3;
			int Arg3 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, getmax(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4,7};
			int Arr1[] = {7,4};
			int Arg2 = 25;
			int Arg3 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, getmax(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10};
			int Arr1[] = {10};
			int Arg2 = 9999;
			int Arg3 = -1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, getmax(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10};
			int Arr1[] = {3};
			int Arg2 = 30;
			int Arg3 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, getmax(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3,6,5,8,2,9,14};
			int Arr1[] = {14,6,13,8,15,6,3};
			int Arg2 = 27;
			int Arg3 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, getmax(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {121,168,86,106,36,10,125,97,53,26,148,129,41,18,173,55,13,73,91,174,177,190,28,164,122,92,5,26,58,188,14,67,48,196,41,94,24,89,54,117,12,6,155,103,200,128,184,29,92,149};
			int Arr1[] = {199,182,43,191,2,145,15,53,38,37,61,45,157,129,119,123,177,178,183,188,132,108,112,137,92,59,75,196,102,152,114,121,181,93,32,3,24,116,4,163,96,159,196,43,59,150,79,113,20,146};
			int Arg2 = 5345;
			int Arg3 = 24;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, getmax(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE


};
// BEGIN CUT HERE 
int main() {
	PilingRectsDiv2 ___test;
	___test.run_test(-1);

}
// END CUT HERE

