// BEGIN CUT HERE
/*
// SRM 519 Div2 Hard (900)
// PROBLEM STATEMENT
// Karel is a robot. He has a set of 64 cards: for each x between 0 and 63,
he has a card that is blank on one side and has 2^x dots on the other side.

Karel's cards are placed on a table. At any moment, the cards show some integer
between 0 and (2^64)-1, inclusive. To read the number, you just count all the dots you see.

Karel is using the cards to count from A to B. That is, he is flipping
some of the cards in such a way that the numbers A, A+1, ..., B appear in this order.

Of course, Karel is using the shortest possible sequence of flips. Additionally,
he always flips the cards one at a time. Sometimes, changing the number
from some Z to Z+1 requires Karel to flip more than one card. In that case,
he flips the necessary cards ordered by the number of dots they have,
starting with the one with the most dots.

For example, if A=6 and B=8, the following will happen:


In the beginning, the card with 4 dots and the card with 2 dots are showing the dots,
all other cards are blank side up. This shows the number 6.
Karel flips the card with 1 dot. Now the number 7 is shown.
Karel flips the card with 8 dots.
Karel flips the card with 4 dots.
Karel flips the card with 2 dots.
Karel flips the card with 1 dot. Now the number 8 is shown and Karel is done.



Given are long longs A and B. Your method must return the largest number
that will be shown at any moment during Karel's counting.


DEFINITION
Class:BinaryCards
Method:largestNumber
Parameters:long long, long long
Returns:long long
Method signature:long long largestNumber(long long A, long long B)


CONSTRAINTS
-A will be between 1 and 10^18, inclusive.
-B will be between A and 10^18, inclusive.


EXAMPLES

0)
6
6

Returns: 6



1)
6
7

Returns: 7



2)
6
8

Returns: 15

This is the example from the problem statement. When flipping cards to create
the number 8 from the number 7, Karel starts by flipping the card with 8 dots.
At this moment, the number shown on the cards is 15.

3)
1
11

Returns: 15



4)
35
38

Returns: 39



5)
1125899906842630
1125899906842632

Returns: 1125899906842639



#line 92 "BinaryCards.cpp"
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
typedef unsigned long long ULL;

class BinaryCards {
	public:
	long long largestNumber(long long A, long long B) {
		ULL M;
		for (M = 1LL << 63; M > 0; M >>= 1) {
			if ((B & M) == 0) {
				continue;
			}
			if ((A & M) == (B & M)) {
				continue;
			}
			A |= (M << 1) - 1;
		}
		return A;
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

static void Test(LL a, LL b, LL expected)
{
	BinaryCards ___test;
	long long result = ___test.largestNumber(a, b);
	printf("result: %s, returned %lld, expected %lld\n", result == expected ? "OK" : "FAILED", result, expected);
}

int main() {
	Test(6, 6, 6);
	Test(6, 7, 7);
	Test(6, 8, 15);
	Test(1, 11, 15);
	Test(35, 38, 39);
	Test(1125899906842630, 1125899906842632, 1125899906842639);
	return 0;
}
// END CUT HERE
