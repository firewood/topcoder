// BEGIN CUT HERE
/*
SRM 615 Div2 Easy (250)

PROBLEM STATEMENT
Monte-Carlo is an amoeba. Amoebas can feed on gel: whenever an amoeba encounters a piece of gel that is exactly as big as the amoeba, the amoeba will consume the gel and thus double its size.

Initially, the size of Monte-Carlo was A. During its lifetime, Monte-Carlo encountered several gels and consumed the ones it could.

You are given a vector <int> X and the int A. The elements of X are the sizes of gels Monte-Carlo encountered, in chronological order. Compute and return the final size of Monte-Carlo.


DEFINITION
Class:AmebaDiv2
Method:simulate
Parameters:vector <int>, int
Returns:int
Method signature:int simulate(vector <int> X, int A)


CONSTRAINTS
-X will contain between 1 and 200 integers, inclusive.
-Each element of X will be between 1 and 1,000,000,000, inclusive.
-A will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
{2,1,3,1,2}
1

Returns: 4

Gel #0 is bigger than Monte-Carlo, nothing happens.
Monte-Carlo consumes gel #1. Its size is now 1+1 = 2.
Gel #2 is bigger than Monte-Carlo, nothing happens.
Gel #3 is smaller than Monte-Carlo, nothing happens.
Monte-Carlo consumes gel #4. Its size is now 2+2 = 4.


1)
{1,4,9,16,25,36,49}
10

Returns: 10

The size of Monte-Carlo doesn't change.


2)
{1,2,4,8,16,32,64,128,256,1024,2048}
1

Returns: 512


3)
{817,832,817,832,126,817,63,63,126,817,832,287,823,817,574}
63

Returns: 252

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class AmebaDiv2 {
public:
	int simulate(vector <int> X, int A) {
		for (int gel : X) {
			if (gel == A) {
				A *= 2;
			}
		}
		return A;
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
			int Arr0[] = {2,1,3,1,2};
			int Arg1 = 1;
			int Arg2 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, simulate(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,4,9,16,25,36,49};
			int Arg1 = 10;
			int Arg2 = 10;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, simulate(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2,4,8,16,32,64,128,256,1024,2048};
			int Arg1 = 1;
			int Arg2 = 512;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, simulate(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {817,832,817,832,126,817,63,63,126,817,832,287,823,817,574};
			int Arg1 = 63;
			int Arg2 = 252;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, simulate(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	AmebaDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
