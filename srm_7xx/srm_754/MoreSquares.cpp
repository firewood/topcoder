// BEGIN CUT HERE
/*
SRM 754 Div1 Easy (250)

PROBLEM STATEMENT

Given a set of points in the plane, its square count is the number of ways in which we can select four of those points in such a way that they form the corners of a square.
The square may be rotated arbitrarily. Order of the four points does not matter. For example, the square count for the set { (1,2), (1,0), (0,1), (2,1) } is 1.

You are given a set S of points in the plane with integer coordinates.
Return the number of points P with the following property: P is not in S, and if we add P to S, the square count will increase.

In order to keep the input size small, S is given as follows:
You are given the ints N, SX, SY, and the vector <int>s Xprefix and Yprefix.
Use the pseudocode given below to generate S.

X, Y = two empty arrays of length N each
L    = length(Xprefix)

for i = 0 .. L-1:
    X[i] = Xprefix[i]
    Y[i] = Yprefix[i]

for i = L .. N-1:
    X[i] = ( X[i-1] * 47 + 42 ) modulo SX
    Y[i] = ( Y[i-1] * 47 + 42 ) modulo SY

for i = 0 .. N-1:
    if (X[i], Y[i]) is not in S:
        add (X[i], Y[i]) to S


DEFINITION
Class:MoreSquares
Method:countLocations
Parameters:int, int, int, vector <int>, vector <int>
Returns:int
Method signature:int countLocations(int N, int SX, int SY, vector <int> Xprefix, vector <int> Yprefix)


NOTES
-The reference solution would work fast enough for any input of the given size, it does not depend on any properties of the pseudorandom generator.
-The new point P can lie anywhere in the plane.


CONSTRAINTS
-N will be between 1 and 3,000, inclusive.
-SX and SY will each be between 1 and 10^6, inclusive.
-Xprefix will have between 1 and min(100,N) elements, inclusive.
-Yprefix will have the same number of elements as Xprefix.
-Each element of Xprefix will be between 0 and SX-1, inclusive.
-Each element of Yprefix will be between 0 and SY-1, inclusive.


EXAMPLES

0)
3
100
100
{3, 0, 2}
{0, 1, 2}

Returns: 1

The set S contains the points (3,0), (0,1), and (2,2). By adding a fourth point at (1,-1) we can increase the square count from 0 to 1.


1)
5
100
100
{47, 47, 47, 47, 47}
{47, 47, 47, 47, 47}

Returns: 0

The set S contains only one point: (47, 47). Adding a second point will always produce a two-element set with square count zero.


2)
23
11
13
{7}
{0}

Returns: 5

The set S contains 20 points. In the order of insertion, these are: (7, 0), (8, 3), (0, 1), (9, 11), (3, 0), (7, 3), (8, 1), (0, 11), (9, 0), (3, 3), (7, 1), (8, 11), (0, 0), (9, 3), (3, 1), (7, 11), (8, 0), (0, 3), (9, 1), (3, 11). The last three points generated using the formula in the statement are (7, 0), (8, 3), and (0, 1) again.


The five possible locations for the new point that increases the square count are (6, 2), (8, -1), (8, 2), (10, 2), and (11, 8).

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef pair<int, int> II;
typedef set<II> IISet;
typedef vector<II> IIVec;

class MoreSquares {
public:
	int countLocations(int N, int SX, int SY, vector <int> Xprefix, vector <int> Yprefix) {
		IISet s, ans;
		IIVec v(N);
		int psz = (int)Xprefix.size();
		for (int i = 0; i < N; ++i) {
			int x = i < psz ? Xprefix[i] : ((v[i - 1].first * 47 + 42) % SX);
			int y = i < psz ? Yprefix[i] : ((v[i - 1].second * 47 + 42) % SY);
			v[i] = II(x, y);
			s.insert(v[i]);
		}
		v = IIVec(s.begin(), s.end());
		for (int i = 0; i < (int)v.size(); ++i) {
			for (int j = i + 1; j < (int)v.size(); ++j) {
				int dx = v[j].first - v[i].first;
				int dy = v[j].second - v[i].second;
				II a(v[i].first - dy, v[i].second + dx), b(v[i].first + dy, v[i].second - dx);
				II c(v[j].first - dy, v[j].second + dx), d(v[j].first + dy, v[j].second - dx);
				bool ea = s.find(a) != s.end(), ec = s.find(c) != s.end();
				if (!ea && ec) {
					ans.insert(a);
				}
				if (ea && !ec) {
					ans.insert(c);
				}
				bool eb = s.find(b) != s.end(), ed = s.find(d) != s.end();
				if (!eb && ed) {
					ans.insert(b);
				}
				if (eb && !ed) {
					ans.insert(d);
				}
			}
		}
		return ans.size();
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
			int Arg0 = 3;
			int Arg1 = 100;
			int Arg2 = 100;
			int Arr3[] = {3, 0, 2};
			int Arr4[] = {0, 1, 2};
			int Arg5 = 1;

			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			verify_case(n, Arg5, countLocations(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 100;
			int Arg2 = 100;
			int Arr3[] = {47, 47, 47, 47, 47};
			int Arr4[] = {47, 47, 47, 47, 47};
			int Arg5 = 0;

			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			verify_case(n, Arg5, countLocations(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 23;
			int Arg1 = 11;
			int Arg2 = 13;
			int Arr3[] = {7};
			int Arr4[] = {0};
			int Arg5 = 5;

			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			verify_case(n, Arg5, countLocations(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MoreSquares ___test;
	___test.run_test(-1);
}
// END CUT HERE
