// BEGIN CUT HERE
/*
// SRM 502 Div2 Medium (500)
// PROBLEM STATEMENT
// Farmer John wants to buy a lottery ticket. Before he buys a ticket,
Fox Brus decided to calculate the probability that John will get a prize.


There are 1,000,000,000 types of lottery tickets.
They are numbered "000000000" to "999999999" (they may have leading zeroes).
Each type of ticket has an equal probability of being bought by John.
You are given a vector <string> goodSuffixes.
If the number written on John's ticket has at least one element of goodSuffixes as a suffix,
he will get a prize.


Return the probability that John will get a prize.

DEFINITION
Class:TheLotteryBothDivs
Method:find
Parameters:vector <string>
Returns:double
Method signature:double find(vector <string> goodSuffixes)


NOTES
-The returned value must have an absolute or relative error less than 1e-9.
-A suffix of a string is obtained by removing zero or more contiguous characters
 from the beginning of the string.


CONSTRAINTS
-goodSuffixes will contain between 1 and 50 elements, inclusive.
-Each element of goodSuffixes will contain between 1 and 9 characters, inclusive.
-Each character in goodSuffixes will be a digit ('0'-'9').


EXAMPLES

0)
{"4"}

Returns: 0.1

John will get a prize if the last digit is '4'. It happens with probability 0.1.

1)
{"4", "7"}

Returns: 0.2



2)
{"47", "47"}

Returns: 0.01

goodSuffixes may contain duplicate elements.

3)
{"47", "58", "4747", "502"}

Returns: 0.021



4)
{"8542861", "1954", "6", "523", "000000000", "5426", "8"}

Returns: 0.201100101



#line 70 "TheLotteryBothDivs.cpp"
*/
// END CUT HERE
#include <math.h>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

typedef long long LL;
typedef vector<int> IntVec;
typedef vector<string> StringVector;
typedef set<string> StringSet;

class TheLotteryBothDivs {
public:
	double find(vector <string> goodSuffixes) {
		double result = 0;
		StringSet S;
		int i;
		for (i = 0; i < (int)goodSuffixes.size(); ++i) {
			reverse(goodSuffixes[i].begin(), goodSuffixes[i].end());
			S.insert(goodSuffixes[i]);
		}
		string prev;
		StringSet::const_iterator it;
		for (it = S.begin(); it != S.end(); ++it) {
			const string &s = *it;
			if (!prev.empty() && strncmp(prev.c_str(), s.c_str(), prev.length()) == 0) {
				continue;
			}
			result += pow(0.1, (double)s.length());
			prev = s;
		}
		return result;
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

static void Test(const char *seq, double expected)
{
	vector <string> v = getVector<string>(seq);
	TheLotteryBothDivs ___test;
	double result = ___test.find(v);
	printf("result: %s, expexted %.9f, returned %.9f\n", fabs(result - expected) < 0.000000001 ? "OK" : "FAILED", expected, result);
}


int main() {
	Test("4", 0.1);
	Test("4 7", 0.2);
	Test("47 47", 0.01);
	Test("47 58 4747 502", 0.021);
	Test("8542861 1954 6 523 000000000 5426 8", 0.201100101);
	return 0;
}
// END CUT HERE
