// BEGIN CUT HERE
/*
SRM 763 Div1 Easy (250)

PROBLEM STATEMENT

You have a square plate.
Its dimensions are 10000 x 10000.
The bottom left corner has coordinates (0, 0), the bottom right is (10000, 0), and the top right is (10000, 10000).

You are going to make Q cuts, one after another.
For each cut you are given two points (X1[i], Y1[i]) and (X2[i], Y2[i]) on different sides of the square.
You should cut the square along the straight line segment that connects those two points.
The cuts are in a general position (see Constraints).

After each query, determine the current number of pieces into which the square is divided at that moment.
Return a vector <int> with Q elements: those numbers of pieces.


DEFINITION
Class:CutCutCut
Method:findPieces
Parameters:vector <int>, vector <int>, vector <int>, vector <int>, int
Returns:vector <int>
Method signature:vector <int> findPieces(vector <int> X1, vector <int> Y1, vector <int> X2, vector <int> Y2, int Q)


CONSTRAINTS
-Q will be between 1 and 500, inclusive.
-Each of X1, Y1, X2 and Y2 will have exactly Q elements.
-All the given segment endpoints will be distinct.
-All the given segment endpoints will be on the boundary of the square.
-None of the given segment endpoints will be in the corners of the square.
-For each segment, its endpoints will lie on different sides of the square.
-No three cuts will intersect at the same point.


EXAMPLES

0)
{1, 2, 3}
{0, 0, 0}
{1, 2, 3}
{10000, 10000, 10000}
3

Returns: {2, 3, 4 }

Here we first cut the plate along the segment joining (1,0) and (1,10000), so we have 2 pieces now, next we cut along segment joing (2,0) and (2,10000)(cutting the right piece from pervious), so we have 3 pieces now, similarly after the 4th cut we have 4 pieces.


1)
{0, 5000}
{5000, 10000}
{10000, 5000}
{5000, 0}
2

Returns: {2, 4 }

Here we first cut the plate along the segment joining (0,5000) and (10000,5000), getting 2 pieces(equal pieces), then when we cut along segment joining (5000,1000) and (5000,0) we get 4 pieces(cutting previous 2 pieces again in equal parts).


2)
{1,0,3,9997}
{0,1,0,10000}
{1,10000,0,10000}
{10000,1,3,9997}
4

Returns: {2, 4, 7, 8 }

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class CutCutCut {
public:
	vector <int> findPieces(vector <int> X1, vector <int> Y1, vector <int> X2, vector <int> Y2, int Q) {
		int cnt = 1;
		vector <int> ans(Q);
		for (int i = 0; i < Q; ++i) {
			++cnt;
			for (int j = 0; j < i; ++j) {
				int a = X1[i], b = Y1[i], c = X2[i], d = Y2[i];
				int e = X1[j], f = Y1[j], g = X2[j], h = Y2[j];
				double aa = (d - b) * (g - e) - (c - a) * (h - f);
				double bb = (f * g - e * h) * (c - a) - (b * c - a * d) * (g - e);
				double cc = (f * g - e * h) * (d - b) - (b * c - a * d) * (h - f);
				if (aa != 0) {
					double x = bb / aa, y = cc / aa;
					cnt += x > 0 && x < 10000 && y > 0 && y < 10000;
				}
			}
			ans[i] = cnt;
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
			int Arr0[] = {1, 2, 3};
			int Arr1[] = {0, 0, 0};
			int Arr2[] = {1, 2, 3};
			int Arr3[] = {10000, 10000, 10000};
			int Arg4 = 3;
			int Arr5[] = {2, 3, 4 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0])));
			verify_case(n, Arg5, findPieces(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 5000};
			int Arr1[] = {5000, 10000};
			int Arr2[] = {10000, 5000};
			int Arr3[] = {5000, 0};
			int Arg4 = 2;
			int Arr5[] = {2, 4 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0])));
			verify_case(n, Arg5, findPieces(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,0,3,9997};
			int Arr1[] = {0,1,0,10000};
			int Arr2[] = {1,10000,0,10000};
			int Arr3[] = {10000,1,3,9997};
			int Arg4 = 4;
			int Arr5[] = {2, 4, 7, 8 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0])));
			verify_case(n, Arg5, findPieces(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arr0[] = {  1000,  9000,     1 };
			int Arr1[] = {     0,     0, 10000 };
			int Arr2[] = {  9000,  1000,  999 };
			int Arr3[] = { 10000, 10000,     0 };
			int Arg4 = 3;
			int Arr5[] = { 2, 4, 5 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0])));
			verify_case(n, Arg5, findPieces(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;
	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	CutCutCut ___test;
	___test.run_test(-1);
}
// END CUT HERE
