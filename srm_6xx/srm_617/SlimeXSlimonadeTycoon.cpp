// BEGIN CUT HERE
/*
SRM 617 Div2 Medium (500)

PROBLEM STATEMENT
You are playing a game called Slime Tycoon.
You will be selling Slimonades in this game, and your goal is to sell as many as you can.

The game will consist of N game days, numbered 0 through N-1 in order.
You are given two vector <int>s morning and customers with N elements each, and an int stale_limit.
These represent constraints on how many Slimonades you can produce and sell, as explained below.

In each game day, three things happen, in the following order:

Early in the morning of day i: All Slimonades that were produced stale_limit days ago (i.e., on day i-stale_limit) go stale. You cannot sell stale Slimonades, you must throw them away immediately.
During day i: You can produce at most morning[i] new Slimonades. (Formally, you choose an integer X between 0 and morning[i], inclusive, and produce X Slimonades.)
In the evening of day i: You can sell at most customers[i] Slimonades. (That is, if you have at most customers[i] Slimonades, you sell all of them. Otherwise, you sell exactly customers[i] Slimonades. In that case, you get to choose which Slimonades you sell and which ones you keep for later days.)

What is the maximum total number of Slimonades that you can sell during these N days?


DEFINITION
Class:SlimeXSlimonadeTycoon
Method:sell
Parameters:vector <int>, vector <int>, int
Returns:int
Method signature:int sell(vector <int> morning, vector <int> customers, int stale_limit)


CONSTRAINTS
-morning will contain between 2 and 50 elements, inclusive.
-Each element of morning will be between 0 and 10000, inclusive.
-customers will contain the same number of elements as morning.
-Each element of customers will be between 0 and 10000, inclusive.
-stale_limit will be between 1 and N, inclusive.


EXAMPLES

0)
{5, 1, 1}
{1, 2, 3}
2

Returns: 5

Here's one optimal solution.

Day 0: We produce 4 Slimonades, then sell 1 of them.
Day 1: We produce 1 Slimonade (so now we have 4). In the evening, we sell two of the Slimonades that were made yesterday.
Day 2: We still have one Slimonade that was made on day 0. It goes stale and we throw it away. We produce one more Slimonade. In the evening, we sell 2 Slimonades (the one made yesterday and the one made today).


1)
{10, 20, 30}
{30, 20, 10}
1

Returns: 40

As stale_limit=1, each evening we can only sell Slimonades made during that day. Hence, we can sell at most 10 Slimonades on day 0, 20 on day 1, and 10 on day 2.


2)
{1, 2, 3, 4, 5}
{5, 5, 5, 5, 5}
5

Returns: 15


3)
{10000, 0, 0, 0, 0, 0, 0}
{1, 2, 4, 8, 16, 32, 64}
4

Returns: 15

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class SlimeXSlimonadeTycoon {
public:
	int sell(vector <int> morning, vector <int> customers, int stale_limit) {
		int ans = 0;
		int N = (int)morning.size();
		for (int i = 0; i < N; ++i) {
			if (i >= stale_limit) {
				morning[i - stale_limit] = 0;
			}
			for (int j = 0; j <= i; ++j) {
				int x = min(customers[i], morning[j]);
				ans += x;
				morning[j] -= x;
				customers[i] -= x;
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
			int Arr0[] = {5, 1, 1};
			int Arr1[] = {1, 2, 3};
			int Arg2 = 2;
			int Arg3 = 5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, sell(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10, 20, 30};
			int Arr1[] = {30, 20, 10};
			int Arg2 = 1;
			int Arg3 = 40;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, sell(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 2, 3, 4, 5};
			int Arr1[] = {5, 5, 5, 5, 5};
			int Arg2 = 5;
			int Arg3 = 15;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, sell(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10000, 0, 0, 0, 0, 0, 0};
			int Arr1[] = {1, 2, 4, 8, 16, 32, 64};
			int Arg2 = 4;
			int Arg3 = 15;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, sell(Arg0, Arg1, Arg2));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arr0[] = { 6698, 5233, 7329, 6261, 7772, 783, 9346, 4110, 5752, 628, 2011, 9620, 9873 };
			int Arr1[] = { 7551, 2566, 8205, 211, 5336, 1247, 5179, 1726, 7114, 8888, 5603, 2993, 9004 };
			int Arg2 = 10;
			int Arg3 = 64770;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, sell(Arg0, Arg1, Arg2));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SlimeXSlimonadeTycoon ___test;
	___test.run_test(-1);
}
// END CUT HERE
