// BEGIN CUT HERE
/*
// SRM 516 Div2 Hard (1000)
// PROBLEM STATEMENT
// Networks are infamous for being unreliable. Data sent over the network
may be lost midway or received out of order. For the purpose of this problem,
however, we will assume that the data will be received in the correct order
but some parts of it may be missing.

The original message is a string consisting of distinct letters
(lowercase and uppercase letters are considered distinct).
This message is sent multiple times, and the received messages are given
in the vector <string> messages. Each element of messages will be a subsequence
(not necessarily contiguous) of the original message that retains the relative ordering between letters.


Your job is to return the shortest possible original message.
The constraints will guarantee that at least one such message exists.
If there are multiple such messages, return the lexicographically first one.

DEFINITION
Class:NetworkXMessageRecovery
Method:recover
Parameters:vector <string>
Returns:string
Method signature:string recover(vector <string> messages)


NOTES
-The length of the answer for some cases may exceed 50 characters.
-If two Strings A and B have the same length, then A comes before B lexicographically
if it has a smaller character at the first position where the Strings differ.
When comparing the characters, refer to the following list of characters in ascending order:
'A', 'B', ..., 'Z', 'a', 'b', ..., 'z'.


CONSTRAINTS
-messages will contain between 1 and 50 elements, inclusive.
-Each element of messages will contain between 1 and 50 characters, inclusive.
-messages will contain only the characters 'a'-'z' and 'A'-'Z'.
-For each i, all characters in messages[i] will be distinct.
-There will exist at least one string such that each element of messages is a subsequence of this string.


EXAMPLES

0)
{"acd", "bce"}

Returns: "abcde"

The only possible original strings of length 5 are:

"abcde"
"abced"
"bacde"
"baced"

The?lexicographically?smallest?of?them?is?"abcde".

1)
{"ed", "dc", "cb", "ba"}

Returns: "edcba"



2)
{"Fox", "Ciel", "FoxCiel"}

Returns: "FoxCiel"



3)
{"a", "A"}

Returns: "Aa"



#line 71 "NetworkXMessageRecovery.cpp"
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

typedef unsigned int UI;
typedef set<UI> IntSet;

class NetworkXMessageRecovery {
	public:
	string recover(vector <string> messages) {
		IntSet used;
		IntSet former[128];
		int i, j, k;
		for (i = 0; i < (int)messages.size(); ++i) {
			const string &s = messages[i];
			int length = s.length();
			for (j = 0; j < length; ++j) {
				used.insert(s[j]);
				for (k = 0; k < j; ++k) {
					former[s[j]].insert(s[k]);
				}
			}
		}

		string result;
		while (used.size() > 0) {
			IntSet::iterator u;
			for (u = used.begin(); u != used.end(); ++u) {
				bool f = true;
				IntSet::const_iterator it;
				for (it = former[*u].begin(); it != former[*u].end(); ++it) {
					if (used.find(*it) != used.end()) {
						f = false;
						break;
					}
				}
				if (!f) {
					continue;
				}
				result += (unsigned char)*u;
				used.erase(u);
				break;
			}
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

static void Test(const char *seq, const char *expected)
{
	vector <string> v = getVector<string>(seq);
	NetworkXMessageRecovery ___test;
	string result = ___test.recover(v);
	printf("result: %s, %s\n", result.compare(expected) == 0 ? "OK" : "FAILED", result.c_str());
}

int main() {
	Test("acd bce", "abcde");
	Test("ed dc cb ba", "edcba");
	Test("Fox Ciel FoxCiel", "FoxCiel");
	Test("a A", "Aa");
	return 0;
}
// END CUT HERE
