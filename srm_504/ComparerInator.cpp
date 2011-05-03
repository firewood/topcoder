// BEGIN CUT HERE 
/*
// SRM 504 Div2 Easy 250
// PROBLEM STATEMENT
// Comparer-inator is a very simple language that is specialized in comparisons. It takes an expression and returns the result. There are only two kinds of expressions: a variable name or a tertiary operator inspired by C syntax (which is also used in many languages like Java, C++, and C#). We are interested to use this language to process two vector <int>s, A and B to generate the vector <int> wanted as a result. We have previously found that there are four candidate programs that could be an optimal way to solve the issue we have. Each of the programs takes two arguments a and b.

"a" : This program will return the given argument a.
"b" : This program will return the given argument b.
"a<b?a:b" : If a is less than b, the program will return a, else it will return b.
"a<b?b:a" : If a is less than b, the program will return b, else it will return a.


Given vector <int> A, B and wanted find the shortest of the four candidate programs that, for every index i, will return wanted[i] after being provided a=A[i] and b=B[i] as arguments. Return the length of the shortest program. If no candidate program can do the required job, return -1 instead.

DEFINITION
Class:ComparerInator
Method:makeProgram
Parameters:vector <int>, vector <int>, vector <int>
Returns:int
Method signature:int makeProgram(vector <int> A, vector <int> B, vector <int> wanted)


CONSTRAINTS
-A will contain between 1 and 50 elements, inclusive.
-B and wanted will each contain the same number of elements as A.
-Each element of A, B and wanted will be between 1 and 1000, inclusive.


EXAMPLES

0)
{1}
{2}
{2}

Returns: 1

"b" and "a<b?b:a" (quotes for clarity) are the two programs that will return 2 after being given a=1, b=2 as arguments. "b" is the shortest of them.


1)
{1,3}
{2,1}
{2,3}

Returns: 7

"a<b?b:a" is the only program that will return 2 after being provided a=1, b=2 and will also
return 3 after being provided a=3, b=1.

2)
{1,3,5}
{2,1,7}
{2,3,5}

Returns: -1

None of the four programs can do the job correctly.

3)
{1,3,5}
{2,1,7}
{1,3,5}

Returns: 1



4)
{1,2,3,4,5,6,7,8,9,10,11}
{5,4,7,8,3,1,1,2,3,4,6}
{1,2,3,4,3,1,1,2,3,4,6}

Returns: 7



5)
{1,5,6,7,8}
{1,5,6,7,8}
{1,5,6,7,8}

Returns: 1

"a", "b", "a<b?a:b" and "a<b?b:a" are all valid programs that will give the wanted result. "a" and "b" are the shortest.

*/
// END CUT HERE
#line 89 "ComparerInator.cpp"
#include <string>
#include <vector>

using namespace std;

typedef vector<int>VI;

class ComparerInator {
	public:
	int makeProgram(vector <int> A, vector <int> B, vector <int> wanted) {
		int length = (int)A.size();
		VI::const_iterator ia, ib, iw;
		int count_a = 0, count_b = 0;
		for (ia = A.begin(), ib = B.begin(), iw = wanted.begin();
				ia != A.end(); ++ia, ++ib, ++iw) {
			if (*ia == *iw) {
				++count_a;
			}
			if (*ib == *iw) {
				++count_b;
			}
		}
		if (count_a >= length || count_b >= length) {
			return 1;
		}

		count_a = 0, count_b = 0;
		for (ia = A.begin(), ib = B.begin(), iw = wanted.begin();
				ia != A.end(); ++ia, ++ib, ++iw) {
			if (*ia < *ib) {
				if (*ia == *iw) {
					++count_a;
				}
				if (*ib == *iw) {
					++count_b;
				}
			} else {
				if (*ib == *iw) {
					++count_a;
				}
				if (*ia == *iw) {
					++count_b;
				}
			}
		}
		if (count_a >= length || count_b >= length) {
			return 7;
		}

		return -1;
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

static void Test(const char *A, const char *B, const char *wanted, int expected)
{
	vector <int> _a = getVector<int>(A);
	vector <int> _b = getVector<int>(B);
	vector <int> _w = getVector<int>(wanted);
	ComparerInator ___test;
	int result = ___test.makeProgram(_a, _b, _w);
	printf("result: %s, %d\n", result == expected ? "OK" : "FAILED", result);
}

int main()
{
	Test("1", "2", "2", 1);
	Test("1,3", "2,1", "2,3", 7);
	Test("1,3,5", "2,1,7", "2,3,5", -1);
	Test("1,3,5", "2,1,7", "1,3,5", 1);
	Test("1,2,3,4,5,6,7,8,9,10,11", "5,4,7,8,3,1,1,2,3,4,6", "1,2,3,4,3,1,1,2,3,4,6", 7);
	Test("1,5,6,7,8", "1,5,6,7,8", "1,5,6,7,8", 1);
	return 0;
}
// END CUT HERE
