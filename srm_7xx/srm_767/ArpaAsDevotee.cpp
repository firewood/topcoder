// BEGIN CUT HERE
/*
SRM 767 Div1 Easy (250)

PROBLEM STATEMENT

Time in this problem is discrete.
All timestamps are integers between 0 and 86,400, inclusive.

Arpa is a devotee of Mojtaba.
Mojtaba is often online on Bale (an instant messenger).
The public profile of a person on this messenger contains the information about the last timestamp when the person was seen online.
Arpa often comes online and checks this information about Mojtaba.

When you come at some time t1 and you check when a person was last online, you are shown a timestamp t2 that satisfies t2 <= t1.
In particular, if that person is currently online, you are shown the timestamp t2 = t1.
(You can only check a person that has already been online, so the value you are shown is always defined.)

Yesterday, Arpa checked on Mojtaba n times.
Arpa claims that the vector <int>s a and lastSeen describe what he saw.
More precisely, Arpa claims that for each i, he checked the messenger at the time a[i] and he obtained the information that Mojtaba was last seen at the time lastSeen[i].

As the first part of your solution, check whether the information provided in a and lastSeen is valid.
If there is any contradiction in the provided data, return an empty vector <string>.

Additionally, you are given q queries in the vector <int> t.
For each timestamp t[j], try to deduce whether Mojtaba was online at that moment.
Return a vector <string> with q elements.
For each query, in the order they were given, the return value should contain the string "Yes" if we are sure that Mojtaba was online at the time t[j], the string "No" if we are sure that he was not online, or the string "Not Sure" otherwise.


DEFINITION
Class:ArpaAsDevotee
Method:solve
Parameters:int, int, vector <int>, vector <int>, vector <int>
Returns:vector <string>
Method signature:vector <string> solve(int n, int q, vector <int> a, vector <int> lastSeen, vector <int> t)


CONSTRAINTS
-n will be between 1 and 50, inclusive.
-q will be between 1 and 50, inclusive.
-a and lastSeen will have n elements each.
-t will have q elements.
-Each element of a, lastSeen, and t will be between 0 and 86,400, inclusive.


EXAMPLES

0)
5
7
{11, 13, 17, 25, 29}
{11, 13, 15, 15, 29}
{11, 12, 13, 14, 15, 16, 17}

Returns: {"Yes", "Not Sure", "Yes", "Not Sure", "Yes", "No", "No" }

Arpa checked on Mojtaba five times. The timestamps of those checks are 11, 13, 17, 25, and 29.

There are seven queries.

We can be sure that Mojtaba was online at time t[0] = 11, t[2] = 13, and also t[4] = 15, as we have explicitly seen the information about these times.
We have no idea about t[1] = 12 or t[3] = 14. For each of these timestamps both scenarios ("Mojtaba was online" and "Mojtaba was not online") are consistent with our data.
When Arpa logged in at the time 25, he saw that Mojtaba's most recent appearance online was at time 15. From this we can deduce the answers to the last two queries.


1)
2
1
{1, 10}
{5, 3}
{6}

Returns: { }

This is an example of invalid data provided in a and lastSeen. The contradiction here is that the value lastSeen[0] is greater than a[0], which cannot happen.


2)
3
1
{7, 7, 1}
{3, 5, 1}
{4}

Returns: { }

The values in a do not have to be distinct.
But, of course, checking at the same timestamp twice must yield the same answer.
As that is not satisfied here, these arrays a and lastSeen contain a contradiction and the correct return value is {}.

Also note that the values in a are not necessarily sorted.


3)
2
3
{5, 5}
{2, 2}
{1, 2, 3}

Returns: {"Not Sure", "Yes", "No" }

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

class ArpaAsDevotee {

public:
	vector <string> solve(int n, int q, vector <int> a, vector <int> lastSeen, vector <int> t) {
		vector<int> x(86401, -1);
		for (int i = 0; i < (int)a.size(); ++i) {
			if (lastSeen[i] > a[i]) {
				return {};
			}
			if (x[lastSeen[i]] == 0) {
				return {};
			}
			x[lastSeen[i]] = 1;
			if (lastSeen[i] < a[i]) {
				for (int j = lastSeen[i] + 1; j <= a[i]; ++j) {
					if (x[j] == 1) {
						return {};
					}
					x[j] = 0;
				}
			}
		}
		vector <string> ans(t.size());
		for (int i = 0; i < (int)t.size(); ++i) {
			const string aa[3] = { "Not Sure", "No", "Yes" };
			ans[i] = aa[1 + x[t[i]]];
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 7;
			int Arr2[] = {11, 13, 17, 25, 29};
			int Arr3[] = {11, 13, 15, 15, 29};
			int Arr4[] = {11, 12, 13, 14, 15, 16, 17};
			string Arr5[] = {"Yes", "Not Sure", "Yes", "Not Sure", "Yes", "No", "No" };

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			vector <string> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0])));
			verify_case(n, Arg5, solve(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 1;
			int Arr2[] = {1, 10};
			int Arr3[] = {5, 3};
			int Arr4[] = {6};

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			vector <string> Arg5;
			verify_case(n, Arg5, solve(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 1;
			int Arr2[] = {7, 7, 1};
			int Arr3[] = {3, 5, 1};
			int Arr4[] = {4};

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			vector <string> Arg5;
			verify_case(n, Arg5, solve(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 3;
			int Arr2[] = {5, 5};
			int Arr3[] = {2, 2};
			int Arr4[] = {1, 2, 3};
			string Arr5[] = {"Not Sure", "Yes", "No" };

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			vector <string> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0])));
			verify_case(n, Arg5, solve(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 2;
			int Arg1 = 3;
			int Arr2[] = { 4, 5 };
			int Arr3[] = { 2, 3 };
			int Arr4[] = { 1, 2, 3 };

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			vector <string> Arg5;
			verify_case(n, Arg5, solve(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 2;
			int Arg1 = 3;
			int Arr2[] = { 5, 4 };
			int Arr3[] = { 3, 2 };
			int Arr4[] = { 1, 2, 3 };

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			vector <string> Arg5;
			verify_case(n, Arg5, solve(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ArpaAsDevotee ___test;
	___test.run_test(-1);
}
// END CUT HERE
