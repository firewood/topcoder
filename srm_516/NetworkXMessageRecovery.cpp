// BEGIN CUT HERE
/*
// SRM 516 Div2 Hard (1000)
// PROBLEM STATEMENT
// Networks are infamous for being unreliable. Data sent over the network may be lost midway or received out of order. For the purpose of this problem, however, we will assume that the data will be received in the correct order but some parts of it may be missing.

The original message is a string consisting of distinct letters (lowercase and uppercase letters are considered distinct). This message is sent multiple times, and the received messages are given in the vector <string> messages. Each element of messages will be a subsequence (not necessarily contiguous) of the original message that retains the relative ordering between letters.


Your job is to return the shortest possible original message. The constraints will guarantee that at least one such message exists. If there are multiple such messages, return the lexicographically first one.

DEFINITION
Class:NetworkXMessageRecovery
Method:recover
Parameters:vector <string>
Returns:string
Method signature:string recover(vector <string> messages)


NOTES
-The length of the answer for some cases may exceed 50 characters.
-If two Strings A and B have the same length, then A comes before B lexicographically if it has a smaller character at the first position where the Strings differ. When comparing the characters, refer to the following list of characters in ascending order: 'A', 'B', ..., 'Z', 'a', 'b', ..., 'z'.


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

typedef set<unsigned int> IntSet;
typedef map<unsigned int, int> IntMap;
typedef map<unsigned int, IntMap> IMM;

class NetworkXMessageRecovery {
	public:
	string recover(vector <string> messages) {
		unsigned char _used[256] = {0};	
		IntSet used;
		IMM M;
		int i, j, k;
		for (i = 0; i < (int)messages.size(); ++i) {
			const string &s = messages[i];
			int length = s.length();
			for (j = 0; j < length; ++j) {
				unsigned char cf = s[j];
				_used[cf] = 1;
				used.insert(cf);
				for (k = j + 1; k < length; ++k) {
					unsigned char cl = s[k];
					(M[cf])[cl] = 1;
					(M[cl])[cf] = -1;
				}
			}
		}

		string result;
		int chars = (int)used.size();
		while (chars > 0) {
			int i;
			for (i = 'A'; i <= 'z'; ++i) {
				if (!_used[i]) {
					continue;
				}

				bool g = true;
				const IntMap &m = M[i];
				IntMap::const_iterator it;
				for (it = m.begin(); it != m.end(); ++it) {
					if (it->second < 0) {
						if (_used[it->first]) {
							g = false;
							break;
						}
					}
				}
				if (!g) {
					continue;
				}
				_used[i] = 0;
				unsigned char C = (unsigned char)i;
				result += C;
				--chars;
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
