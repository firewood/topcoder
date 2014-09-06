// BEGIN CUT HERE
/*
SRM 632 Div2 Easy (250)

PROBLEM STATEMENT

Alice went jogging around the park yesterday.
There is a circular track around the park, and Alice's house is right next to the track.
Alice ran in the clockwise direction.
She both started and ended her run at her house.
In other words, she completed some positive number of full laps.

There are N trees along the track.
The trees are numbered 1 through N in the order in which Alice encounters them when running a single lap.
You are given the int N.

Alice remembers some trees she saw during her run.
She remembers them in the order in which she encountered them.
You are given this information as a vector <int> d.

For example, d={6,6,1} has the following meaning:

Alice started running.
After some time she encountered the tree number 6.
After some more time she encountered the tree number 6.
Even later she encountered the tree number 1.

Compute and return the smallest possible number of laps Alice completed.


DEFINITION
Class:RunningAroundPark
Method:numberOfLap
Parameters:int, vector <int>
Returns:int
Method signature:int numberOfLap(int N, vector <int> d)


CONSTRAINTS
-N will be between 2 and 50, inclusive.
-d will contain between 1 and 50 elements.
-Each element of d will be between 1 and N, inclusive.


EXAMPLES

0)
3
{1,2,3}

Returns: 1

It is possible that Alice ran just a single lap and remembered all the trees she saw.


1)
24
{6,6}

Returns: 2

Alice ran past the tree number 6 at least twice, so there must have been at least two laps.


2)
3
{3,2,1}

Returns: 3


3)
50
{1,3,5,7,9,2,4,6,8,10}

Returns: 2

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class RunningAroundPark {
public:
	int numberOfLap(int N, vector <int> d) {
		int ans = 1;
		for (int i = 1; i < (int)d.size(); ++i) {
			ans += d[i] <= d[i-1];
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
			int Arg0 = 3;
			int Arr1[] = {1,2,3};
			int Arg2 = 1;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, numberOfLap(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 24;
			int Arr1[] = {6,6};
			int Arg2 = 2;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, numberOfLap(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arr1[] = {3,2,1};
			int Arg2 = 3;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, numberOfLap(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 50;
			int Arr1[] = {1,3,5,7,9,2,4,6,8,10};
			int Arg2 = 2;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, numberOfLap(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	RunningAroundPark ___test;
	___test.run_test(-1);
}
// END CUT HERE
