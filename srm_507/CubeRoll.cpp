// BEGIN CUT HERE
/*
// SRM 507 Div2 Hard (1000)
// PROBLEM STATEMENT
// NOTE: This problem statement contains images that may not display properly if viewed outside of the applet.
Fox Ciel is competing against Fox Jiro in a game called cube roll.

Cube roll is played on a horizontal row of cells.  Cells are numbered consecutively, increasing from left to right.  The row is infinitely long, so all integers, including negative ones, are valid cell numbers.  Certain cells contain holes, and they are given in the vector <int> holePos.
Initially, a cube is placed at cell initPos.  The objective of the game is to move the cube to cell goalPos using the least possible number of turns.  On each turn, the player will choose a direction (left or right) and roll the cube in that direction by x number of cells, where x is a perfect square (1, 4, 9, 16, ...).  If at any time during the roll, the cube lands on a cell containing a hole, the cube will fall into the hole.  Once the cube falls into a hole, it can never be moved again.


Return the minimum number of turns required to move the cube to cell goalPos.  If it is impossible, return -1 instead.


DEFINITION
Class:CubeRoll
Method:getMinimumSteps
Parameters:int, int, vector <int>
Returns:int
Method signature:int getMinimumSteps(int initPos, int goalPos, vector <int> holePos)


CONSTRAINTS
-initPos and goalPos will each be between 1 and 100,000, inclusive.
-holePos will contain between 1 and 50 elements, inclusive.
-Each element of holePos be between 1 and 100,000, inclusive.
-initPos and goalPos and all elements of holePos will be distinct.


EXAMPLES

0)
5
1
{3}

Returns: -1

There is a hole between initPos and goalPos, so the cube cannot be moved from initPos to goalPos.

1)
36
72
{300, 100, 200, 400}

Returns: 1

The distance between initPos and goalPos is a perfect square, and there are no holes between them, so the cube can be moved in a single turn.

2)
10
21
{38,45}

Returns: 2

One of the optimal solutions is to move the cube to 10 -> -15 -> 21. (Note that the coordinate of the cube can be a negative integer.)

3)
98765
4963
{10,20,40,30}

Returns: 2



4)
68332
825
{99726,371,67,89210}

Returns: 2



#line 78 "CubeRoll.cpp"
*/
// END CUT HERE
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <vector>

using namespace std;

typedef set<int> IntSet;
typedef vector<int> IntVector;

class CubeRoll {
	public:
	int getMinimumSteps(int initPos, int goalPos, vector <int> holePos) {
		int start = min(initPos, goalPos);
		int end = max(initPos, goalPos);
		sort(holePos.begin(), holePos.end());
		size_t i;
		bool has_lower_bound = false;
		bool has_upper_bound = false;
		int lower_bound, upper_bound;
		for (i = 0; i < holePos.size(); ++i) {
			int p = holePos[i];
			if (p < start) {
				has_lower_bound = true;
				lower_bound = p;
				continue;
			}
			if (p < end) {
				return -1;
			}
			has_upper_bound = true;
			upper_bound = p;
			break;
		}

		int range = end - start;

		if (!has_lower_bound || !has_upper_bound) {
			int sq = (int)sqrt((double)range);
			int remain = range - sq * sq;
			if (remain == 0) {
				return 1;
			}

			if ((range % 2) == 1) {
				// (x + 1)^2 - x^2 = 2x + 1
				return 2;
			}
			if ((range % 4) == 0) {
				// (x + 2)^2 - x-2 = 4x + 4
				return 2;
			}

			// at least 3
			lower_bound = start - 1;
			upper_bound = end + 1;
			range = 3;
		}

		IntSet f;
		IntVector current;
		f.insert(start);
		current.push_back(start);
		int turns;
		for (turns = 1; turns < range; ++turns) {
			IntVector next;
			while (current.size() > 0) {
				int pos = *current.rbegin();
				current.pop_back();
				int d;
				for (d = 1; ; ++d) {
					int x = pos - d * d;
					if (x <= lower_bound) {
						break;
					}
					if (f.find(x) != f.end()) {
						continue;
					}
					if (x == end) {
						return turns;
					}
					f.insert(x);
					next.push_back(x);
				}
				for (d = 1; ; ++d) {
					int x = pos + d * d;
					if (x >= upper_bound) {
						break;
					}
					if (f.find(x) != f.end()) {
						continue;
					}
					if (x == end) {
						return turns;
					}
					f.insert(x);
					next.push_back(x);
				}
			}
			current = next;
		}
		return range;
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

static void Test(int s, int e, const char *seq, int expected)
{
	vector <int> v = getVector<int>(seq);
	CubeRoll ___test;
	int result = ___test.getMinimumSteps(s, e, v);
	printf("result: %s, %d\n", result == expected ? "OK" : "FAILED", result);
}

int main() {
//	Test(0, 9, "9999", 1);
	Test(0, 10, "9999", 2);
//	Test(20, 25, "10,30,50,100", 5);
//	Test(20, 40, "10,30,50,100", -1);
//	Test(1, 3, "0,5,6,7", 2);
//	Test(68332, 825, "99726,371,67,89210", 2);
//	Test(1, 3, "0,5,6,7", 2);
//	Test(10, 21, "38,45", 2);
//	Test(2,99998, "1", 2);
//	Test(42807, 44571, "39017, 20306, 29032, 25977, 18312, 42424, 27909, 22813, 42264, 33996, 14393, 12311, 33005, 16254, 20880, 126, 19777, 31443, 9321, 5760, 1160, 20301, 34356, 32737, 20907, 32171, 36059, 25373, 11937, 16767, 30015, 33421, 3569, 1574, 29407, 22544, 35042, 19455, 40334, 14547, 7328, 27007, 10953, 32956, 39191, 29707, 5139, 41106, 35028, 5366", 1);
//	Test(81247, 62954, "30171, 9572, 20677, 29005, 29157, 18097, 3863, 7601, 38755, 20001, 7099, 49274, 48284, 7155, 1814, 9093, 25130, 27403, 25182, 615, 38597, 6692, 35207, 36018, 30998, 33632, 58506, 16757, 48164, 33934, 29840, 46312, 19493, 41646, 22701, 33757, 55569, 62953, 36871, 28113, 43610, 10937, 1547, 52665, 17212, 24107, 43945, 27055, 43030, 5682", 2);
}
// END CUT HERE
