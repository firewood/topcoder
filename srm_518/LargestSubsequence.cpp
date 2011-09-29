// BEGIN CUT HERE
/*
// SRM 518 Div2 Middle (500)
// PROBLEM STATEMENT
// 
For strings x and y, we say y is a subsequence of x if y can be obtained from x by erasing some
(possibly all or none) of the letters in x. For example, "tpcdr" is a subsequence of "topcoder",
while "rt" is not. 

Given a string s, return the lexicographically largest subsequence of s. 


DEFINITION
Class:LargestSubsequence
Method:getLargest
Parameters:string
Returns:string
Method signature:string getLargest(string s)


NOTES
-For strings x and y, x is said to be lexicographically larger than y
 if y is a prefix of x or y has a smaller character than x at the first position where they differ.
 Order of characters is defined as the order of ASCII codes: 'a' < 'b' < ... < 'z'. 


CONSTRAINTS
-s will contain between 1 and 50 characters, inclusive. 
-Each character in s will be a lowercase letter ('a'-'z').


EXAMPLES

0)
"test"

Returns: "tt"

All subsequences listed in lexicographical order are "" (empty string),
"e", "es", "est", "et", "s", "st", "t", "te", "tes", "test", "tet", "ts", "tst" and "tt".
So return "tt".

1)
"a"

Returns: "a"

There are only two subsequences, "" and "a". 

2)
"example"

Returns: "xple"



3)
"aquickbrownfoxjumpsoverthelazydog"

Returns: "zyog"



#line 59 "LargestSubsequence.cpp"
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

typedef set<string> StringSet;
typedef map<string, string> StringMap;

class LargestSubsequence {
	public:
	string getLargest(string s) {
		string answer;

		char buffer[64] = {0};
		strncpy(buffer, s.c_str(), 63);
		const char *src = buffer;

		const char *seq = "zyxwvutsrqponmlkjihgfedcba";

		int seq_index = 0;
		while (*src && seq_index < 26) {
			const char *p = strchr(src, seq[seq_index]);
			if (p == NULL) {
				++seq_index;
				continue;
			}
			answer += *p;
			src = p + 1;
			seq_index = 0;
		}

		return answer;
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
	LargestSubsequence ___test;
	string result = ___test.getLargest(seq);
	printf("result: %s, %s\n", strcmp(result.c_str(), expected) == 0 ? "OK" : "FAILED", result.c_str());
}

int main() {
	Test("test", "tt");
	Test("a", "a");
	Test("example", "xple");
	Test("aquickbrownfoxjumpsoverthelazydog", "zyog");
	return 0;
}
// END CUT HERE
