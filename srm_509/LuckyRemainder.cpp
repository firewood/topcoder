// BEGIN CUT HERE
/*
// SRM 509 Div2 Middle (500)
// PROBLEM STATEMENT
// Little Arthur loves numbers and 9 is his most favorite. When encountering a number, he always calculates its lucky remainder - the remainder after division by 9. 

This time Arthur is given a number X of length N which contains no zeros. He is asked to find the supersum of X: super(X).

super(X) is defined as follows. For a given non-full set S of digit positions in X we erase the digits in these positions to obtain a sub-number. For example, if X = 12345 and S = {2, 4} we erase 2nd and 4th digits and obtain a sub-number 135. Supersum of X is simply the sum of sub-numbers for all valid sets S.

For example, if X is 123, then super(X) = 123 + 12 + 13 + 23 + 1 + 2 + 3 = 177.

Calculating super(X) is very difficult for Arthur. However, before getting to work he is wondering if it is possible to quickly tell what the lucky reminder of the supersum of X is. You have to help him.

Given string X, which contains the decimal representation of the number X, return super(X)'s lucky remainder.

DEFINITION
Class:LuckyRemainder
Method:getLuckyRemainder
Parameters:string
Returns:int
Method signature:int getLuckyRemainder(string X)


CONSTRAINTS
-X will contain between 1 and 50 characters, inclusive.
-Each character of X will be one of the following: '1', '2', '3', '4', '5', '6', '7', '8', '9'.


EXAMPLES

0)
"123"

Returns: 6

Example from the problem statement. super(123) = 177, which gives remainder 6 after division by 9.

1)
"24816"

Returns: 3

Supersum of 24816 is 43986.

2)
"8"

Returns: 8



3)
"11235813213455"

Returns: 7

Supersum is 43950094900477.

#line 61 "LuckyRemainder.cpp"
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

class LuckyRemainder {
	public:
	int getLuckyRemainder(string X) {
		int r = 0;
		size_t length = X.length();
		size_t i;
		for (i = 0; i < length; ++i) {
			r += X[i] - '0';
		}
		for (i = 1; i < length; ++i) {
			r = (r * 2) % 9;
		}
		return r % 9;
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
	LuckyRemainder ___test;
	int result = ___test.getLuckyRemainder(seq);
	printf("result: %s, %d\n", result == expected ? "OK" : "FAILED", result);
}

int main() {
	Test("123", 6);
	Test("24816", 3);
	Test("8", 8);
	Test("11235813213455", 7);
	return 0;
}
// END CUT HERE
