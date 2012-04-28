/*

Google Code Jam 2012 Round 1A

Problem B. Kingdom Rush


Problem

Ryan is playing Kingdom Rush, a single-player tower defense game developed by
Ironhide Game Studio. In Kingdom Rush, players earn stars by completing levels,
in a way described below. Having more stars makes the player more powerful;
so while Ryan might not be able to complete level 2 right away, he might be
able to complete it after earning stars from level 1.

The real game Kingdom Rush doesn't work in quite the same way as this problem.
It isn't important to have played the game in order to solve the problem.

In this problem's version of Kingdom Rush, when a player completes a level,
he or she is given a 1-star rating or a 2-star rating. That rating might allow
the player to earn stars as follows:

- If the player has never completed the level before and completes it with a
  1-star rating, that player earns 1 star.
- If the player has never completed the level before and completes it with a
  2-star rating, that player earns 2 stars.
- If the player has only completed the level before with a 1-star rating and
  completes it this time with a 2-star rating, the player earns 1 more star.

Otherwise there is no way for a player to earn stars.

Ryan might not be able to complete every level right away. For each level,
before he can complete it with a 1-star rating, he needs to have earned a
certain number of stars; and he will need a larger or equal number of stars
to complete that level with a 2-star rating.

For example, suppose there are two levels:
Level 1 requires 0 stars to complete with a 1-star rating, and 1 star to
complete with a 2-star rating.
Level 2 requires 0 stars to complete with a 1-star rating, and 2 stars to
complete with a 2-star rating.
Here's a possible series of events for Ryan:
Ryan starts with 0 stars. He can choose to complete either level 1 or level 2
with a 1-star rating. He chooses to complete level 1 with a 1-star rating.
Now he has 1 star.
Now Ryan can either complete level 2 with a 1-star rating, or level 1 with a
2-star rating. He chooses to complete level 1 with a 2-star rating.
Now he has 2 stars.
Now Ryan can complete level 2 with a 2-star rating. He does that, and now
he has 4 stars.
Now he is done, having completed all levels with 2-star ratings and earned
4 stars (2 per level). He has completed levels 3 times: level 1 twice, and
level 2 once.
Ryan is great at tower defense games, but he needs some help to beat Kingdom
Rush as quickly as possible. Your job is to figure out how many times he
needs to complete levels in order to earn a 2-star rating on every level.


Input

The first line of the input gives the number of test cases, T. T test cases
follow. Each test case starts with a line containing a single integer N,
indicating how many levels are in the game. N lines follow. The ith line
contains two integers ai and bi: the number of stars it takes to earn a
one-star rating or a two-star rating, respectively, on level i.


Output

For each test case, output one line containing "Case #x: y", where x is the
case number (starting from 1) and y is the minimum number of times Ryan must
complete levels in order to have earned a 2-star rating on every level. If
it is impossible for Ryan to earn a 2-star rating on every level, y should
instead be the string "Too Bad" (without the " characters, but with that
exact capitalization). This indicates that Ryan is too bad at Kingdom Rush
to finish the whole game.


Limits

1 <= T <= 100.
0 <= ai <= bi <= 2001.


Small dataset

1 <= N <= 10.


Large dataset

1 <= N <= 1000.


Sample


Input

4
2
0 1
0 2
3
2 2
0 0
4 4
1
1 1
5
0 5
0 1
1 1
4 7
5 6


Output

Case #1: 3
Case #2: 3
Case #3: Too Bad
Case #4: 6

*/

#include <algorithm>
#include <numeric>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef pair<int, int> II;
typedef vector<int> IntVec;
typedef vector<II> IIVec;

static int solve(int N, IntVec a, IntVec b) {
	int result = 0;
	IIVec A, B;
	int i, j, k, stars = 0;
	for (i = 0; i < N; ++i) {
		A.push_back(II(a[i], i));
		B.push_back(II(b[i], i));
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	IntVec f(N);
	for (i = 0; i < N; ++i) {
		while (stars < B[i].first) {
			int MaxB = -1;
			for (j = 0; j < N; ++j) {
				if (stars < A[j].first) {
					break;
				}
				if (!f[A[j].second]) {
					if (b[A[j].second] > MaxB) {
						k = A[j].second;
						MaxB = b[k];
					}
				}
			}
			if (MaxB < 0) {
				return -1;
			}
			f[k] = 1;
			++result;
			stars += 1;
		}

		++result;
		stars += 2 - f[B[i].second];
		f[B[i].second] = 2;
	}

	return result;
}


int main(int argc, char *argv[])
{
	cout.precision(16);
	string s;
	getline(cin, s);
	int T = atoi(s.c_str());
	int t;
	for (t = 0; t < T; ++t) {
		IntVec a, b;
		getline(cin, s);
		int N = atoi(s.c_str());
		int i;
		for (i = 0; i < N; ++i) {
			getline(cin, s);
			stringstream ss(s);
			int p, q;
			ss >> p >> q;
			a.push_back(p);
			b.push_back(q);
		}
		int result = solve(N, a, b);
		cout << "Case #" << (t+1) << ": ";
		if (result < 0) {
			cout << "Too Bad" << endl;
		} else {
			cout << result << endl;
		}
	}

	return 0;
}

