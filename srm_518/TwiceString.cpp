// BEGIN CUT HERE
/*
// SRM 518 Div2 Easy (250)
// PROBLEM STATEMENT
// 
You are given a string s.  Return the shortest string which contains s as a contiguous substring twice.

Note that two occurrences of s may overlap. For example, "ababa" contains "aba" twice.


DEFINITION
Class:TwiceString
Method:getShortest
Parameters:string
Returns:string
Method signature:string getShortest(string s)


NOTES
-The shortest string which contains s as a contiguous substring twice is always unique.


CONSTRAINTS
-s will contain between 1 and 50 characters, inclusive. 
-Each character in s will be a lowercase letter ('a'-'z').  


EXAMPLES

0)
"aba"

Returns: "ababa"

This is the example shown in the problem statement. 

1)
"xxxxx"

Returns: "xxxxxx"



2)
"topcoder"

Returns: "topcodertopcoder"



3)
"abracadabra"

Returns: "abracadabracadabra"



#line 59 "TwiceString.cpp"
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

class TwiceString {
	public:
	string getShortest(string s) {
		size_t i;
		for (i = 1; i <= s.length(); ++i) {
			string temp;
			temp.assign(s.c_str(), i);
			temp += s;
			if (strncmp(temp.c_str(), s.c_str(), s.length()) == 0) {
				return temp;
			}
		}
		return "";
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

static void Test(const char *seq, const char *expected)
{
	TwiceString ___test;
	string result = ___test.getShortest(seq);
	printf("result: %s, %s\n", strcmp(result.c_str(), expected) == 0 ? "OK" : "FAILED", result.c_str());
}

int main() {
	Test("aba", "ababa");
	Test("xxxxx", "xxxxxx");
	Test("topcoder", "topcodertopcoder");
	Test("abracadabra", "abracadabracadabra");
	return 0;
}
// END CUT HERE
