// BEGIN CUT HERE
/*
// SRM 507 Div2 Easy (250)
// PROBLEM STATEMENT
// NOTE: This problem statement contains images that may not display properly if viewed outside of the applet.
Fox Ciel is observing the behavior of ants. She has a cube whose vertices are indexed from 0 to 7 as follows.

You are given a vector <int> pos containing the initial locations of the ants.  The i-th element of pos is the index of the vertex where the i-th ant is located.  In an attempt to observe their moves, Ciel puts honey on the 0-th vertex.  The ants notice it immediately and start moving toward the honey.  In a single turn, each ant will either move to an adjacent vertex along an edge of the cube or stay in its current vertex.  All moves in a turn happen simultaneously, and at all times, it is legal for multiple ants to be at the same location of the cube.

Ciel observes the ants until they all move to the 0-th vertex.  In order to determine how clever they were, she wants to know the minimal number of turns that were required for this to happen.  Return this minimal number.


DEFINITION
Class:CubeAnts
Method:getMinimumSteps
Parameters:vector <int>
Returns:int
Method signature:int getMinimumSteps(vector <int> pos)


CONSTRAINTS
-pos will contain between 1 and 50 elements, inclusive.
-Each element of pos will be between 0 and 7, inclusive.


EXAMPLES

0)
{0,1,1}

Returns: 1



1)
{5,4}

Returns: 2



2)
{0}

Returns: 0

There is only one ant, and it is already on the 0-th vertex, so the minimum number of turns required is 0.

3)
{6,1,6}

Returns: 3



4)
{7,7,3,3,7,7,3,3}

Returns: 2


#line 64 "CubeAnts.cpp"
*/
// END CUT HERE
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class CubeAnts {
	public:
	int getMinimumSteps(vector <int> pos) {
		static const int C[] = {0,1,2,1,1,2,3,2};
		int r = 0;
		size_t s = pos.size();
		size_t i;
		for (i = 0; i < s; ++i) {
			r = max(r, C[pos[i]]);
		}
		return r;
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

static void Test(const char *seq, int expected)
{
	vector <int> v = getVector<int>(seq);
	CubeAnts ___test;
	int result = 0;
//	int result = ___test.getMinimumSteps();
	printf("result: %s, %d\n", result == expected ? "OK" : "FAILED", result);
}

int main() {
	Test("", 0);
	return 0;
}
// END CUT HERE
