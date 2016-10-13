// BEGIN CUT HERE
/*
SRM 700 Div2 Easy (250)

PROBLEM STATEMENT

A xylophone is a musical instrument that consists of a sequence of wooden bars.
In order to make a sound, you have to strike one of the bars by a mallet.

For the purpose of this problem we will assume that our xylophone has exactly 50 bars.
The bars are numbered from 1 to 50 in the order from the left to the right.

There are 7 notes: A, B, C, D, E, F, G.
Each bar of our xylophone plays one of these notes.
The notes repeat periodically.
When you play the bars from the left to the right, you will hear the following sequence of notes:
A,B,C,D,E,F,G,A,B,C,D,E,F,G,A,B,C,...

In other words: bar 1 produces the note A, bar 2 plays B, bar 3 plays C, ..., bar 7 plays G,
and then the sequence of notes starts repeating: bar 8 plays the note A again, bar 9 is B, and so on.

You have hit a sequence of bars.
You are given their numbers in the vector <int> keys.
Return the number of distinct notes you've hit.


DEFINITION
Class:Xylophone
Method:countKeys
Parameters:vector <int>
Returns:int
Method signature:int countKeys(vector <int> keys)


CONSTRAINTS
-keys will contain between 1 and 50 elements, inclusive.
-Each element of keys will be between 1 and 50, inclusive.


EXAMPLES

0)
{1,8,3}

Returns: 2

If you hit the keys 1,8,3, you have played the notes A,A,C.
This means you have hit two distinct notes: A and C.


1)
{7,3,2,4,1,5,6}

Returns: 7

In this case you have played 7 distinct notes, each of them exactly once.


2)
{1,8,15}

Returns: 1

Although these are all distinct keys, these keys all have the same note, so they are counted as one.


3)
{25,1,17,9,8}

Returns: 4


4)
{11,11,11,11,11,11,11,11,11,11,11}

Returns: 1


5)
{50,10,20,30,11,30,24,38,5,2,9}

Returns: 6

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class Xylophone {
public:
	int countKeys(vector <int> keys) {
		set<int> s;
		for (int k : keys) {
			s.insert(k % 7);
		}
		return (int)s.size();
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
			int Arr0[] = {1,8,3};
			int Arg1 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, countKeys(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {7,3,2,4,1,5,6};
			int Arg1 = 7;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, countKeys(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,8,15};
			int Arg1 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, countKeys(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {25,1,17,9,8};
			int Arg1 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, countKeys(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {11,11,11,11,11,11,11,11,11,11,11};
			int Arg1 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, countKeys(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {50,10,20,30,11,30,24,38,5,2,9};
			int Arg1 = 6;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, countKeys(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Xylophone ___test;
	___test.run_test(-1);
}
// END CUT HERE
