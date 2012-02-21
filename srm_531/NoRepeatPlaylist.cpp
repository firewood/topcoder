// BEGIN CUT HERE
/*
// SRM 531 Div2 Medium (600)
// PROBLEM STATEMENT
// Michael loves listening to music from his cell phone while travelling
by train. He currently has N songs in his cell phone. During one trip
he has the time to listen to P songs. So his cell phone creates a playlist
of P (not necessarily different) songs according to the following rules:

Each song has to be played at least once.
At least M songs have to be played between any two occurrences of the same song.
(This ensures that the playlist is not playing the same song too often.)

Michael wonders how many different playlists his cell phone can create.
You are given the ints N, M, and P. Let X be the number of valid playlists.
Since X can be too large, your method must compute and return the value
(X modulo 1,000,000,007).

DEFINITION
Class:NoRepeatPlaylist
Method:numPlaylists
Parameters:int, int, int
Returns:int
Method signature:int numPlaylists(int N, int M, int P)


NOTES
-Two playlists A and B are different if for some i between 1 and P, inclusive,
 the i-th song in A is different from the i-th song in B.


CONSTRAINTS
-N will be between 1 and 100, inclusive.
-M will be between 0 and N, inclusive.
-P will be between N and 100, inclusive.


EXAMPLES

0)
1
0
3

Returns: 1

You have only 1 song which can be played as often as you want. 
So the only valid playlist is: {song1, song1, song1}.

1)
1
1
3

Returns: 0

Now is the same scenario as in Example 0, but the song cannot be played 2 times in a row. 
Thus there is no valid playlist.

2)
2
0
3

Returns: 6

Now you have 2 songs and you can play them as often as you want. 
Just remember that playlists {song1, song1, song1} and {song2, song2, song2} are not valid,
because each song must be played at least once.

3)
4
0
4

Returns: 24

You have time to play each song exactly once. So there are 4! possible playlists.

4)
2
1
4

Returns: 2

The only two possibilities are {song1, song2, song1, song2} and {song2, song1, song2, song1}.

5)
50
5
100

Returns: 222288991

*/
// END CUT HERE
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
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
typedef vector<string> StrVec;

#define MOD 1000000007LL

class NoRepeatPlaylist {

	int numPlaylists(int N, int M, int P) {
		LL dp[120][120] = {0};
		dp[0][0] = 1;
		int i, j;
		for (i = 1; i <= P; ++i) {
			for (j = 1; j <= N; ++j) {
				dp[i][j] = (dp[i-1][j-1]*(N-j+1) + dp[i-1][j]*max(0, j-M)) % MOD;
			}
		}
		return (int)dp[P][N];
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
			int Arg0 = 1;
			int Arg1 = 0;
			int Arg2 = 3;
			int Arg3 = 1;

			verify_case(n, Arg3, numPlaylists(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 1;
			int Arg2 = 3;
			int Arg3 = 0;

			verify_case(n, Arg3, numPlaylists(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 0;
			int Arg2 = 3;
			int Arg3 = 6;

			verify_case(n, Arg3, numPlaylists(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 0;
			int Arg2 = 4;
			int Arg3 = 24;

			verify_case(n, Arg3, numPlaylists(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 1;
			int Arg2 = 4;
			int Arg3 = 2;

			verify_case(n, Arg3, numPlaylists(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 50;
			int Arg1 = 5;
			int Arg2 = 100;
			int Arg3 = 222288991;

			verify_case(n, Arg3, numPlaylists(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	NoRepeatPlaylist ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
