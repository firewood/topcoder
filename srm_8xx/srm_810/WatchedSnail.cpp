// BEGIN CUT HERE
/*
SRM 810 Div1 Easy (250)

PROBLEM STATEMENT

A snail was racing along a straight trail for raceTime seconds.
The snail maintained the same direction during the entire race.
On the other hand, its speed during the race was not necessarily constant.

The race had observerCount observers.
Each of them watched the snail during a single contiguous closed interval that measured exactly observationTime seconds.

(No observation started before the start of the race. No observation ended after the end of the race. Some observers could have started and therefore also ended their observation at a non-integer timestamp.)

It is guaranteed that during the entire race the snail was always observed by at least one person.
Each observer came to the same conclusion: the distance traveled by the snail during their observation was exactly observationDistance inches.

Return the maximum distance in inches the snail could have traveled during the entire race.


DEFINITION
Class:WatchedSnail
Method:maxDistance
Parameters:int, int, int, int
Returns:double
Method signature:double maxDistance(int raceTime, int observerCount, int observationTime, int observationDistance)


NOTES
-Your return value will be accepted if it has an absolute or a relative error at most 10^(-9).
-The snail cannot teleport (move at infinite speed). Its position in time is a continuous non-decreasing function. 
-As implied by the "non-decreasing" in the previous sentence, the snail may stand still during some intervals of time.


CONSTRAINTS
-raceTime will be between 1 and 1000, inclusive.
-observerCount will be between 1 and 1000, inclusive.
-observationTime will be between 1 and raceTime, inclusive.
-observationDistance will be between 1 and 1000, inclusive.
-observerCount * observationTime will be greater than or equal to raceTime.


EXAMPLES

0)
100
3
100
47

Returns: 47.0

Each person observed the snail during the entire race and saw the snail traverse 47 inches.


1)
100
10
10
47

Returns: 470.0

Ten people took turns watching the snail. Each person saw the snail traverse 47 inches, so the snail traversed 470 inches total. Boring.


2)
100
8
20
47

Returns: 376.0

This should be obvious, right?

Each observation took 20 seconds. The distance traveled during each observation is 47 inches, so for each observation the snail had an average speed of 2.35 inches per second.

The whole race was 100 seconds and at that average speed the snail must have travelled 2.35 * 100 = 235 inches.

The snail was always watched, so it could not have... wait, what?


3)
100
2
74
47

Returns: 94.0

One observer started at the beginning of the race and one ended at the end of the race. 
If [0,100] is the time interval of the race, the first observer was active during [0,74] and the second one during [26,100].

It is possible that the snail traversed only 47 inches total, but it is also possible that it traversed more.
The largest possible total distance it could have travelled is obviously 94 inches.

The answer would clearly remain 94 inches even if we had more than two observers (while keeping the other three parameters the same).

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

class WatchedSnail {
public:
	double maxDistance(int raceTime, int observerCount, int observationTime, int observationDistance) {
		return min(observerCount, max(1, (raceTime - 1) / observationTime * 2)) * observationDistance;
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
			int Arg0 = 100;
			int Arg1 = 3;
			int Arg2 = 100;
			int Arg3 = 47;
			double Arg4 = 47.0;

			verify_case(n, Arg4, maxDistance(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 100;
			int Arg1 = 10;
			int Arg2 = 10;
			int Arg3 = 47;
			double Arg4 = 470.0;

			verify_case(n, Arg4, maxDistance(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 100;
			int Arg1 = 8;
			int Arg2 = 20;
			int Arg3 = 47;
			double Arg4 = 376.0;

			verify_case(n, Arg4, maxDistance(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 100;
			int Arg1 = 2;
			int Arg2 = 74;
			int Arg3 = 47;
			double Arg4 = 94.0;

			verify_case(n, Arg4, maxDistance(Arg0, Arg1, Arg2, Arg3));
		}
		n++;




		if ((Case == -1) || (Case == n)) {
			int Arg0 = 100;
			int Arg1 = 2;
			int Arg2 = 100;
			int Arg3 = 100;
			double Arg4 = 100.0;

			verify_case(n, Arg4, maxDistance(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 100;
			int Arg1 = 2;
			int Arg2 = 99;
			int Arg3 = 100;
			double Arg4 = 200.0;

			verify_case(n, Arg4, maxDistance(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 100;
			int Arg1 = 3;
			int Arg2 = 99;
			int Arg3 = 100;
			double Arg4 = 200.0;

			verify_case(n, Arg4, maxDistance(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 100;
			int Arg1 = 4;
			int Arg2 = 25;
			int Arg3 = 100;
			double Arg4 = 400.0;

			verify_case(n, Arg4, maxDistance(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 100;
			int Arg1 = 5;
			int Arg2 = 49;
			int Arg3 = 100;
			double Arg4 = 400.0;

			verify_case(n, Arg4, maxDistance(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 100;
			int Arg1 = 5;
			int Arg2 = 50;
			int Arg3 = 100;
			double Arg4 = 200.0;

			verify_case(n, Arg4, maxDistance(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 200;
			int Arg1 = 10;
			int Arg2 = 50;
			int Arg3 = 100;
			double Arg4 = 600.0;

			verify_case(n, Arg4, maxDistance(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 201;
			int Arg1 = 10;
			int Arg2 = 50;
			int Arg3 = 100;
			double Arg4 = 800.0;

			verify_case(n, Arg4, maxDistance(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 200;
			int Arg1 = 10;
			int Arg2 = 49;
			int Arg3 = 100;
			double Arg4 = 800.0;

			verify_case(n, Arg4, maxDistance(Arg0, Arg1, Arg2, Arg3));
		}
		n++;



	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	WatchedSnail ___test;
	___test.run_test(-1);
}
// END CUT HERE
