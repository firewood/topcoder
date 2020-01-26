// BEGIN CUT HERE
/*
SRM 775 Div1 Easy (250)

PROBLEM STATEMENT

We use the following pseudocode to visit each cell of an N x N x N cube exactly once:

for sum = 0 .. 3*N-3:
    for x = 0 .. N-1:
        for y = 0 .. N-1:
            for z = 0 .. N-1:
                if x+y+z == sum:
                    visit (x,y,z)

You are given the int N and the long long index: a 0-based index into the sequence of cells visited by the above pseudocode.
Return a vector <int> containing the coordinates of that cell.


DEFINITION
Class:IterateOverACube
Method:findCell
Parameters:int, long long
Returns:vector <int>
Method signature:vector <int> findCell(int N, long long index)


CONSTRAINTS
-N will be between 1 and 10^6, inclusive.
-index will be between 0 and N^3 - 1, inclusive.


EXAMPLES

0)
3
9

Returns: {2, 0, 0 }

The first ten cells visited are (0,0,0), (0,0,1), (0,1,0), (1,0,0), (0,0,2), (0,1,1), (0,2,0), (1,0,1), (1,1,0), and (2,0,0).


1)
3
10

Returns: {0, 1, 2 }

The next visited cell is (0,1,2).


2)
4747
106968940722

Returns: {4746, 4746, 4746 }

The very last cell visited in this cube.


3)
4
32

Returns: {0, 2, 3 }

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

typedef long long LL;

class IterateOverACube {
public:
	vector <int> findCell(int N, long long index) {
		vector<LL> tc(N * 3);
		LL a, b, c = 0, d = 1, sum = 0;
		for (a = 0; a <= ((N - 1) * 3) / 2; ++a) {
			c += d;
			sum += c;
			tc[a] = sum;
			tc[(N - 1) * 3 - a] = sum;
			if (c >= N) {
				d = -2;
			}
		}
		for (sum = 0; sum <= (N - 1) * 3; ++sum) {
			if (index < tc[sum]) {
				break;
			}
			index -= tc[sum];
		}
		for (a = 0; a <= min((LL)N - 1, sum); ++a) {
			LL bm = min((LL)N - 1, sum - a);
			for (b = max(sum - a - (N - 1), 0LL); b <= bm; ++b) {
				if (index >= N) {
					index -= bm - b + 1;
					break;
				}
				if (index <= 0) {
					return { (int)a, (int)b, (int)(sum - a - b) };
				}
				--index;
			}
		}
		return {};
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
			int Arg0 = 3;
			long long Arg1 = 9LL;
			int Arr2[] = {2, 0, 0 };

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, findCell(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			long long Arg1 = 10LL;
			int Arr2[] = {0, 1, 2 };

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, findCell(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4747;
			long long Arg1 = 106968940722LL;
			int Arr2[] = {4746, 4746, 4746 };

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, findCell(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			long long Arg1 = 32LL;
			int Arr2[] = {0, 2, 3 };

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, findCell(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 4;
			long long Arg1 = 0LL;
			int Arr2[] = { 0, 0, 0 };

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, findCell(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 1000000;
			long long Arg1 = 999999999999999999LL;
			int Arr2[] = { 999999, 999999, 999999 };

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, findCell(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 86797;
			long long Arg1 = 299204922133549LL;
			int Arr2[] = { 57880, 27413, 39983 };

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, findCell(Arg0, Arg1));
		}
		n++;
	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	IterateOverACube ___test;
	___test.run_test(-1);
}
// END CUT HERE
