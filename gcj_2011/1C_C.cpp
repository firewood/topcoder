/*

Google Code Jam 2011 Round 1C

Problem C. Perfect Harmony


Problem

Jeff is a part of the great Atlantean orchestra. Each player of the orchestra
has already decided what sound will he play (for the sake of simplicity we
assume each player plays only one sound). We say two sounds are in harmony
if the frequency of any one of them divides the frequency of the other
(that's a pretty restrictive idea of harmony, but the Atlanteans are known
to be very conservative in music). Jeff knows that the notes played by other
players are not necessarily in harmony with each other. He wants his own note
to improve the symphony, so he wants to choose his note so that it is in
harmony with the notes all the other players play.

Now, this sounds simple (as all the frequencies are positive integers, it
would be enough for Jeff to play the note with frequency 1, or, from the other
side, the Least Common Multiple of all the other notes), but unfortunately
Jeff's instrument has only a limited range of notes available. Help Jeff
find out if playing a note harmonious with all others is possible.


Input

The first line of the input gives the number of test cases, T. T test cases
follow. Each test case is described by two lines. The first contains three
numbers: N, L and H, denoting the number of other players, the lowest and
the highest note Jeff's instrument can play. The second line contains N
integers denoting the frequencies of notes played by the other players.


Output

For each test case, output one line containing "Case #x: y", where x is the
case number (starting from 1) and y is either the string "NO" (if Jeff cannot
play an appropriate note), or a possible frequency. If there are multiple
frequencies Jeff could play, output the lowest one.


Limits

1 <= T <= 40.

Small dataset

1 <= N <= 100.
1 <= L <= H <= 10000.
All the frequencies are no larger than 10000.

Large dataset

1 <= N <= 104.
1 <= L <= H <= 10^16
All the frequencies are no larger than 10^16


Sample

Input

2
3 2 100
3 5 7
4 8 16
1 20 5 2


Output

Case #1: NO
Case #2: 10

*/

#include <algorithm>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>

using namespace std;

typedef long long LL;
typedef set<LL> LLSet;
typedef vector<int> IntVec;

LL solve(int N, LL L, LL H, IntVec &v) {
	LLSet m;
	int i;
	for (i = 0; i < N; ++i) {
		m.insert(v[i]);
	}
	LL x;
	for (x = L; x <= H; ++x) {
		LLSet::const_iterator it;
		for (it = m.begin(); it != m.end(); ++it) {
			if (*it == x) {
				break;
			}
			if ((*it % x) != 0 && (x % *it) != 0) {
				break;
			}
		}
		if (it == m.end()) {
			return x;
		}
	}
	return -1;
}

int main()
{
	string s;
	getline(cin, s);
	int T = atoi(s.c_str());
	int i, j, N;
	LL L, H;
	for (i = 0; i < T; ++i) {
		{
			getline(cin, s);
			stringstream ss(s);
			ss >> N >> L >> H;
		}
		IntVec v(N);
		{
			getline(cin, s);
			stringstream ss(s);
			for (j = 0; j < N; ++j) {
				ss >> v[j];
			}
		}
		LL result = solve(N, L, H, v);
		if (result >= 0) {
			cout << "Case #" << (i+1) << ": " << result << endl;
		} else {
			cout << "Case #" << (i+1) << ": NO" << endl;
		}
	}
	return 0;
}

