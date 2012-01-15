// BEGIN CUT HERE
/*
// SRM 529 Div2 Easy (250)
// PROBLEM STATEMENT
// 
"Pairing pawns" is a game played on a strip of paper, divided into N cells. The cells are labeled 0 through N-1. Each cell may contain an arbitrary number of pawns.


You are given a vector <int> start with N elements. For each i, element i of start is the initial number of pawns on cell i.


The goal of the game is to bring as many pawns as possible to cell 0.


The only valid move looks as follows:


Find a pair of pawns that share the same cell X (other than cell 0).
Remove the pair of pawns from cell X.
Add a single new pawn into the cell X-1.


You may make as many moves as you wish, in any order.


Return the maximum number of pawns that can be in cell 0 at the end of the game.


DEFINITION
Class:PairingPawns
Method:savedPawnCount
Parameters:vector <int>
Returns:int
Method signature:int savedPawnCount(vector <int> start)


NOTES
-You may assume that the answer will always fit into an int.
-Note that you are only given the vector <int> start. The number of cells N can be determined as the length of start.


CONSTRAINTS
-start will contain between 1 and 20 elements, inclusive.
-Each element of start will be between 0 and 1,000,000, inclusive.


EXAMPLES

0)
{0,2}

Returns: 1

There are two pawns on cell 1. You can remove them both and place a pawn onto cell 0.

1)
{10,3}

Returns: 11

There are 10 pawns already on cell 0. You can add another one by removing two pawns from cell 1. Note that at the end of the game cell 1 will still contain one pawn that cannot be used anymore.

2)
{0,0,0,8}

Returns: 1

After 7 moves you can get a single pawn to cell 0. The rest of the board will be empty.

3)
{0,1,1,2}

Returns: 1

Again, a single pawn can reach the leftmost cell.

4)
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,123456}

Returns: 0

That's a lot of pawns! But they are too far away. In this case it is impossible for a pawn to reach cell 0.

5)
{1000,2000,3000,4000,5000,6000,7000,8000}

Returns: 3921



#line 92 "PairingPawns.cpp"
*/
// END CUT HERE
#include <cmath>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;
typedef vector<int> IntVec;
typedef vector<LL> LLVec;
typedef vector<string> StrVec;
typedef set<int> IntSet;
typedef set<LL> LLSet;
typedef set<string> StrSet;
typedef set<int, int> IntMap;
typedef set<LL, LL> LLMap;
typedef set<string, string> StrMap;

class PairingPawns {

public:
	int savedPawnCount(vector <int> start) {
		int s = start.size();
		int i;
		for (i = s - 1; i > 0; --i) {
			start[i - 1] += start[i] / 2;
		}
		return start[0];
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
			int Arr0[] = {0,2};
			int Arg1 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, savedPawnCount(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10,3};
			int Arg1 = 11;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, savedPawnCount(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,0,0,8};
			int Arg1 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, savedPawnCount(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,1,1,2};
			int Arg1 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, savedPawnCount(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,123456};
			int Arg1 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, savedPawnCount(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1000,2000,3000,4000,5000,6000,7000,8000};
			int Arg1 = 3921;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, savedPawnCount(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PairingPawns ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
