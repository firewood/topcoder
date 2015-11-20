// BEGIN CUT HERE
/*
SRM 673 Div2 Easy (250)

PROBLEM STATEMENT
Bear Limak has recently learned about musical notes.
He then listened to a song and noticed that some notes appeared less often than others.
In fact, some notes were so rare that they appeared in the song only once!

Limak now wants to look for such notes in other songs.
Write a program that will look for the rare notes.

You are given a vector <int> notes that describes a song.
Each number in notes represents one note of the song.
Different numbers represent different notes, equal numbers represent equal notes.

Compute and return the number of notes that occur exactly once in the given song.


DEFINITION
Class:BearSong
Method:countRareNotes
Parameters:vector <int>
Returns:int
Method signature:int countRareNotes(vector <int> notes)


CONSTRAINTS
-notes will contain between 1 and 50 elements, inclusive.
-Each element in notes will be between 1 and 1000, inclusive.


EXAMPLES

0)
{9,10,7,8,9}

Returns: 3

The rare notes are the notes 7, 8, and 10.
Each of these notes occurs exactly once in the whole song.
The note 9 occurs twice, so it is not a rare note


1)
{8,8,7,6,7,3,5,10,9,3}

Returns: 4

Each of the notes 5, 6, 9, and 10 occurs exactly once in this song.


2)
{234,462,715,596,906}

Returns: 5


3)
{17}

Returns: 1


4)
{1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000}

Returns: 0

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

class BearSong {
public:
	int countRareNotes(vector <int> notes) {
		int cnt[1024] = {};
		for (int n : notes) {
			cnt[n] += 1;
		}
		int ans = 0;
		for (int n : notes) {
			ans += cnt[n] == 1;
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
			int Arr0[] = {9,10,7,8,9};
			int Arg1 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, countRareNotes(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {8,8,7,6,7,3,5,10,9,3};
			int Arg1 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, countRareNotes(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {234,462,715,596,906};
			int Arg1 = 5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, countRareNotes(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {17};
			int Arg1 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, countRareNotes(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000};
			int Arg1 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, countRareNotes(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BearSong ___test;
	___test.run_test(-1);
}
// END CUT HERE
