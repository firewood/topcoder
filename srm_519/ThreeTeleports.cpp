// BEGIN CUT HERE
/*
// SRM 519 Div2 Middle (600)
// PROBLEM STATEMENT
// You are a frog. You live on an infinite lattice of grid points.
For each pair of integers x, y there is a grid point with coordinates (x,y).
At this moment, you sit on the grid point (xMe,yMe). You want to get home: to the grid point (xHome,yHome).
There are two ways in which you can travel. Your first option is jumping:
if you are at (x,y), you can jump to one of the four neighboring grid points:
(x+1,y), (x-1,y), (x,y+1), or (x,y-1). Each jump takes one second.
Your second option is using a teleport. There are three teleports in the entire world.
Each of them connects two different grid points. If you are at one of the endpoints,
you may activate the teleport and travel to its other endpoint. Traveling by teleport takes 10 seconds.
You are given ints xMe, yMe, xHome, yHome, and a vector <string> teleports that describes the three teleports.
Each element of teleports will be a string containing four integers x1, y1, x2, and y2,
separated by single spaces. These integers describe a teleport with endpoints at (x1,y1) and (x2,y2).
Your method must return the shortest time in which you can reach your home.

DEFINITION
Class:ThreeTeleports
Method:shortestDistance
Parameters:int, int, int, int, vector <string>
Returns:int
Method signature:int shortestDistance(int xMe, int yMe, int xHome, int yHome, vector <string> teleports)


NOTES
-Traveling by a teleport is not mandatory. You may pass through its endpoint and decide not to use it.


CONSTRAINTS
-xMe, yMe, xHome, and yHome will all be between 0 and 1,000,000,000, inclusive.
-teleports will have exactly three elements.
-Each element of teleports will have the following format: "x1 y1 x2 y2" (quotes for clarity),
 where x1, y1, x2, and y2 are integers between 0 and 1,000,000,000, inclusive.
 The integers x1, y1, x2, and y2 will not contain unnecessary leading zeroes.
-All eight points (your location, the location of your home, and the six teleport endpoints)
 will be pairwise distinct.


EXAMPLES

0)
3
3
4
5
{"1000 1001 1000 1002", "1000 1003 1000 1004", "1000 1005 1000 1006"}

Returns: 3

The frog must make at least 3 leaps. For example, from (3,3) to (3,4), then to (3,5), and finally to (4,5).
The teleports are all too far away to be useful.

1)
0
0
20
20
{"1 1 18 20", "1000 1003 1000 1004", "1000 1005 1000 1006"}

Returns: 14

The journey can be done in 40 jumps = 40 seconds, but there is a better solution:
Make 2 jumps to get from (0,0) to (1,1), use the teleport to get to (18,20), and make 2 jumps to get to (20,20).
This solution takes (2+10+2) = 14 seconds.

2)
0
0
20
20
{"1000 1003 1000 1004", "18 20 1 1", "1000 1005 1000 1006"}

Returns: 14

The teleports may be used in either direction, and in any order.

3)
10
10
10000
20000
{"1000 1003 1000 1004", "3 3 10004 20002", "1000 1005 1000 1006"}

Returns: 30



4)
3
7
10000
30000
{"3 10 5200 4900", "12212 8699 9999 30011", "12200 8701 5203 4845"}

Returns: 117

Sometimes the best solution requires us to use more than one teleport.
In this case, the optimal solution looks as follows:

Using jumps, travel to (3,10).
Use the first teleport.
Using jumps, travel from (5200,4900) to (5203,4845).
Use the third teleport.
Using jumps, travel from (12200,8701) to (12212,8699).
Use the second teleport.
Using jumps, travel from (9999,30011) to (10000,30000).



5)
0
0
1000000000
1000000000
{"0 1 0 999999999", "1 1000000000 999999999 0", "1000000000 1 1000000000 999999999"}

Returns: 36

Watch out for overflows. The correct return value will always fit into a int,
but some other paths may be very long.

#line 109 "ThreeTeleports.cpp"
*/
// END CUT HERE
#include <math.h>
#include <algorithm>
#include <list>
#include <map>
#include <string>
#include <vector>
#include <set>

using namespace std;
typedef long long LL;
typedef pair<LL, LL> P;
typedef vector<P> PVec;
typedef map<P, P> PPMap;
typedef vector<LL> LLV;


class ThreeTeleports {
	P Me;
	P Home;
	PVec pv1;
	PVec pv2;
	LLV GoalCost;
	static LL ll_abs(LL n) {
		return n >= 0 ? n : -n;
	}
	static LL Cost(const P &s, const P &d) {
		return ll_abs(s.first - d.first) + ll_abs(s.second - d.second);
	}

public:
	int shortestDistance(int xMe, int yMe, int xHome, int yHome, vector <string> teleports) {
		Me = P(xMe, yMe);
		Home = P(xHome, yHome);
		pv1.clear();
		pv2.clear();
		GoalCost.clear();
		int i, j;
		for (i = 0; i < (int)teleports.size(); ++i) {
			int x1, y1, x2, y2;
			if (sscanf(teleports[i].c_str(), "%d %d %d %d", &x1, &y1, &x2, &y2) != 4) {
				return -1;
			}
			pv1.push_back(P(x1, y1));
			pv2.push_back(P(x2, y2));
			// teleport + walk to goal
			GoalCost.push_back(10 + Cost(*pv2.rbegin(), Home));
			pv1.push_back(P(x2, y2));
			pv2.push_back(P(x1, y1));
			GoalCost.push_back(10 + Cost(*pv2.rbegin(), Home));
		}

		LL Min = Cost(Me, Home);
/*
		for (i = 0; (int)i < pv1.size(); ++i) {
			Min = min(Min, dfs(i));
		}
*/

		bool f = true;
		while (f) {
			f = false;
			for (i = 0; i < (int)pv1.size(); ++i) {
				for (j = 0; j < (int)pv1.size(); ++j) {
					if (i == j) {
						continue;
					}
					// teleport + walk to anther spot + teleport
					LL cost = 10 + Cost(pv2[i], pv1[j]) + GoalCost[j];
					if (cost < GoalCost[i]) {
						f = true;
						GoalCost[i] = cost;
					}
				}
			}
		}

		for (i = 0; i < (int)pv1.size(); ++i) {
			Min = min(Min, Cost(Me, pv1[i]) + GoalCost[i]);
		}

		return (int)Min;
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
	char *p = strtok(buffer, ",");
	while (p) {
		v.push_back(__str_to_val<T>(p));
		p = strtok(NULL, ",");
	}
	return v;
}

static void Test(int x1, int y1, int x2, int y2, const char *seq, int expected)
{
	vector <string> v = getVector<string>(seq);
	ThreeTeleports ___test;
	int result = ___test.shortestDistance(x1, y1, x2, y2, v);
	printf("result: %s, %d\n", result == expected ? "OK" : "FAILED", result);
}

int main() {
	Test(3,3,4,5, "1000 1001 1000 1002,1000 1003 1000 1004,1000 1005 1000 1006", 3);
	Test(0,0,20,20, "1 1 18 20,1000 1003 1000 1004,1000 1005 1000 1006", 14);
	Test(0,0,20,20, "1000 1003 1000 1004,18 20 1 1,1000 1005 1000 1006", 14);
	Test(10,10,10000,20000, "1000 1003 1000 1004,3 3 10004 20002,1000 1005 1000 1006", 30);
	Test(3,7,10000,30000,"3 10 5200 4900,12212 8699 9999 30011,12200 8701 5203 4845", 117);
	Test(0,0,1000000000,1000000000,"0 1 0 999999999,1 1000000000 999999999 0,1000000000 1 1000000000 999999999", 36);
	return 0;
}
// END CUT HERE
