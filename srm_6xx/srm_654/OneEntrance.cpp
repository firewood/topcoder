// BEGIN CUT HERE
/*
SRM 654 Div2 Medium (500)

PROBLEM STATEMENT

There are N rooms in Maki's new house.
The rooms are numbered from 0 to N-1.
Some pairs of rooms are connected by bidirectional passages.
The passages have the topology of a tree.
That is, there are exactly N-1 of them and it is possible to go from any room to any other room by following some sequence of passages.

You are given two vector <int>s a and b that describe the passages.
For each valid i, there is a passage that connects the rooms a[i] and b[i].
You are also given an int s.
The house has exactly one entrance from the outside, and the entrance leads to the room s.

Niko is helping Maki move into the new house.
Maki has exactly N pieces of furniture.
The pieces are numbered from 0 to N-1.
Niko will carry them into the house in this order.
Each piece of furniture must be placed into a different room.
Maki does not care which piece goes where, each of the N! permutations is allowed.

However, not all of those N! permutations are actually possible.
This is because the furniture is large.
As soon as a room contains a piece of furniture, it is impossible to move other pieces through this room.
Thus, Niko must place the furniture carefully.
Formally, she can place a new piece of furniture into the room x if and only if all rooms on the (unique) path between s and x, including s and x, are still empty.
Niko is smart and she will always place the furniture in such a way that she never gets stuck.
Thus, at the end each of Maki's rooms will contain exactly one piece of furniture.

Calculate and return the number of ways how the furniture can be arranged in Maki's house at the end.


DEFINITION
Class:OneEntrance
Method:count
Parameters:vector <int>, vector <int>, int
Returns:int
Method signature:int count(vector <int> a, vector <int> b, int s)


CONSTRAINTS
-N will be between 1 and 9, inclusive.
-a and b will contain exactly N-1 elements each.
-Each element of a and b will be between 0 and N-1, inclusive.
-The graph described by a and b will be a tree.
-s will be between 0 and N-1, inclusive.


EXAMPLES

0)
{0, 1, 2}
{1, 2, 3}
0

Returns: 1

There is only one solution: Niko must fill the rooms in the order {3,2,1,0}.
Thus, piece number 0 will end in room 3, piece number 1 in room 2, and so on.


1)
{0, 1, 2}
{1, 2, 3}
2

Returns: 3

In this case Niko can choose one of three orders: {3,0,1,2}, {0,3,1,2}, or {0,1,3,2}.
Note that the room with the entrance (in this case, room 2) always gets the last piece of furniture.


2)
{0, 0, 0, 0}
{1, 2, 3, 4}
0

Returns: 24


3)
{7, 4, 1, 0, 1, 1, 6, 0}
{6, 6, 2, 5, 0, 3, 8, 4}
4

Returns: 896


4)
{}
{}
0

Returns: 1

Maki's new house has only one room.

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

class OneEntrance {
	int N;
	int be_empty[10];
	int connected[10][10];

public:
	void dfs(int n, int f) {
		be_empty[n] = f;
		for (int i = 0; i < N; ++i) {
			if (connected[n][i]) {
				connected[n][i] = 0;
				connected[i][n] = 0;
				dfs(i, f | (1 << n));
			}
		}
	}

	int count(vector <int> a, vector <int> b, int s) {
		memset(be_empty, 0, sizeof(be_empty));
		memset(connected, 0, sizeof(connected));
		N = (int)a.size() + 1;
		for (int i = 0; i < N - 1; ++i) {
			connected[a[i]][b[i]] = connected[b[i]][a[i]] = 1;
		}
		dfs(s, 0);
		int ans = 0;
		int p[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
		do {
			bool possible = true;
			for (int i = 0; possible && i < N; ++i) {
				for (int j = 0; possible && j < N; ++j) {
					if (be_empty[i] & (1 << j)) {
						if (p[j] < p[i]) {
							possible = false;
						}
					}
				}
			}
			ans += possible;
		} while (next_permutation(p, p + N));
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
			int Arr0[] = {0, 1, 2};
			int Arr1[] = {1, 2, 3};
			int Arg2 = 0;
			int Arg3 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, count(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 1, 2};
			int Arr1[] = {1, 2, 3};
			int Arg2 = 2;
			int Arg3 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, count(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 0, 0, 0};
			int Arr1[] = {1, 2, 3, 4};
			int Arg2 = 0;
			int Arg3 = 24;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, count(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {7, 4, 1, 0, 1, 1, 6, 0};
			int Arr1[] = {6, 6, 2, 5, 0, 3, 8, 4};
			int Arg2 = 4;
			int Arg3 = 896;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, count(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			// int Arr0[] = {};
			// int Arr1[] = {};
			int Arg2 = 0;
			int Arg3 = 1;

			vector <int> Arg0;
			vector <int> Arg1;
			verify_case(n, Arg3, count(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	OneEntrance ___test;
	___test.run_test(-1);
}
// END CUT HERE
