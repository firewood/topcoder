// BEGIN CUT HERE
/*
// SRM 509 Div2 Easy (250)
// PROBLEM STATEMENT
// Little Arthur loves numbers, especially palindromic ones. A palindromic string is a string that reads the same both forwards and backwards. A palindromic number is a non-negative integer such that its decimal representation (without insignificant leading zeros) is a palindromic string. For example, 12321, 101, 9, and 0 are palindromic numbers but 2011, 509, and 40 are not.

Arthur has a number X and he would like to palindromize it. Palindromization of a number means adding or subtracting some value to obtain a palindromic number. For example, one possible way to palindromize number 25 is adding 8 resulting in number 33, which is palindromic.

Unfortunately Arthur cannot palindromize numbers for free. The cost of palindromization in dollars is equal to the value added or subtracted. In the previous example Arthur would have to pay 8 dollars.

Of course Arthur would like to palindromize X spending the least amount of money. Given X return the minimum amount of money Arthur needs.

DEFINITION
Class:PalindromizationDiv2
Method:getMinimumCost
Parameters:int
Returns:int
Method signature:int getMinimumCost(int X)


CONSTRAINTS
-X will be between 0 and 100000 (10^5), inclusive.


EXAMPLES

0)
25

Returns: 3

In the problem statement it is shown that adding 8 to 25 results in a palindromic number 33. However, this is not the cheapest way to palindromize 25. Arthur can subtract 3 to obtain a number 22 which is also palindromic.

1)
12321

Returns: 0

Already a palindromic number.

2)
40

Returns: 4



3)
2011

Returns: 9



4)
0

Returns: 0


#line 63 "PalindromizationDiv2.cpp"
*/
// END CUT HERE
#include <string>
#include <vector>

using namespace std;

static bool isPalindromic(int x) {
	if (x <= 9) {
		return true;
	}
	char a[16] = {0};
	char b[16] = {0};
	char *aw = a;
	char *bw = b + 16;
	while (x > 0) {
		char r = (char)(x % 10);
		*aw++ = r;
		*--bw = r;
		x /= 10;
	}
	return memcmp(a, bw, (aw - a) / 2) == 0;
}

class PalindromizationDiv2 {
	public:
	int getMinimumCost(int X) {
		int i;
		for (i = 0; i < X; ++i) {
			if (isPalindromic(X + i) || isPalindromic(X - i)) {
				break;
			}
		}
		return i;
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
	PalindromizationDiv2 ___test;
	int result = 0;
//	int result = ___test.getMinimumCost();
	printf("result: %s, %d\n", result == expected ? "OK" : "FAILED", result);
}

static void Test_isPalindromic(int x) {
	printf("test of %d: %s\n", x, isPalindromic(x) ? "Yes" : "No");
}

int main() {
	Test_isPalindromic(1);
	Test_isPalindromic(10);
	Test_isPalindromic(100);
	Test_isPalindromic(101);
	Test_isPalindromic(1000);
	Test_isPalindromic(1001);
	Test_isPalindromic(10000);
	Test_isPalindromic(10001);
	Test_isPalindromic(12011);
	Test_isPalindromic(12021);
	Test_isPalindromic(12022);
	return 0;
}
// END CUT HERE
