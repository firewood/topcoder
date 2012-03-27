// BEGIN CUT HERE
/*
// SRM 510 Div2 Hard (1000)

// PROBLEM STATEMENT
// John and Brus believe that the digits 4 and 7 are lucky and all others are not.
Recently, they became interested in numeral systems with different bases.
Normally, people use the numeral system with base 10 to represent numbers,
however, there exist numeral systems with other bases. More exactly,
for each integer B, B >= 2, there exists a numeral system with base B.
In this system, there are B different digits, used to represent numbers from
0 to B-1, inclusive. In order to represent a positive integer A in such system,
it's necessary to find such digits a[n], a[n-1], ..., a[0], that
A = a[n] * B^n + a[n-1] * B^(n-1) + ... + a[0] * B^0 (here ^ denotes the power operator),
and then write these digits from left to right, in this exact order. For example,
255 = 4 * 62 + 7, therefore representation of number 255 in the numeral system with
base 62 consists of two digits, the leftmost digit is 4 and the rightmost digit is 7.

The base of numeral system B is called lucky for some integer number A
if all digits of the number A represented in numeral system with base B are
the lucky digits (i.e. 4 and 7). For example, base 62 is lucky for the number 255.

You are given a long long n. Return the total number of lucky bases for the number n.
If there are infinitely many such lucky bases, return -1 instead.


DEFINITION
Class:TheLuckyBasesDivTwo
Method:find
Parameters:long long
Returns:long long
Method signature:long long find(long long n)


CONSTRAINTS
-n will be between 1 and 10^12, inclusive.


EXAMPLES

0)
255

Returns: 1

The only lucky base for the number 255 is 62.
Note that base 52 is not lucky. Representation of 255 in this base contains digits 4 and 47.
The digit 47 is not lucky, even though its decimal representation contains only lucky digits.
Only the digits 4 and 7 are considered to be lucky.


1)
4

Returns: -1

All bases greater than 4 are lucky.


2)
13

Returns: 0

No lucky bases here.


3)
60

Returns: 2

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

class TheLuckyBasesDivTwo {

public:
	long long find(long long n) {
		if (n == 4 || n == 7) {
			return -1;
		}
		LL result = 0;
		LL a, b, c, d;
		for (a = 4; a <= 7; a += 3) {
			c = n - a;
			if (c > 4) {
				result += ((c % 4) == 0 && (c / 4) > 4);
				result += ((c % 7) == 0 && (c / 7) > 7);
			}
		}
		for (b = 5; b*b <= n; ++b) {
			c = 0;
			d = n;
			while (d > b) {
				LL a = d % b;
				if (a != 4 && a != 7) {
					break;
				}
				++c;
				d /= b;
				if (d < b && (d == 4 || d == 7)) {
					result += c >= 2;
				}
			}
		}
		return result;
	}
};

// BEGIN CUT HERE
static void Test(LL n, LL expected)
{
	TheLuckyBasesDivTwo ___test;
	LL result = ___test.find(n);
	printf("result: %s, returned %lld, expected %lld\n", result == expected ? "OK" : "FAILED", result, expected);
}

int main() {

	// example 0
	Test(255, 1);

	// example 1
	Test(4, -1);

	// example 2
	Test(13, 0);

	// example 3
	Test(60, 2);

	Test(474747477747, 3);
	
	Test(5*4+4, 1);
	Test(25*4+5*4+4, 2);

	return 0;
}
// END CUT HERE
