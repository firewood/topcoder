// BEGIN CUT HERE
/*
SRM 631 Div2 Medium (500)

PROBLEM STATEMENT

There are some cats sitting on a straight line that goes from the left to the right.
You are given two vector <int>s position and count.
For each valid i, there are count[i] cats initially sitting at the point position[i].

During each minute, each cat chooses and performs one of three possible actions: it may stay in its place, move one unit to the left (i.e., from x to x-1), or move one unit to the right (i.e., from x to x+1).
(Note that there are no restrictions. In particular, different cats that are currently at the same point may make different choices.)

You are also given an int time.
The goal is to rearrange the cats in such a way that each point contains at most one cat.
Return "Possible" if it's possible to achive the goal in time minutes, and "Impossible" otherwise (quotes for clarity).


DEFINITION
Class:CatsOnTheLineDiv2
Method:getAnswer
Parameters:vector <int>, vector <int>, int
Returns:string
Method signature:string getAnswer(vector <int> position, vector <int> count, int time)


CONSTRAINTS
-position will contain between 1 and 50 elements, inclusive.
-position and count will contain the same number of elements.
-Each element of position will be between -1000 and 1000, inclusive.
-All elements of position will be distinct.
-Each element of count will be between 1 and 1000, inclusive.
-time will be between 0 and 1000, inclusive.


EXAMPLES

0)
{0}
{7}
3

Returns: "Possible"

There are 7 cats sitting at the origin in this case. There are also 7 different points that cats can reach in 3 minutes, so each cat can occupy a unique point. Thus, the answer is "Possible".

1)
{0}
{8}
2

Returns: "Impossible"

Unlike the first test case, in this case there are 8 cats for 7 available points. Thus, the answer is "Impossible".


2)
{0, 1}
{3, 1}
0

Returns: "Impossible"


3)
{5, 0, 2}
{2, 3, 5}
2

Returns: "Impossible"


4)
{5, 1, -10, 7, 12, 2, 10, 20}
{3, 4, 2, 7, 1, 4, 3, 4}
6

Returns: "Possible"

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;
typedef pair<LL, LL> II;
typedef vector<II> IIVec;

class CatsOnTheLineDiv2 {
public:
	string getAnswer(vector <int> position, vector <int> count, int time) {
		int N = (int)position.size();
		IIVec v;
		for (int i = 0; i < N; ++i) {
			v.push_back(II(position[i], count[i]));
		}
		sort(v.begin(), v.end());

		LL prev = -1LL << 60;
		for (int i = 0; i < N; ++i) {
			LL left = max(prev + 1, v[i].first - time);
			LL right = left + v[i].second - 1;
			if (right > v[i].first + time) {
				return "Impossible";
			}
			prev = right;
		}
		return "Possible";
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
			int Arr0[] = {0};
			int Arr1[] = {7};
			int Arg2 = 3;
			string Arg3 = "Possible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, getAnswer(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0};
			int Arr1[] = {8};
			int Arg2 = 2;
			string Arg3 = "Impossible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, getAnswer(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 1};
			int Arr1[] = {3, 1};
			int Arg2 = 0;
			string Arg3 = "Impossible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, getAnswer(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5, 0, 2};
			int Arr1[] = {2, 3, 5};
			int Arg2 = 2;
			string Arg3 = "Impossible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, getAnswer(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5, 1, -10, 7, 12, 2, 10, 20};
			int Arr1[] = {3, 4, 2, 7, 1, 4, 3, 4};
			int Arg2 = 6;
			string Arg3 = "Possible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, getAnswer(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	CatsOnTheLineDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
