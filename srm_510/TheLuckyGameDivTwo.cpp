// BEGIN CUT HERE
/*
// SRM 510 Div2 Middle (500)
// PROBLEM STATEMENT
// 
John and Brus believe that the digits 4 and 7 are lucky and all others are not.
According to them, a lucky number is a number that contains only lucky digits in its decimal representation.

	

John and Brus play the following game.
Initially, there is an interval of integers between a and b, inclusive.
Then, John choose a subinterval of the initial interval that contains exactly jLen numbers.
Finally, Brus chooses a subinterval of John's subinterval that contains exactly bLen numbers.
The outcome of the game is the total number of lucky numbers in Brus's subinterval.



John follows the optimal strategy that maximizes the outcome.
Brus follows the optimal strategy that minimizes the outcome.
Return the outcome of the game.



DEFINITION
Class:TheLuckyGameDivTwo
Method:find
Parameters:int, int, int, int
Returns:int
Method signature:int find(int a, int b, int jLen, int bLen)


CONSTRAINTS
-a will be between 1 and 4747, inclusive.
-b will be between a and 4747, inclusive.
-jLen will be between 1 and b-a+1, inclusive.
-bLen will be between 1 and jLen, inclusive.


EXAMPLES

0)
1
10
2
1

Returns: 0

John will choose a subinterval containing two consecutive numbers. Then Brus will choose a subinterval containing just one of these two numbers. Since no two lucky numbers are consecutive, Brus will always be able to choose a subinterval containing no lucky numbers, so the outcome is 0.

1)
1
100
100
100

Returns: 6

Here, John and Brus have no choice. The outcome of the game is the number of lucky numbers between 1 and 100, inclusive.

2)
4
8
3
2

Returns: 1

John can choose one of the intervals [4; 6], [5; 7] or [6; 8]. In the first two cases Brus can choose a subinterval that contains no lucky numbers. However, in the last case, Brus will have to choose a subinterval that contains the lucky number 7. Therefore it is optimal for John to choose [6; 8], and the outcome is 1.

3)
1
100
75
50

Returns: 2

#line 81 "TheLuckyGameDivTwo.cpp"
*/
// END CUT HERE
#include <math.h>
#include <algorithm>
#include <map>

using namespace std;

typedef map<int, int> IntMap;

class TheLuckyGameDivTwo {
	static bool isLucky(int n) {
		while (n > 0) {
			int x = n % 10;
			if (x != 4 && x != 7) {
				return false;
			}
			n /= 10;
		}
		return true;
	}

public:
	int find(int a, int b, int jLen, int bLen) {
		int result = 0;
		IntMap Brus;
		int j;
		int jm = b - jLen + 1;
		for (j = a; j <= jm; ++j) {
			int BrusScore = 9999;
			int k;
			int km = j + jLen - bLen;
			for (k = j; k <= km; ++k) {
				IntMap::const_iterator bf = Brus.find(k);
				if (bf == Brus.end()) {
					// not calculated yet
					int bs = 0;
					int l;
					int lm = k + bLen - 1;
					for (l = k; l <= lm; ++l) {
						bs += isLucky(l);
					}
					Brus[k] = bs;
					BrusScore = min(BrusScore, bs);
				} else {
					BrusScore = min(BrusScore, bf->second);
				}
			}
			result = max(result, BrusScore);
		}
		return result;
	}
};

// BEGIN CUT HERE
static void Test(int a, int b, int jLen, int bLen, int expected)
{
	TheLuckyGameDivTwo ___test;
	int result = ___test.find(a, b, jLen, bLen);
	printf("result: %s, %d\n", result == expected ? "OK" : "FAILED", result);
}

int main() {
	Test(1, 10, 2, 1, 0);
	Test(1, 100, 100, 100, 6);
	Test(4,8,3,2,1);
	Test(1,100,75,50,2);
	return 0;
}
// END CUT HERE
