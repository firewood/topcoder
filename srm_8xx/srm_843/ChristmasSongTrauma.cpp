// BEGIN CUT HERE
/*
SRM 843 Div1 Easy (250)

PROBLEM STATEMENT

Shopping before Christmas comes with many perils. One of them is the endless barrage of Christmas songs.

A few weeks ago Tommy needed to visit a shopping mall and spend visitTime consecutive seconds inside.

The shopping mall has a single tape with several distinct Christmas songs. They play the tape in an endless loop. The lengths of the songs on the tape (in seconds, in the order in which they are on the tape) are given in the vector <int> playTime.

Depending on when Tommy enters the mall, he may hear a different number of songs. 
Hearing only a part of a song still counts as hearing the song.

We are only interested in distinct songs Tommy hears, so if he hears the same song multiple times, we only count it once.

Assume Tommy will enter the mall at some integer offset from the beginning of the tape, and that all offsets are equally likely.
(The set of possible offsets includes zero = the start of the tape but excludes the end of the tape, as that is already also the beginning of its next loop.)

Tommy is lucky if the number of distinct songs he has to hear is minimal.
(I.e., there is no other entrance time for which he would hear fewer distinct songs.)

Return the probability that Tommy will be lucky.


DEFINITION
Class:ChristmasSongTrauma
Method:fewest
Parameters:vector <int>, int
Returns:double
Method signature:double fewest(vector <int> playTime, int visitTime)


NOTES
-Return values with an absolute difference at most 1e-9 will be accepted as correct.
-If a song stops playing at the same time Tommy enters the mall, or starts playing at the same time he leaves the mall, we do NOT count the song as heard by him.


CONSTRAINTS
-playTime will have between 1 and 1000 elements, inclusive.
-Each element of playTime will be between 1 and 10^6, inclusive.
-visitTime will be between 1 and 10^9, inclusive.


EXAMPLES

0)
{50, 100, 100, 100, 70, 90, 90}
300

Returns: 0.0016666666666666668

The loop of Christmas songs has 600 seconds. Tommy will be in the mall for 300 seconds. If he enters exactly 50 seconds after the start of the tape, he will only hear the three longest songs while at the mall. If he enters at any other time, he will hear at least four distinct songs.


1)
{100, 100, 100, 100, 100, 100, 100, 100}
301

Returns: 1.0

All songs on this tape have the exact same length. Regardless of when Tommy enters he will hear four of the songs.


2)
{312}
15241235

Returns: 1.0

Tommy will be in the mall for a very long time. Regardless of when he enters, he will be treated to an endless loop of Last Christmas and he will slowly lose his remaining shreds of sanity and his will to live.

Regardless of when he enters, he will hear exactly one distinct song. Per our definition in the problem statement this means that for all possible offsets he will be lucky.


3)
{50, 100, 100, 100, 70, 90, 90}
310

Returns: 0.41

The extra 10 seconds (in comparison to Example 0) now mean that Tommy will hear at least four distinct songs. His chance of hearing exactly four is somewhat less than 50 percent.

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

typedef long long LL;
typedef long double LD;

class ChristmasSongTrauma {
public:
	double fewest(vector <int> playTime, int visitTime) {
		LL N = playTime.size(), sum = accumulate(playTime.begin(), playTime.end(), 0LL);
		if (visitTime >= sum) return 1.0;
		map<LL, LL> m;
		map<LL, LL> pm;
		LL t = 0;
		for (int i = 0; i < N * 4; ++i) {
			t += playTime[i % N];
			m[t + visitTime - 1] = -1;
			m[t + visitTime] = -1;
		}
		t = 0;
		for (int i = 0; i < N * 4; ++i) {
			m[t] = i % N;
			t += playTime[i % N];
		}
		m[t] = 0;
		set<LL> s;
		bool f = false;
		LL prev = 0;
		for (auto kv : m) {
			while (!s.empty() && *(s.begin()) <= (kv.first - visitTime)) {
				s.erase(s.begin());
			}
			if (f) {
				LL d = kv.first - prev;
				pm[min(s.size(), playTime.size())] += d;
			}
			if (kv.second >= 0) {
				s.insert(kv.first + playTime[kv.second]);
			}
			if (kv.first == sum) {
				f = true;
			} else if (kv.first == sum * 2) {
				break;
			}
			prev = kv.first;
		}
		return LD(pm.begin()->second) / sum;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {50, 100, 100, 100, 70, 90, 90};
			int Arg1 = 300;
			double Arg2 = 0.0016666666666666668;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, fewest(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {100, 100, 100, 100, 100, 100, 100, 100};
			int Arg1 = 301;
			double Arg2 = 1.0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, fewest(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {312};
			int Arg1 = 15241235;
			double Arg2 = 1.0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, fewest(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {50, 100, 100, 100, 70, 90, 90};
			int Arg1 = 310;
			double Arg2 = 0.41;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, fewest(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 50, 100, 100, 100, 70, 90, 90 };
			int Arg1 = 551;
			double Arg2 = 1.0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, fewest(Arg0, Arg1));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ChristmasSongTrauma ___test;
	___test.run_test(-1);
}
// END CUT HERE
