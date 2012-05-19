/*

Google Code Jam 2011 Round 2

Problem A. Airport Walkways


Problem

You're in an airport, standing at point 0. A corridor of length X leads to
the gate, where your plane is about to leave. There are moving walkways
in the corridor, each moving with some speed wi. When you walk or run on
one of those, you move with speed (your speed + wi). The walkways do not
change their position; they just make you move faster. The walkways do not
overlap: at any given point of the corridor there is at most one walkway,
but one walkway can begin at the point where another ends.

Your normal walking speed is S. You are worried that you might not catch
your plane, though, so you can run a bit - you can run with speed R for
at most t seconds in total. You do not have to run for t consecutive seconds:
you can split these t seconds into any number of intervals, or even not
use some part of them.

How long does it take you to get to the gate, assuming you choose when to
walk and when to run in order to reach it as soon as possible?


Input

The first line of the input gives the number of test cases, T. T test cases
follow. Each test case begins with a line containing five integers: X (the
length of the corridor, in meters), S (your walking speed, in meters per second),
R (your running speed, in meters per second), t (the maximum time you can run,
in seconds) and N (the number of walkways).

Each of the next N lines contains three integers: Bi, Ei and wi - the beginning
and end of the walkway (in meters from your starting point) and the speed
of the walkway (in meters per second).


Output

For each test case, output one line containing "Case #x: y", where x is the
case number (starting from 1) and y is the time (in seconds) you need to
reach point X if you walk and run optimally. Answers with relative or
absolute error of at most 10-6 will be accepted.


Limits

1 <= T <= 40.
1 <= S < R <= 100.
1 <= wi <= 100.
0 <= Bi < Ei <= X.
Ei <= Bi+1.


Small dataset

1 <= t <= 100.
1 <= X <= 100.
1 <= N <= 20.


Large dataset

1 <= t <= 106.
1 <= X <= 106.
1 <= N <= 1000.


Sample

3
10 1 4 1 2
4 6 1
6 9 2
12 1 2 4 1
6 12 1
20 1 3 20 5
0 4 5
4 8 4
8 12 3
12 16 2
16 20 1

Case #1: 4.000000
Case #2: 5.500000
Case #3: 3.538095238

*/

#include <map>
#include <vector>
#include <iostream>

using namespace std;

typedef vector<int> IntVec;
typedef map<int, int> IntMap;

double solve(int X, int S, int R, int t, int N, IntVec &B, IntVec &E, IntVec &w) {
	IntMap m;
	int prev = 0;
	int i, len;
	for (i = 0; i < N; ++i) {
		len = B[i] - prev;
		m[S] += len;
		len = E[i] - B[i];
		m[S+w[i]] += len;
		prev = E[i];
	}
	len = X - prev;
	m[S] += len;

	double total = 0;
	double canboost = t;
	IntMap::const_iterator it;
	for (it = m.begin(); it != m.end(); ++it) {
		double speed = it->first;
		double dash = speed;
		if (canboost > 0) {
			dash += (R-S);
		}
		double meter = it->second;
		double past = meter / dash;
		if (canboost > 0) {
			if (past > canboost) {
				meter -= dash * canboost;
				past = canboost + meter / speed;
				canboost = 0;
			} else {
				canboost -= past;
			}
		}
		total += past;
	}

	return total;
}

int main()
{
	cout.precision(16);
	int T, X, S, R, t, N, i, j;
	cin >> T;
	for (i = 0; i < T; ++i) {
		cin >> X >> S >> R >> t >> N;
		IntVec w(N), B(N), E(N);
		for (j = 0; j < N; ++j) {
			cin >> B[j] >> E[j] >> w[j];
		}
		double result = solve(X, S, R, t, N, B, E, w);
		cout << "Case #" << (i+1) << ": " << result << endl;
	}

	return 0;
}

