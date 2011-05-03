/*
// BEGIN CUT HERE
// PROBLEM STATEMENT
// Let's say you have a binary string such as the following:

011100011

One way to encrypt this string is to add to each digit the sum of its adjacent digits.  For example, the above string would become:

123210122

In particular, if P is the original string, and Q is the encrypted string, then Q[i] = P[i-1] + P[i] + P[i+1] for all digit positions i.  Characters off the left and right edges of the string are treated as zeroes.

An encrypted string given to you in this format can be decoded as follows (using 123210122 as an example):

Assume P[0] = 0.
Because Q[0] = P[0] + P[1] = 0 + P[1] = 1, we know that P[1] = 1.
Because Q[1] = P[0] + P[1] + P[2] = 0 + 1 + P[2] = 2, we know that P[2] = 1.
Because Q[2] = P[1] + P[2] + P[3] = 1 + 1 + P[3] = 3, we know that P[3] = 1.
Repeating these steps gives us P[4] = 0, P[5] = 0, P[6] = 0, P[7] = 1, and P[8] = 1.
We check our work by noting that Q[8] = P[7] + P[8] = 1 + 1 = 2.  Since this equation works out, we are finished, and we have recovered one possible original string.

Now we repeat the process, assuming the opposite about P[0]:

Assume P[0] = 1.
Because Q[0] = P[0] + P[1] = 1 + P[1] = 0, we know that P[1] = 0.
Because Q[1] = P[0] + P[1] + P[2] = 1 + 0 + P[2] = 2, we know that P[2] = 1.
Now note that Q[2] = P[1] + P[2] + P[3] = 0 + 1 + P[3] = 3, which leads us to the conclusion that P[3] = 2.  However, this violates the fact that each character in the original string must be '0' or '1'.  Therefore, there exists no such original string P where the first digit is '1'.

Note that this algorithm produces at most two decodings for any given encrypted string.  There can never be more than one possible way to decode a string once the first binary digit is set.

Given a string message, containing the encrypted string, return a vector <string> with exactly two elements.  The first element should contain the decrypted string assuming the first character is '0'; the second element should assume the first character is '1'.  If one of the tests fails, return the string "NONE" in its place.  For the above example, you should return {"011100011", "NONE"}.

DEFINITION
Class:BinaryCode
Method:decode
Parameters:string
Returns:vector <string>
Method signature:vector <string> decode(string message)


CONSTRAINTS
-message will contain between 1 and 50 characters, inclusive.
-Each character in message will be either '0', '1', '2', or '3'.


EXAMPLES

0)
"123210122"

Returns: { "011100011",  "NONE" }

The example from above.

1)
"11"

Returns: { "01",  "10" }

We know that one of the digits must be '1', and the other must be '0'.  We return both cases.

2)
"22111"

Returns: { "NONE",  "11001" }

Since the first digit of the encrypted string is '2', the first two digits of the original string must be '1'.  Our test fails when we try to assume that P[0] = 0.

3)
"123210120"

Returns: { "NONE",  "NONE" }

This is the same as the first example, but the rightmost digit has been changed to something inconsistent with the rest of the original string.  No solutions are possible.

4)
"3"

Returns: { "NONE",  "NONE" }

5)
"12221112222221112221111111112221111"

Returns: { "01101001101101001101001001001101001",  "10110010110110010110010010010110010" }

// END CUT HERE
*/
#line 88 "BinaryCode.cpp"
#include <string>
#include <vector>
using namespace std;
class BinaryCode {
	public:
	vector <string> decode(string message) {
		vector <string> v;
		v.push_back(d(0, message.length(), message.c_str()));
		v.push_back(d(1, message.length(), message.c_str()));
		return v;
	}
	static string d(int a, size_t l, const char *t) {
		int result[100] = {0};
		result[1] = a;
		size_t p;
		for (p = 0; p < l; ++p) {
			int x = t[p] - '0';
			int z = x - result[p] - result[p + 1];
			if (z < 0 || z > 1) {
				return "NONE";
			}
			result[p + 2] = z;
		}

		string s;
		for (p = 1; p <= l; ++p) {
			s += '0' + result[p];
		}
		return s;
	}
};

// BEGIN CUT HERE 
static void Test(const char *t)
{
	BinaryCode ___test;
	vector <string> v = ___test.decode(t);
	printf("decoded: %s, %s\n", v[0].c_str(), v[1].c_str());
}

int main() {

	Test("123210122");
	Test("11");
	Test("22111");
	Test("123210120");
	Test("3");
}
// END CUT HERE
