// BEGIN CUT HERE
/*
// SRM 516 Div2 Easy (250)
// PROBLEM STATEMENT
// Toastman has sent Fox Ciel a message consisting entirely of lowercase 'o' and 'x' letters.
This message has the interesting property that for any even-length contiguous substring of this message,
the number of 'o's will equal the number of 'x's.


Unfortunately due to the nature of the network, some of the letters in the message can become corrupted.
You are given a string message, each character of which is 'o', 'x', or '?'.
'o' or 'x' denotes that the letter in the message is not corrupted and is equal to the corresponding letter.
A '?' denotes that the letter at that position is corrupted and might have been either 'o' or 'x'.


Your job is to replace each of the '?' characters in the input by either 'o' or 'x' such that
the resulting message has the interesting property described above, and return that corrected message.
It is guaranteed that there will be exactly one such message for the given input.

DEFINITION
Class:NetworkXZeroOne
Method:reconstruct
Parameters:string
Returns:string
Method signature:string reconstruct(string message)


CONSTRAINTS
-message will contain between 2 and 50 characters, inclusive.
-Each character in message will be lowercase 'o', lowercase 'x', or '?'.
-There will be exactly one possible corrected message which has the interesting property described in the problem statement.


EXAMPLES

0)
"x?x?"

Returns: "xoxo"

Consider the entire message, which is a contiguous substring of the input message of length 4, which is even.
It has two 'x's, so it follows that the other two '?' characters must be both 'o'.

1)
"?xo?"

Returns: "oxox"

Consider the first two characters of message. Since it's a contiguous substring
of the input message and has a length of 2, which is even,
and since it already contains one 'x', the first '?' must be 'o'.
Then, by considering the entire message as a contiguous substring of length 4, the last character must be 'x'.

2)
"xo"

Returns: "xo"

Sometimes?the?message?is?not?corrupted.

3)
"o??x??o"

Returns: "oxoxoxo"



4)
"???????x"

Returns: "oxoxoxox"



#line 65 "NetworkXZeroOne.cpp"
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

class NetworkXZeroOne {
	public:
	string reconstruct(string message) {
		char buffer[100];
		strcpy(buffer, message.c_str());
		int length = strlen(buffer);
		char *p = strpbrk(buffer, "ox");
		if (p == NULL) {
			return buffer;
		}
		int pos = p - buffer;
		int is_x = *p == 'x';
		if (pos & 1) {
			is_x = !is_x;
		}
		int i;
		for (i = 0; i < length; ++i) {
			buffer[i] = is_x ? 'x' : 'o';
			is_x = !is_x;
		}
		return buffer;
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
	NetworkXZeroOne ___test;
	int result = 0;
//	string result = ___test.reconstruct();
	printf("result: %s, %d\n", result == expected ? "OK" : "FAILED", result);
}

int main() {
	Test("", 0);
	return 0;
}
// END CUT HERE
