/*

Google Code Jam 2011 Round 1B

Problem A. RPI


Problem

In the United States, 350 schools compete every year for an invitation to the
NCAA College Basketball Tournament. With so many schools, how do you decide
who should be invited? Most teams never play each other, and some teams have a
much more difficult schedule than others.

Here is an example schedule for 4 teams named A, B, C, D:

   |ABCD
  -+----
  A|.11.
  B|0.00
  C|01.1
  D|.10.
Each 1 in a team's row represents a win, and each 0 represents a loss. So
team C has wins against B and D, and a loss against A. Team A has wins
against B and C, but has not played D.
The NCAA tournament committee uses a formula called the RPI (Ratings Percentage
Index) to help rank teams. Traditionally, it has been defined as follows:

  RPI = 0.25 * WP + 0.50 * OWP + 0.25 * OOWP

WP, OWP, and OOWP are defined for each team as follows:

- WP (Winning Percentage) is the fraction of your games that you have won.
  In the example schedule, team A has WP = 1, team B has WP = 0, team C has
  WP = 2/3, and team D has WP = 0.5.
- OWP (Opponents' Winning Percentage) is the average WP of all your opponents,
  after first throwing out the games they played against you.
  For example, if you throw out games played against team D, then team B has
  WP = 0 and team C has WP = 0.5. Therefore team D has
  OWP = 0.5 * (0 + 0.5) = 0.25. Similarly, team A has OWP = 0.5, team B has
  OWP = 0.5, and team C has OWP = 2/3.
- OOWP (Opponents' Opponents' Winning Percentage) is the average OWP of all
  your opponents. OWP is exactly the number computed in the previous step.
  For example, team A has OOWP = 0.5 * (0.5 + 2/3) = 7/12.

Putting it all together, we see team A has
RPI = (0.25 * 1) + (0.5 * 0.5) + (0.25 * 7 / 12) = 0.6458333...
There are some pretty interesting questions you can ask about the RPI.
Is it a reasonable measure of team's ability? Is it more important for teams
to win games, or to schedule strong opponents? These are all good questions,
but for this problem, your task is more straightforward: given a schedule of
games, can you calculate every team's RPI?


Input

The first line of the input gives the number of test cases, T. T test cases follow.
Each test case begins with a single line containing the number of teams N.

The next N lines each contain exactly N characters (either '0', '1', or '.')
representing a schedule in the same format as the example schedule above.
A '1' in row i, column j indicates team i beat team j, a '0' in row i,
column j indicates team i lost to team j, and a '.' in row i, column j
indicates team i never played against team j.


Output

For each test case, output N + 1 lines. The first line should be "Case #x:"
where x is the case number (starting from 1). The next N lines should contain
the RPI of each team, one per line, in the same order as the schedule.

Answers with a relative or absolute error of at most 10-6 will be considered correct.


Limits

1 <= T <= 20.
If the schedule contains a '1' in row i, column j, then it contains a '0' in row j, column i.
If the schedule contains a '0' in row i, column j, then it contains a '1' in row j, column i.
If the schedule contains a '.' in row i, column j, then it contains a '.' in row j, column i.
Every team plays at least two other teams.
No two teams play each other twice.
No team plays itself.
Small dataset

3 <= N <= 10.


Large dataset

3 <= N <= 100.


Sample


Input

2
3
.10
0.1
10.
4
.11.
0.00
01.1
.10.


Output 

Case #1:
0.5
0.5
0.5
Case #2:
0.645833333333
0.368055555556
0.604166666667
0.395833333333

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<string> StrVec;

static void solve(StrVec v) {
	int N = v.size();
	int i, j;
	int result[128][2] = {};
	int total[128] = {};
	double WP[128] = {};
	double OWP[128] = {};
	double OOWP[128] = {};
	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) {
			if (v[i][j] != '.') {
				int win = v[i][j] - '0';
				result[i][win] += 1;
			}
		}
		total[i] = result[i][0] + result[i][1];
		if (total[i] > 0) {
			WP[i] = (double)result[i][1] / (double)total[i];
		}
	}
	for (i = 0; i < N; ++i) {
		int c = 0;
		double owp = 0;
		for (j = 0; j < N; ++j) {
			if (v[j][i] != '.' && total[j] > 1) {
				++c;
				int win = v[j][i] - '0';
				owp += (double)(result[j][1] - win) / (double)(result[j][0] + result[j][1] - 1);
			}
		}
		OWP[i] = owp / (double)c;
	}
	for (i = 0; i < N; ++i) {
		int c = 0;
		double oowp = 0;
		for (j = 0; j < N; ++j) {
			if (v[j][i] != '.') {
				++c;
				oowp += OWP[j];
			}
		}
		OOWP[i] = oowp / (double)c;
	}
	for (i = 0; i < N; ++i) {
		double rpi = (WP[i] + 2.0 * OWP[i] + OOWP[i]) / 4.0;
		cout << rpi << endl;
	}
}

int main()
{
	cout.precision(16);
	int T, N;
	cin >> T;
	int t, i;
	for (t = 0; t < T; ++t) {
		cin >> N;
		StrVec v;
		for (i = 0; i < N; ++i) {
			string s;
			cin >> s;
			v.push_back(s);
		}
		cout << "Case #" << (t+1) << ":" << endl;
		solve(v);
	}

	return 0;
}

