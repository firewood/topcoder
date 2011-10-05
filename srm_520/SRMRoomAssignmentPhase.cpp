// BEGIN CUT HERE
/*
// SRM 520 Div2 Easy (250)
// PROBLEM STATEMENT
// Mr. Dengklek introduced you to an online programming contest called SRM (Special Round Match)!

There are N coders in the contest, including you. Each coder has a skill measurement called rating.
This information is given in ratings, where ratings[0] is your rating and
ratings[1] through ratings[N-1] are the ratings of the other coders.
Ratings of all coders are pairwise distinct.

You are now in the room assignment phase of the contest. There are K available rooms.
Each coder will be assigned to exactly one room in the following way:
the coders, in descending order of their ratings, are assigned one-by-one
to rooms 1, 2, ..., K, 1, 2, ..., K, ... and so on in that order.
See the examples for further clarification.

You wish to win your room, so you wonder how many stronger competitors you have.
Return the number of coders in your room who have higher ratings than yours.

DEFINITION
Class:SRMRoomAssignmentPhase
Method:countCompetitors
Parameters:vector <int>, int
Returns:int
Method signature:int countCompetitors(vector <int> ratings, int K)


CONSTRAINTS
-ratings will contain between 2 and 50 elements, inclusive.
-Each element of ratings will be between 0 and 1199, inclusive.
-All elements of ratings will be distinct.
-K will be between 1 and the number of elements in ratings, inclusive.


EXAMPLES

0)
{491, 981, 1199, 763, 994, 879, 888}
3

Returns: 2

Here is the room assignment for all coders.

Room 1 coders' ratings:

1199
888
491


Room 2 coders' ratings:

994
879


Room 3 coders' ratings:

981
763


You are in Room 1, and there are 2 coders with greater ratings than yours.



1)
{1024, 1000, 600}
1

Returns: 0

You are the highest rated coder in Room 1.

2)
{505, 679, 900, 1022}
2

Returns: 1

You are the lowest rated coder in Room 2.

3)
{716, 58, 1000, 1004, 912, 822, 453, 1100, 558}
3

Returns: 1

You are the second highest rated coder in Room 3.

4)
{422, 623, 1023, 941, 882, 776, 852, 495, 803, 622, 618, 532, 751, 500}
4

Returns: 3



5)
{1197, 1198, 1196, 1195, 1199}
1

Returns: 2



#line 102 "SRMRoomAssignmentPhase.cpp"
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

class SRMRoomAssignmentPhase {
	public:
	int countCompetitors(vector <int> ratings, int K) {
		int me = ratings[0];
		sort(ratings.begin(), ratings.end());
		int i;
		for (i = ratings.size() - 1; i >= 0; --i) {
			if (ratings[i] == me) {
				break;
			}
		}
		return (ratings.size() - 1 - i) / K;
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

static void Test(const char *seq, int K, int expected)
{
	vector <int> v = getVector<int>(seq);
	SRMRoomAssignmentPhase ___test;
	int result = ___test.countCompetitors(v, K);
	printf("result: %s, %d\n", result == expected ? "OK" : "FAILED", result);
}

int main() {
	Test("491, 981, 1199, 763, 994, 879, 888", 3, 2);
	Test("1024, 1000, 600", 1, 0);
	Test("505, 679, 900, 1022", 2, 1);
	Test("716, 58, 1000, 1004, 912, 822, 453, 1100, 558", 3, 1);
	Test("422, 623, 1023, 941, 882, 776, 852, 495, 803, 622, 618, 532, 751, 500", 4, 3);
	Test("1197, 1198, 1196, 1195, 1199", 1, 2);
	return 0;
}
// END CUT HERE
