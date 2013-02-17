// BEGIN CUT HERE
/*
// SRM 570 Div1 Easy (250)

PROBLEM STATEMENT
Robot Herb is playing on an infinite square grid.
At any moment, Herb stands on one of the squares and he faces one of the four cardinal directions.
In his memory, Herb has a program.
The program is a sequence of commands.
For each i, the i-th of these commands has the following form:

First move forward a[i] tiles.
Then turn 90 degrees to the right, a[i] times in a row.

Herb has decided to run the program T times.
You are given the int T and the vector <int> a that describes Herb's program.
Let A be the initial position of Herb and B be his position after the program was executed T times.
Return the Manhattan distance between tiles A and B.


DEFINITION
Class:RobotHerb
Method:getdist
Parameters:int, vector <int>
Returns:long long
Method signature:long long getdist(int T, vector <int> a)


NOTES
-Let's introduce a Cartesian coordinate system on the grid so that each cardinal direction is parallel to one of the axes.
 The Manhattan distance between two tiles with centers at points (x1, y1) and (x2, y2) is defined as |x1-x2| + |y1-y2|.


CONSTRAINTS
-T will be between 1 and 1,000,000,000, inclusive.
-a will contain between 1 and 50 elements, inclusive.
-Each element of a will be between 1 and 10,000,000, inclusive.


EXAMPLES

0)
1
{1,2,3}

Returns: 2

Suppose that initially Herb stands on the tile with center at (0, 0) and faces the positive y direction. The program will get executed as follows:

                       tile         direction
After 1st command:     (0, 1)       positive x
After 2nd command:     (2, 1)       negative x
After 3rd command:     (-1, 1)      negative y

The manhattan distance between the initial and the final positions is |-1| + |1| = 2.


1)
100
{1}

Returns: 0


2)
5
{1,1,2}

Returns: 10


3)
1000000000
{100}

Returns: 100000000000

The answer doesn't fit into a 32-bit integer data type.


4)
570
{2013,2,13,314,271,1414,1732}

Returns: 4112

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

class RobotHerb {

public:
	long long getdist(int T, vector <int> a) {
		int sz = (int)a.size();
		int d = 0;
		int dx[] = {1,0,-1,0};
		int dy[] = {0,-1,0,1};
		LL i, j, x = 0, y = 0;
		for (i = 1; i <= T; ++i) {
			for (j = 0; j < sz; ++j) {
				x += dx[d] * a[j];
				y += dy[d] * a[j];
				d = (d + a[j]) % 4;
			}
			if (i == 4) {
				i = T - (T%4);
				x *= (T/4);
				y *= (T/4);
			}
		}
		return max(x,-x)+max(y,-y);
	}



	long long getdist2(int T, vector <int> a) {
		int sz = (int)a.size();
		int c = 0;
		int dx[] = {1,0,-1,0};
		int dy[] = {0,-1,0,1};
		LL i, j, x = 0, y = 0;
		for (i = 0; i < T; ++i) {
			for (j = 0; j < sz; ++j) {
				x += dx[c] * a[j];
				y += dy[c] * a[j];
				c = (c + a[j]) % 4;
			}
		}
		if (x<0)x=-x;
		if (y<0)y=-y;
		return x+y;
	}


// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const long long &Expected, const long long &Received, const long long &Received2) {
		cerr << "Test Case #" << Case << "...";
		if (Received != Received2) {
			cerr << "FAILED" << endl;
			cerr << "\1: \"" << Received << '\"' << endl;
			cerr << "\2: \"" << Received2 << '\"' << endl;
		} else if (Expected == Received) {
			cerr << "PASSED" << endl;
		} else {
			cerr << "FAILED" << endl;
			cerr << "\tExpected: \"" << Expected << '\"' << endl;
			cerr << "\tReceived: \"" << Received << '\"' << endl;
		}
	}

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arr1[] = {1,2,3};
			long long Arg2 = 2LL;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getdist(Arg0, Arg1), getdist2(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 100;
			int Arr1[] = {1};
			long long Arg2 = 0LL;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getdist(Arg0, Arg1), getdist2(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arr1[] = {1,1,2};
			long long Arg2 = 10LL;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getdist(Arg0, Arg1), getdist2(Arg0, Arg1));
		}
		n++;

/*
		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1000000000;
			int Arr1[] = {100};
			long long Arg2 = 100000000000LL;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getdist(Arg0, Arg1), getdist2(Arg0, Arg1));
		}
		n++;
*/

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 570;
			int Arr1[] = {2013,2,13,314,271,1414,1732};
			long long Arg2 = 4112LL;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getdist(Arg0, Arg1), getdist2(Arg0, Arg1));
		}
		n++;


		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arr1[] = {1,2,3,4,5};
			long long Arg2 = 9LL;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getdist(Arg0, Arg1), getdist2(Arg0, Arg1));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	RobotHerb ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
