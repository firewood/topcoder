// BEGIN CUT HERE
/*
SRM 588 Div2 Medium (500)

PROBLEM STATEMENT
Gumi loves singing.
She knows N songs.
The songs are numbered 0 through N-1.
She now has some time and she would love to sing as many different songs as possible. 

You are given a vector <int> duration.
For each i, duration[i] is the duration of song i in Gumi's time units. 

Gumi finds it difficult to sing songs with quite different tones consecutively.
You are given a vector <int> tone with the following meaning:
If Gumi wants to sing song y immediately after song x, she will need to spend |tone[x]-tone[y]| units of time resting between the two songs.
(Here, || denotes absolute value.) 

You are also given an int T.
Gumi has T units of time for singing.
She can start singing any song she knows immediately at the beginning of this time interval.
Compute the maximal number of different songs she can sing completely within the given time.


DEFINITION
Class:GUMIAndSongsDiv2
Method:maxSongs
Parameters:vector <int>, vector <int>, int
Returns:int
Method signature:int maxSongs(vector <int> duration, vector <int> tone, int T)


CONSTRAINTS
-duration and tone will each contain between 1 and 15 elements, inclusive.
-duration and tone will contain the same number of elements.
-Each element of duration will be between 1 and 100,000, inclusive.
-Each element of tone will be between 1 and 100,000, inclusive.
-T will be between 1 and 10,000,000, inclusive.


EXAMPLES

0)
{3, 5, 4, 11}
{2, 1, 3, 1}
17

Returns: 3

There are four songs. 
Two songs have tone 1 and their durations are 5 and 11, respectively.
One song has tone 2 and its duration is 3.
One song has tone 3 and its duration is 4.
Gumi has 17 units of time to sing. 

It is impossible for Gumi to sing all four songs she knows within the given time: even without the breaks the total length of all songs exceeds 17. 

Here is one way how she can sing three songs:
First, she sings song 0 in 3 units of time.
Second, she waits for |2-3|=1 unit of time and then sings song 2 in 4 units of time.
Finally, she waits for |3-1|=2 units of time and then sings song 1 in 5 units of time.
The total time spent is 3+1+4+2+5 = 15 units of time.


1)
{100, 200, 300}
{1, 2, 3}
10

Returns: 0

In this case, T is so small that she can't sing at all.


2)
{1, 2, 3, 4}
{1, 1, 1, 1}
100

Returns: 4

There is plenty of time, so she can sing all 4 songs.


3)
{10, 10, 10}
{58, 58, 58}
30

Returns: 3


4)
{8, 11, 7, 15, 9, 16, 7, 9}
{3, 8, 5, 4, 2, 7, 4, 1}
14

Returns: 1


5)
{5611,39996,20200,56574,81643,90131,33486,99568,48112,97168,5600,49145,73590,3979,94614}
{2916,53353,64924,86481,44803,61254,99393,5993,40781,2174,67458,74263,69710,40044,80853}
302606

Returns: 8

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;

typedef pair<int, int> II;
typedef vector<II> IIVec;

class GUMIAndSongsDiv2 {
public:
	int maxSongs(vector <int> duration, vector <int> tone, int T) {
		int ans = 0;

		IIVec v;
		for (int i = 0; i < (int)tone.size(); ++i) {
			v.push_back(II(tone[i], duration[i]));
		}
		sort(v.begin(), v.end());

		int dp[64][64];
		memset(dp, 0x3f, sizeof(dp));
		for (int i = 0; i < (int)v.size(); ++i) {
			for (int j = 0; j < i; ++j) {
				for (int k = 1; k <= i; ++k) {
					dp[i][k + 1] = min(dp[i][k + 1], dp[j][k] + abs(v[i].first - v[j].first) + v[i].second);
					if (dp[i][k + 1] <= T) {
						ans = max(ans, k + 1);
					}
				}
			}
			dp[i][1] = v[i].second;
			if (v[i].second <= T) {
				ans = max(ans, 1);
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
			int Arr0[] = {3, 5, 4, 11};
			int Arr1[] = {2, 1, 3, 1};
			int Arg2 = 17;
			int Arg3 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, maxSongs(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {100, 200, 300};
			int Arr1[] = {1, 2, 3};
			int Arg2 = 10;
			int Arg3 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, maxSongs(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 2, 3, 4};
			int Arr1[] = {1, 1, 1, 1};
			int Arg2 = 100;
			int Arg3 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, maxSongs(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10, 10, 10};
			int Arr1[] = {58, 58, 58};
			int Arg2 = 30;
			int Arg3 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, maxSongs(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {8, 11, 7, 15, 9, 16, 7, 9};
			int Arr1[] = {3, 8, 5, 4, 2, 7, 4, 1};
			int Arg2 = 14;
			int Arg3 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, maxSongs(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5611,39996,20200,56574,81643,90131,33486,99568,48112,97168,5600,49145,73590,3979,94614};
			int Arr1[] = {2916,53353,64924,86481,44803,61254,99393,5993,40781,2174,67458,74263,69710,40044,80853};
			int Arg2 = 302606;
			int Arg3 = 8;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, maxSongs(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	GUMIAndSongsDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
