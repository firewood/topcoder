// BEGIN CUT HERE
/*
SRM 580 Div1 Easy (250)

PROBLEM STATEMENT
Rabbit went to a river to catch eels.
All eels are currently swimming down the stream at the same speed.
Rabbit is standing by the river, downstream from all the eels.


Each point on the river has a coordinate.
The coordinates increase as we go down the stream.
Initially, Rabbit is standing at the origin, and all eels have non-positive coordinates.


You are given two vector <int>s: l and t.
These describe the current configuration of eels.
The speed of each eel is 1 (one).
For each i, the length of eel number i is l[i].
The head of eel number i will arrive at the coordinate 0 precisely at the time t[i].
Therefore, at any time T the eel number i has its head at the coordinate T-t[i], and its tail at the coordinate T-t[i]-l[i].


Rabbit may only catch an eel when some part of the eel (between head and tail, inclusive) is at the same coordinate as the rabbit.
Rabbit can catch eels at most twice.
Each time he decides to catch eels, he may catch as many of the currently available eels as he wants.
(That is, he can only catch eels that are in front of him at that instant, and he is allowed and able to catch multiple eels at once.)


Return the maximal total number of eels Rabbit can catch.

DEFINITION
Class:EelAndRabbit
Method:getmax
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int getmax(vector <int> l, vector <int> t)


CONSTRAINTS
-l will contain between 1 and 50 elements, inclusive.
-Each element of l will be between 1 and 1,000,000,000, inclusive.
-l and t will contain the same number of elements.
-Each element of t will be between 0 and 1,000,000,000, inclusive.


EXAMPLES

0)
{2, 4, 3, 2, 2, 1, 10}
{2, 6, 3, 7, 0, 2, 0}

Returns: 6

Rabbit can catch 6 eels in the following way:

At time 2, catch Eel 0, Eel 4, Eel 5, and Eel 6.
At time 8, catch Eel 1 and Eel 3.


1)
{1, 1, 1}
{2, 0, 4}

Returns: 2

No two eels are in front of Rabbit at the same time, so Rabbit can catch at most two eels.


2)
{1}
{1}

Returns: 1


3)
{8, 2, 1, 10, 8, 6, 3, 1, 2, 5}
{17, 27, 26, 11, 1, 27, 23, 12, 11, 13}

Returns: 7

*/
// END CUT HERE
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class EelAndRabbit {
public:
	int getmax(vector <int> l, vector <int> t) {
		int ans = 0;
		int i, j, k;
		for (i = 0; i < (int)t.size(); ++i) {
			for (j = 0; j < (int)t.size(); ++j) {
				int f[50] = {};
				for (k = 0; k < (int)t.size(); ++k) {
					f[k] |= t[i] >= t[k] && t[i] <= (t[k] + l[k]);
					f[k] |= t[j] >= t[k] && t[j] <= (t[k] + l[k]);
				}
				ans = max(ans, accumulate(f, f + t.size(), 0));
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
			int Arr0[] = {2, 4, 3, 2, 2, 1, 10};
			int Arr1[] = {2, 6, 3, 7, 0, 2, 0};
			int Arg2 = 6;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getmax(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 1, 1};
			int Arr1[] = {2, 0, 4};
			int Arg2 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getmax(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1};
			int Arr1[] = {1};
			int Arg2 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getmax(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {8, 2, 1, 10, 8, 6, 3, 1, 2, 5};
			int Arr1[] = {17, 27, 26, 11, 1, 27, 23, 12, 11, 13};
			int Arg2 = 7;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getmax(Arg0, Arg1));
		}
		n++;




		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,2,2,2};
			int Arr1[] = {0,2,4,6};
			int Arg2 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getmax(Arg0, Arg1));
		}
		n++;





	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EelAndRabbit ___test;
//	___test.run_test(0);
//	___test.run_test(1);
//	___test.run_test(2);
//	___test.run_test(3);
//	___test.run_test(4);
//	___test.run_test(5);
	___test.run_test(-1);
}
// END CUT HERE
