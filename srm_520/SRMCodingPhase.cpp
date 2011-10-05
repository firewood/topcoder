// BEGIN CUT HERE
/*
// SRM 520 Div2 Middle (500)
// PROBLEM STATEMENT
// Mr. Dengklek introduced you to an online programming contest called SRM (Special Round Match)!

You are now in the coding phase of the contest. There are 3 problems in the contest.
You have practiced a lot before in practice rooms, so you are sure that
you can solve the first problem in skills[0] minutes, the second problem
in skills[1] minutes and the third problem is skills[2] minutes.

You have exactly 75 minutes to solve the problems.
Before submitting a solution to a problem, you must first open the problem.
If you submit a solution to a problem t minutes after you open the problem, you will receive:

(points[0] - 2t) points for the first problem, or
(points[1] - 4t) points for the second problem, or
(points[2] - 8t) points for the third problem.


In your strategy, you only submit a solution to a problem after you solve the problem.
If you don't submit a solution to a problem, you will receive zero points for the problem.

It is well-known that luck plays an important role in a contest.
A fortune-teller told you that you have luck points of luck.
You may use these points to decrease the amount of time you need to solve the problems,
in minutes. Of course, you don't have to use all the points.
Each point is worth one minute per problem.
So, if you initially can solve a problem in t minutes, by using x points of luck
(where x is a positive integer and 0 < x < t), you can solve the problem in (t - x) minutes
(it is impossible to use t or more points of luck on the problem).

Arrange your strategy in this coding phase.
Return the maximum total score you can achieve in this coding phase.

DEFINITION
Class:SRMCodingPhase
Method:countScore
Parameters:vector <int>, vector <int>, int
Returns:int
Method signature:int countScore(vector <int> points, vector <int> skills, int luck)


CONSTRAINTS
-points will contain exactly 3 elements.
-points[0] will be between 250 and 300, inclusive.
-points[1] will be between 450 and 600, inclusive.
-points[2] will be between 900 and 1100, inclusive.
-skills will contain exactly 3 elements.
-Each element of skills will be between 1 and 100, inclusive.
-luck will be between 0 and 100, inclusive.


EXAMPLES

0)
{250, 500, 1000}
{10, 25, 40}
0

Returns: 1310

You don't have any luck points. However, you can solve all the problems in exactly 75 minutes.

1)
{300, 600, 900}
{30, 65, 90}
25

Returns: 680

Use 25 luck points on the 600-point problem, and then solve the 300- and 600-point problems.

2)
{250, 550, 950}
{10, 25, 40}
75

Returns: 1736

Using the large amount of luck points, solve each problem in only 1 minute.

3)
{256, 512, 1024}
{35, 30, 25}
0

Returns: 1216



4)
{300, 600, 1100}
{80, 90, 100}
4

Returns: 0



#line 88 "SRMCodingPhase.cpp"
*/
// END CUT HERE
#include <math.h>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

typedef long long LL;
typedef vector<int> IntVec;
typedef vector<string> StrVec;

class SRMCodingPhase {

public:
	int countScore(vector <int> points, vector <int> skills, int luck) {
		int result = 0;

		int la, lb, lc;
		for (la = 0; la <= luck; ++la) {
			int ta = max(1, skills[0] - la);
			int pa = points[0] - 2 * ta;
			int lbm = luck - la;
			for (lb = 0; lb <= lbm; ++lb) {
				int tb = max(1, skills[1] - lb);
				int pb = points[1] - 4 * tb;
				lc = lbm - lb;
				int tc = max(1, skills[2] - lc);
				int pc = points[2] - 8 * tc;
				if (ta <= 75) {
					result = max(result, pa);
				}
				if (tb <= 75) {
					result = max(result, pb);
				}
				if (tc <= 75) {
					result = max(result, pc);
				}
				if ((ta + tb) <= 75) {
					result = max(result, pa + pb);
				}
				if ((ta + tc) <= 75) {
					result = max(result, pa + pc);
				}
				if ((tb + tc) <= 75) {
					result = max(result, pb + pc);
				}
				if ((ta + tb + tc) <= 75) {
					result = max(result, pa + pb + pc);
				}
			}
		}

		return result;
	}
};

// BEGIN CUT HERE
template <typename T> static T __str_to_val(const char *p)
{
	return p;
}
template <> static int __str_to_val(const char *p)
{
	return atoi(p);
}
template <typename T> vector<T> getVector(const char *s)
{
	static const int buffer_size = 1024000;
	static char buffer[buffer_size];
	strcpy(buffer, s);
	vector <T> v;
	char *p = strtok(buffer, " ,");
	while (p) {
		v.push_back(__str_to_val<T>(p));
		p = strtok(NULL, " ,");
	}
	return v;
}

static void Test(const char *points, const char *skills, int luck, int expected)
{
	vector <int> pv = getVector<int>(points);
	vector <int> sv = getVector<int>(skills);
	SRMCodingPhase ___test;
	int result = ___test.countScore(pv, sv, luck);
	printf("result: %s, %d\n", result == expected ? "OK" : "FAILED", result);
}

int main() {
	Test("250, 500, 1000", "10, 25, 40", 0, 1310);
	Test("300, 600, 900", "30, 65, 90", 25, 680);
	Test("250, 550, 950", "10, 25, 40", 75, 1736);
	Test("256, 512, 1024", "35, 30, 25", 0, 1216);
	Test("300, 600, 1100", "80, 90, 100", 4, 0);
	return 0;
}
// END CUT HERE
