// BEGIN CUT HERE
/*
// SRM 510 Div2 Easy
// PROBLEM STATEMENT
// 
John and Brus believe that the digits 4 and 7 are lucky and all others are not.
According to them, an almost lucky number is a number that contains at most one non-lucky digit in its decimal representation.
Return the total number of almost lucky numbers between a and b, inclusive.



DEFINITION
Class:TheAlmostLuckyNumbersDivTwo
Method:find
Parameters:int, int
Returns:int
Method signature:int find(int a, int b)


CONSTRAINTS
-a will be between 1 and 1,000,000, inclusive.
-b will be between a and 1,000,000, inclusive.


EXAMPLES

0)
4
7

Returns: 4

All numbers between 4 and 7 are almost lucky.

1)
8
19

Returns: 4

Numbers 8, 9, 14 and 17 are almost lucky.

2)
28
33

Returns: 0

No almost lucky numbers here.

3)
1234
4321

Returns: 36



#line 60 "TheAlmostLuckyNumbersDivTwo.cpp"
*/
// END CUT HERE
#include <stdio.h>

class TheAlmostLuckyNumbersDivTwo {
	static bool isLucky(int n) {
		if (n < 10) {
			return true;
		}
		int c = 0;
		while (n > 0) {
			int x = n % 10;
			if (x != 4 && x != 7) {
				++c;
				if (c >= 2) {
					return false;
				}
			}
			n /= 10;
		}
		return true;
	}

public:
	int find(int a, int b) {
		int result = 0;
		for (; a <= b; ++a) {
			if (isLucky(a)) {
				++result;
			}
		}
		return result;
	}
};

// BEGIN CUT HERE
static void Test(int a, int b, int expected)
{
	TheAlmostLuckyNumbersDivTwo ___test;
	int result = ___test.find(a, b);
	printf("result: %s, %d\n", result == expected ? "OK" : "FAILED", result);
}

int main() {
	Test(4, 7, 4);
	return 0;
}
// END CUT HERE
