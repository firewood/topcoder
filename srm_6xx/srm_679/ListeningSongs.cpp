// BEGIN CUT HERE
/*
SRM 679 Div2 Easy (250)

PROBLEM STATEMENT
You have two favorite music bands.
Each of them has just recorded a new album.
You have bought both albums.

You know the durations (in seconds) of songs on each of the album.
You are given these duration in vector <int>s durations1 and durations2.
Elements of durations1 are the durations of songs on one of the album, elements of durations2 correspond to the songs of the other album.

You only have a limited amount of time before you have to leave for work.
This amount of time is given in the int minutes.
(Note that the durations are given in seconds while this time is given in minutes.)
Given this time, you want to listen to as many different songs as possible.
However, there is a constraint: as you are a fan of both bands, you have to listen to at least T different songs from each album.

Each song only counts if you listened to it from its beginning to its end.
You can play the songs in any order you like.
Selecting the next song to play and switching between albums takes zero time.

If the input data is such that it is impossible to listen to T different songs from each album in the time you have, return -1.
Otherwise, return the largest number of different songs you can listen to.


DEFINITION
Class:ListeningSongs
Method:listen
Parameters:vector <int>, vector <int>, int, int
Returns:int
Method signature:int listen(vector <int> durations1, vector <int> durations2, int minutes, int T)


CONSTRAINTS
-durations1 will contain between 1 and 100 elements inclusive.
-durations2 will contain between 1 and 100 elements inclusive.
-Each element of durations1 will be between 60 and 3,600 inclusive.
-Each element of durations2 will be between 60 and 3,600 inclusive.
-minutes will be between 1 and 12,000 inclusive.
-T will be between 1 and 100 inclusive.


EXAMPLES

0)
{300,200,100}
{400,500,600}
17
1

Returns: 4

You have 17 minutes = 17*60 seconds = 1020 seconds before you have to leave for work.
In this time you can listen to at most 4 songs.
The only optimal solution is to listen to the entire first album and to the first song of the second album.
This takes 300 + 200 + 100 + 400 = 1000 seconds, which does not exceed 1020.


1)
{300,200,100}
{400,500,600}
10
1

Returns: 2

In this case you could have listened to all the songs from the first album, but you need to listen to at least one song form the second album

So you have three choices:

You can listen to the second song of the first album and the first song of the second album.
You can listen to the third song of the first album and the first song of the second album.
You can listen to the third song of the first album and the second song of the second album.

In all these cases, you can never listen to more than 2 songs.


2)
{60,60,60}
{60,60,60}
5
2

Returns: 5

Any five of these songs take exactly 5 minutes, which is precisely equal to the time you have left.


3)
{120,120,120,120,120}
{60,60,60,60,60,60}
10
3

Returns: 7


4)
{196,147,201,106,239,332,165,130,205,221,248,108,60}
{280,164,206,95,81,383,96,255,260,244,60,313,101}
60
3

Returns: 22

These are the song durations for discs 1 and 2 of The Wall, by Pink Floyd (with durations changed to 60 for songs under 60 seconds).

You want to listen to at least 3 songs from each disc in one hour.


5)
{100,200,300}
{100,200,300}
2
1

Returns: -1

You don't have enough time to listen to a song from the first album and a song from the second album.


6)
{100,200,300,400,500,600}
{100,200}
1000
3

Returns: -1

There is not a sufficient number of different songs on the second album: you want to listen to at least three of them but the album contains only two songs.

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

class ListeningSongs {
public:
	int listen(vector <int> durations1, vector <int> durations2, int minutes, int T) {
		if (durations1.size() < T || durations2.size() < T) {
			return -1;
		}
		sort(durations1.begin(), durations1.end());
		sort(durations2.begin(), durations2.end());
		int sec = minutes * 60;
		int tot = 0;
		for (int i = 0; i < T; ++i) {
			tot += durations1[0];
			tot += durations2[0];
			durations1.erase(durations1.begin());
			durations2.erase(durations2.begin());
		}
		if (tot > sec) {
			return -1;
		}
		for (int d : durations2) {
			durations1.push_back(d);
		}
		sort(durations1.begin(), durations1.end());
		int ans = T * 2;
		for (int d : durations1) {
			tot += d;
			if (tot > sec) {
				break;
			}
			++ans;
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
			int Arr0[] = {300,200,100};
			int Arr1[] = {400,500,600};
			int Arg2 = 17;
			int Arg3 = 1;
			int Arg4 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg4, listen(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {300,200,100};
			int Arr1[] = {400,500,600};
			int Arg2 = 10;
			int Arg3 = 1;
			int Arg4 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg4, listen(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {60,60,60};
			int Arr1[] = {60,60,60};
			int Arg2 = 5;
			int Arg3 = 2;
			int Arg4 = 5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg4, listen(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {120,120,120,120,120};
			int Arr1[] = {60,60,60,60,60,60};
			int Arg2 = 10;
			int Arg3 = 3;
			int Arg4 = 7;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg4, listen(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {196,147,201,106,239,332,165,130,205,221,248,108,60};
			int Arr1[] = {280,164,206,95,81,383,96,255,260,244,60,313,101};
			int Arg2 = 60;
			int Arg3 = 3;
			int Arg4 = 22;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg4, listen(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {100,200,300};
			int Arr1[] = {100,200,300};
			int Arg2 = 2;
			int Arg3 = 1;
			int Arg4 = -1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg4, listen(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {100,200,300,400,500,600};
			int Arr1[] = {100,200};
			int Arg2 = 1000;
			int Arg3 = 3;
			int Arg4 = -1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg4, listen(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ListeningSongs ___test;
	___test.run_test(-1);
}
// END CUT HERE
