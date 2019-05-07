// BEGIN CUT HERE
/*
SRM 755 Div2 Easy (300)

PROBLEM STATEMENT
Misof recently had an accident in which he managed to cut his left hand on some broken glass. He is now "all right" - meaning that he can only use his right hand for a while. Help him with some issues he has.
Misof needs to do some tasks. Each of the tasks has to be done during a specific time interval, and it requires constant use of his only hand. Find out whether he can do all the tasks.
You are given the vector <int>s tStart and tEnd, each with N elements. For each i between 0 and N-1, inclusive, tStart[i] is the timestamp of the beginning and tEnd[i] the timestamp of the end of task i.
(All timestamps are in seconds, with timestamp 0 being the midnight today.)
For each task, Misof needs his hand for the entire interval of time, including both endpoints. That is, if one task ends exactly at the same time at which another task begins, Misof cannot do both of them.
Return "possible" (quotes for clarity) if Misof can do all the tasks and "impossible" if he cannot do that.


DEFINITION
Class:OneHandScheduling
Method:checkSchedule
Parameters:vector <int>, vector <int>
Returns:string
Method signature:string checkSchedule(vector <int> tStart, vector <int> tEnd)


NOTES
-You are not given the value N explicitly. Instead, you can determine it by looking at the number of elements in tStart (or tEnd).
-Note that the return value is case-sensitive.


CONSTRAINTS
-N will be between 1 and 10, inclusive.
-tStart and tEnd will each contain exactly N elements.
-Each element of tStart and tEnd will be between 0 and 1,000,000, inclusive.
-For each i, tStart[i] will be less than tEnd[i].


EXAMPLES

0)
{10, 100, 236}
{47, 235, 347}

Returns: "possible"

Task 0 starts at timestamp 10 and ends at timestamp 47.
Task 1 starts at timestamp 100 and ends at timestamp 235.
Task 2 starts at timestamp 236 and ends at timestamp 347.

Misof can do all of them.


1)
{100, 236, 10}
{235, 347, 47}

Returns: "possible"

The same three tasks as in Example #0, just given in another order. The answer remains the same.


2)
{10, 20}
{20, 30}

Returns: "impossible"

These two tasks overlap, so Misof cannot do both of them.


3)
{10, 400000, 500000}
{20, 600000, 700000}

Returns: "impossible"


4)
{1, 40, 50, 60}
{1000000, 41, 51, 61}

Returns: "impossible"

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

typedef pair<int, int> II;

class OneHandScheduling {
	bool possible(vector <int> tStart, vector <int> tEnd) {
		int n = (int)tStart.size();
		vector<II> v;
		for (int i = 0; i < n; ++i) {
			v.push_back(II(tStart[i], tEnd[i]));
		}
		sort(v.begin(), v.end());
		int prev = -1;
		for (int i = 0; i < n; ++i) {
			if (v[i].first <= prev) {
				return false;
			}
			prev = v[i].second;
		}
		return true;
	}

public:
	string checkSchedule(vector <int> tStart, vector <int> tEnd) {
		return possible(tStart, tEnd) ? "possible" : "impossible";
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10, 100, 236};
			int Arr1[] = {47, 235, 347};
			string Arg2 = "possible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, checkSchedule(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {100, 236, 10};
			int Arr1[] = {235, 347, 47};
			string Arg2 = "possible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, checkSchedule(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10, 20};
			int Arr1[] = {20, 30};
			string Arg2 = "impossible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, checkSchedule(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10, 400000, 500000};
			int Arr1[] = {20, 600000, 700000};
			string Arg2 = "impossible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, checkSchedule(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 40, 50, 60};
			int Arr1[] = {1000000, 41, 51, 61};
			string Arg2 = "impossible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, checkSchedule(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	OneHandScheduling ___test;
	___test.run_test(-1);
}
// END CUT HERE
