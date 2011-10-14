// BEGIN CUT HERE
/*
// SRM 517 Div2 Medium (500)
// PROBLEM STATEMENT
// Toastwoman wants to be a magical girl. As training, she wants to make a ball that contains an integer target.


Initially she has a ball that contains an integer N.
She can smash a ball that contains a composite number (see notes for definition) and break it into two balls.
Each new ball will also contain an integer.
If she smashes a ball that contains a composite number x and it breaks into two balls that contain y and z,
it satisfies y &ge 2, z &ge 2 and yz = x.
For example, if she smashes a ball that contains 12, it breaks into 2 and 6 or 3 and 4.
Toastwoman can control the ball she smashes, but she can't control the numbers in the two new balls
when there are multiple pairs of (y, z) that satisfy the above conditions.
She can apply the described ball smash operation arbitrary number of times,
but she can't smash a ball that contains a non-composite number.


If she can always make a ball that contains target, return "Yes" (quotes for clarity).
Otherwise, return "No" (quotes for clarity).


DEFINITION
Class:CompositeSmash
Method:thePossible
Parameters:int, int
Returns:string
Method signature:string thePossible(int N, int target)


NOTES
-A positive integer x is called a composite number if it has at least one divisor other than 1 and x.
 For example, 4 and 6 are composite numbers, while 1 and 5 are not composite numbers.


CONSTRAINTS
-N will be between 2 and 100,000, inclusive.
-target will be between 2 and 100,000, inclusive.


EXAMPLES

0)
517
47

Returns: "Yes"

If she smashes 517, it breaks into 11 and 47.

1)
8
4

Returns: "Yes"

If she smashes 8, it breaks into 2 and 4.

2)
12
6

Returns: "No"

If she smashes 12 and it breaks into 3 and 4, she can't make 6.

3)
5
8

Returns: "No"



4)
100000
100000

Returns: "Yes"

She already has target.

5)
5858
2

Returns: "Yes"



6)
81461
2809

Returns: "No"



7)
65536
256

Returns: "No"

#line 96 "CompositeSmash.cpp"
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

class CompositeSmash {
	bool isPossible(int N, int Target) {
		if (N == Target) {
			return true;
		}
		if (N % Target) {
			return false;
		}

		int r = (int)sqrt((double)N);
		int i;
		for (i = 2; i <= r; ++i) {
			if ((N % i) != 0) {
				continue;
			}
			if (!isPossible(N / i, Target) && !isPossible(i, Target)) {
				return false;
			}
		}
		return true;
	}

	public:
	string thePossible(int N, int target) {
		return isPossible(N, target) ? "Yes" : "No";
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

static void Test(int N, int target, const char *expected)
{
	CompositeSmash ___test;
	string result = ___test.thePossible(N, target);
	printf("result: %s, %s\n", result.compare(expected) == 0 ? "OK" : "FAILED", result.c_str());
}

int main() {
	Test(517, 47, "Yes");
	Test(8, 4, "Yes");
	Test(12, 6, "No");
	Test(5, 8, "No");
	Test(100000, 100000, "Yes");
	Test(5858, 2, "Yes");
	Test(81461, 2809, "No");
	Test(65536, 256, "No");
	Test(16, 4, "Yes");
	Test(33649, 23, "Yes");

	return 0;
}
// END CUT HERE
