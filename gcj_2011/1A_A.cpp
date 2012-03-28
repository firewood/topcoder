/*

Google Code Jam 2011 Round 1A

Problem A. FreeCell Statistics


Problem

I played D (D > 0) games of FreeCell today. Each game of FreeCell ends
in one of two ways -- I either win, or I lose. I've been playing for
many years, and have so far played G games in total (obviously, G >= D).

At the end of the day, I look at the game statistics to see how well I have
played. It turns out that I have won exactly PD percent of the D games today,
and exactly PG percent of G total games I had ever played. Miraculously,
there is no rounding necessary -- both percentages are exact! Unfortunately,
I don't remember the exact number of games that I have played today (D),
or the exact number of games that I have played in total (G). I do know that
I could not have played more than N games today (D <= N).

Are the percentages displayed possible, or is the game statistics calculator broken?


Input

The first line of the input gives the number of test cases, T. T lines follow.
Each line contains 3 integers -- N, PD and PG.


Output

For each test case, output one line containing "Case #x: y", where x is the
case number (starting from 1) and y is either "Possible" or "Broken".


Limits

0 <= PD <= 100;
0 <= PG <= 100.

Small dataset

1 <= T <= 100;
1 <= N <= 10.

Large dataset

1 <= T <= 2000;
1 <= N <= 10^15.


Sample

Input

3
1 100 50
10 10 100
9 80 56

Output

Case #1: Possible
Case #2: Broken
Case #3: Possible

In Case #3, I could have played 5 games today (D = 5) and 25 games in total
(G = 25), and won 4 games today (80% of 5) and 14 games in total (56% of 25).

*/

#include <iostream>

using namespace std;

typedef __int64 LL;

LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }

static bool solve(LL n, LL pd, LL pg) {
	if (pg == 0 || pg == 100) {
		return pd == pg;
	}
	if (pd == 0 || pd == 100) {
		return true;
	}
	LL g = gcd(100, pd);
	LL a = 100 / g;
	return a <= n;
}

int main()
{
	int T;
	cin >> T;
	int i;
	for (i = 0; i < T; ++i) {
		// n: max games
		// pd: won
		// pg: played
		LL n, pd, pg;
		cin >> n >> pd >> pg;
		cout << "Case #" << (i+1) << ": " << (solve(n, pd, pg) ? "Possible" : "Broken") << endl;
	}

	return 0;
}

