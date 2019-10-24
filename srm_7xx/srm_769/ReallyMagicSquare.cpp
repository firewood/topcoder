// BEGIN CUT HERE
/*
SRM 739 Div2 Medium (500)

PROBLEM STATEMENT

An N times N square of integers is called a really magic square if it has the following property:
if you pick any N of the N^2 numbers in such a way that no two numbers share the same row and no two numbers share the same column, the sum of the numbers you picked will always be the same.

For example, here is a 4 times 4 square that is really magic:

 140   80  160   60
  90   30  110   10
 100   40  120   20
 130   70  150   50

In the figure below we show two of the twenty-four valid ways to select four numbers such that no two share the same row or column.
Note that in both cases the sum is the same: 130 + 80 + 110 + 20 = 130 + 40 + 160 + 10 = 340.

 140  (80) 160   60       140   80 (160)  60
  90   30 (110)  10        90   30  110  (10)
 100   40  120  (20)      100  (40) 120   20
(130)  70  150   50      (130)  70  150   50

You are given the top row of a really magic square in the vector <int> topRow and its main diagonal in the vector <int> mainDiagonal.
Construct any one really magic square that matches the given numbers.
Return a vector <int> that contains a list of all numbers in your really magic square, read from top to bottom and each row read left to right.
If there are multiple solutions, you may return any of them.
If there is no solution, return an empty vector <int>.


DEFINITION
Class:ReallyMagicSquare
Method:reconstruct
Parameters:vector <int>, vector <int>
Returns:vector <int>
Method signature:vector <int> reconstruct(vector <int> topRow, vector <int> mainDiagonal)


NOTES
-The main diagonal is the one going from top left to bottom right.
-If there is a solution, there is always a solution such that all numbers fit into an int.


CONSTRAINTS
-topRow will contain between 1 and 30 elements, inclusive.
-Each element in topRow will be between 1 and 1000, inclusive.
-mainDiagonal will contain the same number of elements as topRow.
-Each element in mainDiagonal will be between 1 and 1000, inclusive.
-topRow[0] will be equal to mainDiagonal[0].


EXAMPLES

0)
{140, 80, 160, 60}
{140, 30, 120, 50}

Returns: {140, 80, 160, 60, 90, 30, 110, 10, 100, 40, 120, 20, 130, 70, 150, 50 }

The example from the problem statement.

1)
{1,7}
{1,4}

Returns: {1, 7, -2, 4 }

The only missing number must be -2, as (-2)+7 = 1+4 = 5.

2)
{47,47,47,47,47}
{47,47,47,47,47}

Returns: {47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47 }

A square with all numbers equal is obviously really magic.

*/
// END CUT HERE
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class ReallyMagicSquare {
public:
	vector <int> reconstruct(vector <int> topRow, vector <int> mainDiagonal) {
		const int MAX = 1 << 30;
		int n = (int)topRow.size();
		vector<int> m(n * n, MAX);
		for (int i = 0; i < n; ++i) {
			m[i] = topRow[i];
			m[i * n + i] = mainDiagonal[i];
		}
		int sum = accumulate(mainDiagonal.begin(), mainDiagonal.end(), 0);
		for (int c = 0; c < n; ++c) {
			for (int r = 0; r < n; ++r) {
				if (m[r * n + c] == MAX) {
					int remain = sum;
					int rf = 1 << r, cf = 1 << c;
					for (int cc = n - 1; cc >= 0; --cc) {
						for (int rr = n - 1; rr >= 0; --rr) {
							if ((rf & (1 << rr)) == 0 && (cf & (1 << cc)) == 0 && m[rr * n + cc] != MAX) {
								rf |= 1 << rr;
								cf |= 1 << cc;
								remain -= m[rr * n + cc];
							}
						}
					}
					m[r * n + c] = remain;
				}
			}
		}
		return m;
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
			int Arr0[] = {140, 80, 160, 60};
			int Arr1[] = {140, 30, 120, 50};
			int Arr2[] = {140, 80, 160, 60, 90, 30, 110, 10, 100, 40, 120, 20, 130, 70, 150, 50 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, reconstruct(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,7};
			int Arr1[] = {1,4};
			int Arr2[] = {1, 7, -2, 4 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, reconstruct(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {47,47,47,47,47};
			int Arr1[] = {47,47,47,47,47};
			int Arr2[] = {47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, reconstruct(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ReallyMagicSquare ___test;
	___test.run_test(-1);
}
// END CUT HERE
