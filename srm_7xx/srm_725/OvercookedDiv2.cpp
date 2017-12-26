// BEGIN CUT HERE
/*
SRM 725 Div2 Medium (500)

PROBLEM STATEMENT

Alice and Bob are playing a popular game called Overcooked.
In this game, players work together to cook dishes and serve them to customers.
We'll be discussing a simplified version of the game in this problem.

Alice and Bob wish to prepare a single dish.
The recipe consists of n steps.
The steps must be done sequentially in order from 0 to n-1: step i+1 cannot be started before step i has been completed.
(It is allowed to start the next step in the same moment in which they finished working on the previous step.)

Alice and Bob have a stopwatch.
At the beginning of the game they start the stopwatch.
Each step of the recipe can only be started when the time on the stopwatch is an integer.
Additionally, the steps are not necessarily available from the start: the i-th step only becomes available when the stopwatch reaches start[i] seconds.
Step i takes time[i] seconds to complete.

Given a particular schedule that describes when to do which step of the recipe, we can measure the waiting times.
For each step of the recipe, the waiting time before step i is the idle time between finishing step i-1 and starting step i.
(For step 0, the waiting time is the time between starting the stopwatch and starting step 0.)
The boredom level of the schedule is the maximum of all waiting times.

You are given the vector <int>s start and time.
Determine and return the smallest possible boredom level of a schedule that describes how to execute the given recipe.


DEFINITION
Class:OvercookedDiv2
Method:minStale
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int minStale(vector <int> start, vector <int> time)


CONSTRAINTS
-start,time will have the same number of elements.
-start will have between 1 and 50 elements, inclusive.
-Each element of start,time will be between 1 and 10^6, inclusive.
-Elements in start will be in increasing order.


EXAMPLES

0)
{1,5,10}
{3,6,1}

Returns: 1


The smallest possible boredom level is 1 second.
It can be achieved with the following schedule:

0: Wait for 1 second.
1: Step 0 now becomes available. Start doing it.
4: Finish doing step 0. Wait for 1 second.
5: Step 1 now becomes available. Start doing it.
10: Step 2 now becomes available, but we are still doing step 1.
11: Finish doing step 1. Without any waiting start doing step 2.
12: Finish the recipe.


1)
{3,10}
{1,10}

Returns: 5

Here, it is better to wait until time 4 or 5 to start the first step.


2)
{1,10,100,1000,10000,100000}
{50,50,50,50,50,50}

Returns: 16625


3)
{10,30,50,60,70,80,90,100,110,120}
{5,4,3,2,1,5,4,3,2,1}

Returns: 14


4)
{1000}
{1000000}

Returns: 1000

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

class OvercookedDiv2 {
	int get_min(vector <int> &start, vector <int> &time, int w) {
		int t = 0;
		for (int i = 0; i < (int)time.size(); ++i) {
			w = max(w, start[i] - t);
			t += w + time[i];
		}
		return w;
	}

public:
	int minStale(vector <int> start, vector <int> time) {
		int ans = get_min(start, time, 0);
		while (ans > 0) {
			int w = get_min(start, time, ans - 1);
			if (w >= ans) {
				break;
			}
			ans = w;
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
			int Arr0[] = {1,5,10};
			int Arr1[] = {3,6,1};
			int Arg2 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minStale(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3,10};
			int Arr1[] = {1,10};
			int Arg2 = 5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minStale(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,10,100,1000,10000,100000};
			int Arr1[] = {50,50,50,50,50,50};
			int Arg2 = 16625;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minStale(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10,30,50,60,70,80,90,100,110,120};
			int Arr1[] = {5,4,3,2,1,5,4,3,2,1};
			int Arg2 = 14;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minStale(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1000};
			int Arr1[] = {1000000};
			int Arg2 = 1000;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minStale(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	OvercookedDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
