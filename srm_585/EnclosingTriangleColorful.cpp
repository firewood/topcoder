// BEGIN CUT HERE
/*
SRM 585 Div2 Hard (1000)

PROBLEM STATEMENT
You are given an int m. 
Consider a square in the plane such that the corners of the square have coordinates (0, 0), (m, 0), (m, m), and (0, m). 
All the lattice points on the sides of this square are colored, as described below: 

The points with coordinates (1, 0), ..., (m-1, 0) are red. 
The points with coordinates (m, 1), ..., (m, m-1) are green. 
The points with coordinates (m-1, m), ..., (1, m) are blue. 
The points with coordinates (0, m-1), ..., (0, 1) are yellow. 

Some other lattice points are black. 
Each black point lies strictly inside the square. 
You are given two vector <int>s: x and y. 
These describe the black points: 
For each i, there is a black point at (x[i], y[i]). 



You want to draw a triangle such that: 

its vertices have three distinct colors out of the set { red, green, blue, yellow }, 
all black points lie inside or on the boundary of the triangle. 

Return the number of ways to draw such a triangle. 


DEFINITION
Class:EnclosingTriangleColorful
Method:getNumber
Parameters:int, vector <int>, vector <int>
Returns:int
Method signature:int getNumber(int m, vector <int> x, vector <int> y)


CONSTRAINTS
-m will be between 2 and 300, inclusive. 
-x and y will each contain between 1 and 50 elements, inclusive. 
-x and y will contain the same number of elements. 
-Each element of x and y will be between 1 and m-1, inclusive. 
-All points described by x and y will be distinct. 


EXAMPLES

0)
4
{ 1, 2, 3 }
{ 1, 3, 2 }

Returns: 8

The picture shows the 8 ways to draw a triangle. 


1)
7
{ 1, 1, 6, 6 }
{ 1, 6, 1, 6 }

Returns: 0


2)
4
{ 2 }
{ 2 }

Returns: 72


3)
10
{ 2, 6, 7, 6 }
{ 7, 7, 9, 3 }

Returns: 52


4)
15
{ 7, 6, 5, 4, 3 }
{ 1, 4, 7, 10, 13 }

Returns: 150


5)
300
{ 117, 183, 181, 118, 132, 128, 184, 150, 168, 121, 
  179, 132, 168, 182, 119, 117, 180, 120, 175, 177, 
  116, 175, 128, 163, 181, 178, 123, 118, 172, 143, 
  163, 157, 179, 122, 121, 119, 157, 122, 150, 180, 
  137, 177, 125, 123, 172, 125, 137, 143, 120, 178 }

{ 157, 157, 132, 163, 181, 180, 150, 116, 181, 125, 
  125, 119, 119, 163, 132, 143, 172, 172, 179, 178, 
  150, 121, 120, 118, 168, 123, 178, 137, 120, 117, 
  182, 117, 175, 177, 175, 168, 183, 123, 184, 128, 
  118, 122, 179, 122, 180, 121, 182, 183, 128, 177 }

Returns: 21690886

*/
// END CUT HERE
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;

#define EPS 1.0e-9

class EnclosingTriangleColorful {

public:
	int getNumber(int m, vector <int> x, vector <int> y) {
		static char R[1204][1204] = {};
		memset(R, 0, sizeof(R));
		int N = (int)x.size();
		int sx[] = {0, 0, m, m};
		int sy[] = {0, m, m, 0};
		int dx[] = {0, 1, 0, -1};
		int dy[] = {1, 0, -1, 0};
		for (int a = 1; a < m*4; ++a) {
			int b = a / m, c = a % m;
			if (c == 0) {
				continue;
			}
			int x1 = sx[b] + dx[b] * c, y1 = sy[b] + dy[b] * c;
			for (int d = (b+1)*m+1; d < m*4; ++d) {
				int e = d / m, f = d % m;
				if (f == 0) {
					continue;
				}
				int x2 = sx[e] + dx[e] * f, y2 = sy[e] + dy[e] * f;

				int equal = 0, plus = 0, minus = 0;
				for (int i = 0; i < N; ++i) {
					int g = (x2-x1)*(y[i]-y1)-(y2-y1)*(x[i]-x1);
					if (g == 0) {
						++equal;
					} else if (g > 0) {
						++plus;
						if (minus > 0) {
							break;
						}
					} else {
						++minus;
						if (plus > 0) {
							break;
						}
					}
				}
				if (plus > 0 && minus > 0) {
					continue;
				}
				if (plus > 0 || (plus == 0 && minus == 0)) {
//					L[a][d] = 1;
					R[d][a] = 1;
				}
				if (minus > 0 || (plus == 0 && minus == 0)) {
					R[a][d] = 1;
//					L[d][a] = 1;
				}
			}
		}

		int ans = 0;
		for (int a = 1; a < m*4; ++a) {
			if ((a % m) == 0) {
				continue;
			}
			for (int b = (a/m+1)*m+1; b < m*4; ++b) {
				if ((b % m) == 0) {
					continue;
				}
				if (R[a][b]) {
					for (int c = (b/m+1)*m+1; c < m*4; ++c) {
						if ((c % m) == 0) {
							continue;
						}
						if (R[b][c] && R[c][a]) {
							++ans;
						}
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
			int Arg0 = 4;
			int Arr1[] = { 1, 2, 3 };
			int Arr2[] = { 1, 3, 2 };
			int Arg3 = 8;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, getNumber(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 7;
			int Arr1[] = { 1, 1, 6, 6 };
			int Arr2[] = { 1, 6, 1, 6 };
			int Arg3 = 0;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, getNumber(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arr1[] = { 2 };
			int Arr2[] = { 2 };
			int Arg3 = 72;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, getNumber(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arr1[] = { 2, 6, 7, 6 };
			int Arr2[] = { 7, 7, 9, 3 };
			int Arg3 = 52;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, getNumber(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 15;
			int Arr1[] = { 7, 6, 5, 4, 3 };
			int Arr2[] = { 1, 4, 7, 10, 13 };
			int Arg3 = 150;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, getNumber(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 300;
			int Arr1[] = { 117, 183, 181, 118, 132, 128, 184, 150, 168, 121, 
  179, 132, 168, 182, 119, 117, 180, 120, 175, 177, 
  116, 175, 128, 163, 181, 178, 123, 118, 172, 143, 
  163, 157, 179, 122, 121, 119, 157, 122, 150, 180, 
  137, 177, 125, 123, 172, 125, 137, 143, 120, 178 }
;
			int Arr2[] = { 157, 157, 132, 163, 181, 180, 150, 116, 181, 125, 
  125, 119, 119, 163, 132, 143, 172, 172, 179, 178, 
  150, 121, 120, 118, 168, 123, 178, 137, 120, 117, 
  182, 117, 175, 177, 175, 168, 183, 123, 184, 128, 
  118, 122, 179, 122, 180, 121, 182, 183, 128, 177 }
;
			int Arg3 = 21690886;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, getNumber(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EnclosingTriangleColorful ___test;
	___test.run_test(-1);
}
// END CUT HERE
