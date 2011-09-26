// BEGIN CUT HERE
/*
// SRM 512 Div2 Easy (256)
// PROBLEM STATEMENT
// Ash is a marble collector and he likes to create various ornaments using his marbles.

One day, Elsh asks him to create a simple decoration for her desk. She wants a sequence of marbles consisting of at most two different colors. To make the sequence look interesting, each pair of adjacent marbles must have different colors.

Currently, Ash has R red marbles, G green marbles, and B blue marbles. Elsh wants that the resulting sequence is as long as possible. Return this maximum length.

DEFINITION
Class:MarbleDecoration
Method:maxLength
Parameters:int, int, int
Returns:int
Method signature:int maxLength(int R, int G, int B)


CONSTRAINTS
-R will be between 0 and 50, inclusive.
-G will be between 0 and 50, inclusive.
-B will be between 0 and 50, inclusive.


EXAMPLES

0)
0
0
0

Returns: 0

Ash currently doesn't have any marbles at all.

1)
3
0
0

Returns: 1

The only valid sequence is (red).

2)
5
1
2

Returns: 5

One possible sequence is (red, blue, red, blue, red).

3)
7
7
4

Returns: 14



4)
2
3
5

Returns: 7



5)
13
13
13

Returns: 26



#line 82 "MarbleDecoration.cpp"
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
typedef vector<int> VI;

class MarbleDecoration {
	public:
	int maxLength(int R, int G, int B) {
		VI v;
		v.push_back(R);
		v.push_back(G);
		v.push_back(B);
		sort(v.begin(), v.end());
		int a = v[1];
		int b = v[2];
		int len = a * 2;
		b -= a;
		len += min(b, 1);
		return len;
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
	MarbleDecoration ___test;
	int result = 0;
//	int result = ___test.maxLength();
	printf("result: %s, %d\n", result == expected ? "OK" : "FAILED", result);
}

int main() {
	Test("", 0);
	return 0;
}
// END CUT HERE
