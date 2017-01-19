// BEGIN CUT HERE
/*
SRM 705 Div2 Easy (250)

PROBLEM STATEMENT
Fox Ciel just used the command "sudo" (super-user do) to gain administrative privileges in the UNIX-based operating system on her computer.
She now wants to install several new programs.
Each program has some dependencies: in addition to the program, the package manager has to install some libraries used by the program.

The package repository contains exactly 1000 libraries.
For simplicity, we will number them from 1 to 1000, inclusive.

You are given the information about the dependencies of the programs Fox Ciel wants to install.
More precisely, you are given the vector <int>s A and B, both containing the same number of elements.
For each valid i, one of the programs needs all libraries that have numbers between A[i] and B[i], inclusive.
Note that the programs may have overlapping dependences: multiple programs may require the same library to be installed.
Of course, in such cases it is sufficient to install such a library once.

Calculate and return the total number of libraries that need to be installed.


DEFINITION
Class:SuperUserDo
Method:install
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int install(vector <int> A, vector <int> B)


CONSTRAINTS
-A will contain between 1 and 100 elements inclusive.
-B will contain the same number of elements as A.
-Each element of A will be between 1 and 1000 inclusive.
-The i-th element of B will be between A[i] and 1000 inclusive.


EXAMPLES

0)
{1}
{10}

Returns: 10

Only libraries 1 to 10 must be installed, so the answer is 10.


1)
{1,101}
{10,110}

Returns: 20


2)
{1}
{1000}

Returns: 1000


3)
{1,2,3,4,5}
{6,7,8,9,10}

Returns: 10

In this test case the dependencies have non-empty intersections.
One program needs libraries from 1 to 6, another program needs libraries from 2 to 7, and so on.
In order to satisfy all dependencies, the package manager will install libraries numbered from 1 to 10, inclusive.
Hence, the total number of installed libraries is 10.


4)
{1,1}
{1,1}

Returns: 1

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

class SuperUserDo {
public:
	int install(vector <int> A, vector <int> B) {
		int dep[1001] = {};
		for (int i = 0; i != A.size(); ++i) {
			for (int j = A[i]; j <= B[i]; ++j) {
				dep[j] = 1;
			}
		}
		return accumulate(dep, dep + 1001, 0);
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
			int Arr0[] = {1};
			int Arr1[] = {10};
			int Arg2 = 10;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, install(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,101};
			int Arr1[] = {10,110};
			int Arg2 = 20;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, install(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1};
			int Arr1[] = {1000};
			int Arg2 = 1000;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, install(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2,3,4,5};
			int Arr1[] = {6,7,8,9,10};
			int Arg2 = 10;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, install(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1};
			int Arr1[] = {1,1};
			int Arg2 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, install(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SuperUserDo ___test;
	___test.run_test(-1);
}
// END CUT HERE
