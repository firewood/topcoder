// BEGIN CUT HERE
/*
// SRM 516 Div2 Middle (500)
// PROBLEM STATEMENT
// One-time pad (patented by Vernam in 1919) is one of the most widely known schemes
to encrypt a binary string to achieve confidentiality. This scheme takes a binary string
(a string consisting of only the digits 0 and 1) as input and outputs another binary string
of the same length. The input is called the plaintext, and the output is called the ciphertext.
The scheme uses a key which is another binary string of the same length as the input.
The i-th bit of the ciphertext is defined as the XOR of the i-th bit of the plaintext and the key
(see the notes for XOR definition). The ciphertext is sent to the receiving party.

In this problem, we will consider several messages, each of length N, encrypted using a single key of length N.


We would like to investigate how strong this cipher is. Suppose an adversary manages to find out
the content of all the original messages (i.e., the plaintexts) and some of the encrypted messages
(i.e., ciphertexts). These messages are given in the vector <string>s plaintexts and ciphertexts, respectively.
Return the number of possible keys that are consistent with this data. The constraints will guarantee that
there is at least one such key. A key is consistent if for all members of ciphertexts C, there exists a member
of plaintexts P such that when P is encrypted using the specified key, it becomes C.

DEFINITION
Class:NetworkXOneTimePad
Method:crack
Parameters:vector <string>, vector <string>
Returns:int
Method signature:int crack(vector <string> plaintexts, vector <string> ciphertexts)


NOTES
-XOR is a binary operation on bits defined as follows: 0 XOR 0 = 0, 0 XOR 1 = 1, 1 XOR 0 = 1, 1 XOR 1 = 0.


CONSTRAINTS
-plaintexts will contain between 1 and 50 elements, inclusive.
-Each element of plaintexts will contain between 1 and 50 characters, inclusive.
-All the elements of plaintexts will contain the same number of characters.
-All the characters in plaintexts will be either '0' (zero) or '1' (one).
-All the elements of plaintexts will be distinct.
-ciphertexts will contain between 1 and 50 elements, inclusive.
-All the elements of ciphertexts will contain the same number of characters as all the elements of plaintexts.
-All the characters in ciphertexts will be either '0' (zero) or '1' (one).
-All the elements of ciphertexts will be distinct.
-There will exist at least one key that is consistent with the given plaintexts and ciphertexts.


EXAMPLES

0)
{"110", "001"}
{"101", "010"}

Returns: 2

The two possible keys are "011" and "100".

1)
{"00", "01", "10", "11"}
{"00", "01", "10", "11"}

Returns: 4



2)
{"01", "10"}
{"00"}

Returns: 2



3)
{"000", "111", "010", "101", "110", "001"}
{"011", "100"}

Returns: 6



#line 72 "NetworkXOneTimePad.cpp"
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

typedef long long LL;
typedef vector<LL> LLV;
typedef set<LL> LLS;

class NetworkXOneTimePad {
public:

	static long long ston(string s) {
		long long n = 0;
		size_t i;
		for (i = 0; i < s.length(); ++i) {
			n = (n << 1) | (s[i] != '0');
		}
		return n;
	}

	int crack(vector <string> plaintexts, vector <string> ciphertexts) {
		LLV p, c;
		LLS ps;
		size_t i, j;
		for (i = 0; i < plaintexts.size(); ++i) {
			LL n = ston(plaintexts[i]);
			p.push_back(n);
			ps.insert(n);
		}
		for (i = 0; i < ciphertexts.size(); ++i) {
			LL n = ston(ciphertexts[i]);
			c.push_back(n);
		}

		// key candidates
		LLS ks;
		for (i = 0; i < p.size(); ++i) {
			for (j = 0; j < c.size(); ++j) {
				ks.insert(p[i] ^ c[j]);
			}
		}

		// check if all of restored messages are in plaintexts
		int count = 0;
		LLS::const_iterator k;
		for (k = ks.begin(); k != ks.end(); ++k) {
			int ok = 1;
			for (i = 0; i < c.size(); ++i) {
				LL x = *k ^ c[i];
				if (ps.find(x) == ps.end()) {
					ok = 0;
					break;
				}
			}
			count += ok;
		}

		return count;
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

static void Test(const char *p, const char *c, int expected)
{
	vector <string> pv = getVector<string>(p);
	vector <string> cv = getVector<string>(c);
	NetworkXOneTimePad ___test;
	int result = ___test.crack(pv, cv);
	printf("result: %s, %d\n", result == expected ? "OK" : "FAILED", result);
}

int main() {
	Test("110,001", "101,010", 2);
	Test("00,01,10,11", "00,01,10,11", 4);
	Test("01,10", "00", 2);
	Test("000,111,010,101,110,001", "011,100", 6);

	return 0;
}
// END CUT HERE
