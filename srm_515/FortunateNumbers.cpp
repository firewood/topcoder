// BEGIN CUT HERE
/*
// SRM 515 Div2 Easy (250)
// PROBLEM STATEMENT
// Lecette thinks that 5 and 8 are fortunate digits. 
A positive integer is called a fortunate number if it has only fortunate digits in its decimal representation. 

You are given three vector <int>s a, b and c. 
Return that number of fortunate numbers which can be expressed as a[i] + b[j] + c[k] for some indices i, j and k. 
Note that you must not count the same fortunate number more than once. 


DEFINITION
Class:FortunateNumbers
Method:getFortunate
Parameters:vector <int>, vector <int>, vector <int>
Returns:int
Method signature:int getFortunate(vector <int> a, vector <int> b, vector <int> c)


CONSTRAINTS
-a, b and c will each contain between 1 and 50 elements, inclusive. 
-Each element of a, b and c will be between 1 and 30,000, inclusive. 


EXAMPLES

0)
{ 1, 10, 100 }
{ 3, 53 }
{ 4, 54 }

Returns: 2

We have two fortunate numbers 8 = 1 + 3 + 4 and 58 = 1 + 3 + 54. 
58 can be also expressed as 1 + 53 + 4, but you must not count 58 twice. 


1)
{ 47 }
{ 500 }
{ 33 }

Returns: 0

580 is not a fortunate number. 


2)
{ 100, 1, 10, 100, 1, 1 }
{ 3, 53, 53, 53, 53, 53, 53 }
{ 4, 54, 4, 54, 4, 54 }

Returns: 2

3)
{ 500, 800 }
{ 50, 80 }
{ 5, 8 }

Returns: 8

4)
{ 30000, 26264 }
{ 30000, 29294 }
{ 30000, 29594 }

Returns: 3

#line 71 "FortunateNumbers.cpp"
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

typedef set<int> IntSet;
typedef vector<int> VI;

class FortunateNumbers {

public:
	static bool isFortunate(int x) {
		while (x > 0) {
			int r = x % 10;
			if (r != 5 && r != 8) {
				return false;
			}
			x /= 10;
		}
		return true;
	}

public:
	int getFortunate(vector <int> a, vector <int> b, vector <int> c) {
		IntSet ab;
		IntSet Z;
		VI::const_iterator ia, ib, ic;
		for (ia = a.begin(); ia != a.end(); ++ia) {
			for (ib = b.begin(); ib != b.end(); ++ib) {
				ab.insert(*ia + *ib);
			}
		}
		for (ic = c.begin(); ic != c.end(); ++ic) {
			IntSet::const_iterator s;
			for (s = ab.begin(); s != ab.end(); ++s) {
				Z.insert(*ic + *s);
			}
		}
		int r = 0;
		IntSet::const_iterator z;
		for (z = Z.begin(); z != Z.end(); ++z) {
			if (isFortunate(*z)) {
				++r;
			}
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

static void Test(const char *a, const char *b, const char *c, int expected)
{
	vector <int> _a = getVector<int>(a);
	vector <int> _b = getVector<int>(b);
	vector <int> _c = getVector<int>(c);
	FortunateNumbers ___test;
	int result = ___test.getFortunate(_a, _b, _c);
	printf("result: %s, %d\n", result == expected ? "OK" : "FAILED", result);
}

static void __test(int a) {
	int r = FortunateNumbers::isFortunate(a);
	printf("%d -> %s\n", a, r ? "T" : "F");
}

int main() {
	__test(5);
	__test(6);
	__test(18);
	__test(85);
	__test(108);
	__test(555);
	__test(558);
	__test(554);
	__test(5581);
	__test(5585);
	__test(5588);
	__test(1558);
	__test(55555);
	__test(51555);
	__test(58555);
	__test(55550);

	Test("1,10,100","3,53","4,54", 2);
	Test("47","500","33",0);
	Test("100,1,10,100,1,1","3,53,53,53,53,53,53","4,54,4,54,4,54",2);
	return 0;
}
// END CUT HERE
