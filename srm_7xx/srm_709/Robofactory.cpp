// BEGIN CUT HERE
/*
SRM 709 Div2 Easy (250)

PROBLEM STATEMENT
Hero owns a factory.
There are n robots working at the factory.
The robots are numbered 0 through n-1.

Today, exactly one of the robots became corrupted.
Hero has decided to give all robots a test that may determine the number of the corrupted robot.
The test works as follows:
For each x from 0 to n-1, in order, Hero tells robot x a positive integer and the robot answers whether the integer is odd or even.
Each normal robot will always give the correct answer.
The corrupted robot may sometimes give the opposite answer.
More precisely: the corrupted robot will answer incorrectly if and only if the previous robot was given an odd number.
In particular, if robot 0 is the corrupted robot, it will give the correct answer (as there is no previous robot).

You are given a log of the test: a vector <int> query and a vector <string> answer, each with n elements.
For each x, query[x] is the positive integer given to robot x, and answer[x] is the answer given by the robot: either "Odd" or "Even".

It is guaranteed that the situation described by query and answer could have occurred as described above.
If it is possible to determine the index of the corrupted robot, return it.
Otherwise, return -1.


DEFINITION
Class:Robofactory
Method:reveal
Parameters:vector <int>, vector <string>
Returns:int
Method signature:int reveal(vector <int> query, vector <string> answer)


CONSTRAINTS
-n will be between 1 and 50, inclusive.
-query and answer will contain exactly n elements.
-Each element in query will be between 1 and 1000, inclusive.
-Each element in answer will be either "Odd" or "Even".
-It is guaranteed that there will be at least one possible number of the corrupted robot.


EXAMPLES

0)
{3,2,2}
{"Odd", "Odd", "Even"}

Returns: 1

Robot 1 gave the wrong answer.
Thus, robot 1 is the corrupted robot.


1)
{1,3,5,10}
{"Odd", "Odd", "Odd", "Even"}

Returns: 0

All robots gave correct answers.
Still, we can deduce that the corrupted robot must be robot 0.
For example, robot 1 cannot be the corrupted robot: as robot 0's number was odd, robot 1 would have answered incorrectly if it were corrupted.


2)
{2,3,5,10}
{"Even", "Odd", "Odd", "Even"}

Returns: -1

Again, all robots gave correct answers.
This time we cannot be sure which robot is corrupted.
All we know is that it is either robot 0 or robot 1.
Both possibilities are consistent with the given input data.
Thus, we should return -1.


3)
{2,4,6,10}
{"Even", "Even", "Even", "Even"}

Returns: -1


4)
{107}
{"Odd"}

Returns: 0


5)
{1,1,1}
{"Odd", "Odd", "Even"}

Returns: 2

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class Robofactory {
public:
	int reveal(vector <int> query, vector <string> answer) {
		int ans = 0;
		for (int i = 1; i < (int)query.size(); ++i) {
			if (query[i - 1] & 1) {
				if (!(query[i] & 1) != (answer[i] == "Even")) {
					return i;
				}
			} else {
				ans = -1;
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
			int Arr0[] = {3,2,2};
			string Arr1[] = {"Odd", "Odd", "Even"};
			int Arg2 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, reveal(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,3,5,10};
			string Arr1[] = {"Odd", "Odd", "Odd", "Even"};
			int Arg2 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, reveal(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,3,5,10};
			string Arr1[] = {"Even", "Odd", "Odd", "Even"};
			int Arg2 = -1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, reveal(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,4,6,10};
			string Arr1[] = {"Even", "Even", "Even", "Even"};
			int Arg2 = -1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, reveal(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {107};
			string Arr1[] = {"Odd"};
			int Arg2 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, reveal(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1,1};
			string Arr1[] = {"Odd", "Odd", "Even"};
			int Arg2 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, reveal(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Robofactory ___test;
	___test.run_test(0);
//	___test.run_test(1);
//	___test.run_test(2);
//	___test.run_test(3);
//	___test.run_test(4);
//	___test.run_test(5);
	___test.run_test(-1);
}
// END CUT HERE
