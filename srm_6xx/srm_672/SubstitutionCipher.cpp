// BEGIN CUT HERE
/*
SRM 672 Div2 Medium (500)

PROBLEM STATEMENT
Recently you learned about substitution ciphers.
This problem is about such a cipher.
All strings in this problem (both encrypted and decrypted ones) will consist of only uppercase English letters ('A'-'Z').

When encrypting text using a substitution cipher we choose a substitution table: a permutation p of the alphabet.
In other words, for each letter x in the alphabet we choose a letter p(x) that will be used to encode x.
This encoding must be one-to-one: if x and y are two different letters, the letters p(x) and p(y) chosen to encode them must also be different.

You decided to try it out: you chose some specific substitution table and used it to encrypt some strings.

At some later point in time you found an encrypted string y.
You believe it was encrypted using the substitution table you once had.
Sadly, you do not remember the substitution table anymore.
The only thing you remember about it is that when you used it to encrypt the string a you got the string b.
Is this information sufficient to decrypt y?

You are given the strings a, b, and y.
If it is possible to decrypt the string y, return the original string x that was encrypted into y.
(More precisely: If there is exactly one string x such that the same permutation table can be used to encrypt a into b and to encrypt x into y, return x.)
Otherwise, return an empty string.


DEFINITION
Class:SubstitutionCipher
Method:decode
Parameters:string, string, string
Returns:string
Method signature:string decode(string a, string b, string y)


CONSTRAINTS
-a will contain between 1 and 50 characters, inclusive.
-a and b will contain the same number of characters.
-It is guaranteed that b can be obtained from a by applying some substitution cipher.
-y will contain between 1 and 50 characters, inclusive.
-Each character in a, b, and y will be an uppercase English letter ('A'-'Z').


EXAMPLES

0)
"CAT"
"DOG"
"GOD"

Returns: "TAC"

By observing a and b we see that each C is encoded as a D, each A is encoded as an O, and each T is encoded as a G.
Formally, we have p(C)=D, p(A)=O, and p(T)=G.
This information is sufficient to determine that the encrypted string "GOD" must have been created from the plaintext string "TAC".


1)
"BANANA"
"METETE"
"TEMP"

Returns: ""

We do not know which character was encoded as the letter P.
Thus, there are multiple possiblities for the string x.
For example, x can be "NABC" or "NABD".


2)
"THEQUICKBROWNFOXJUMPSOVERTHELAZYHOG"
"UIFRVJDLCSPXOGPYKVNQTPWFSUIFMBAZIPH"
"DIDYOUNOTICESKIPPEDLETTER"

Returns: "CHCXNTMNSHBDRJHOODCKDSSDQ"

This test case is tricky.
Note that the letter E does occur in y but it does not occur in b.
However, in this specific case we can still determine that the letter E must be decrypted to a D.

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef set<int> IntSet;

class SubstitutionCipher {
public:
	string decode(string a, string b, string y) {
		IntSet p, q;
		for (int i = 'A'; i <= 'Z'; ++i) {
			p.insert(i);
			q.insert(i);
		}
		char table[256] = {};
		for (int i = 0; i != a.length(); ++i) {
			table[b[i]] = a[i];
			p.erase(a[i]);
			q.erase(b[i]);
		}
		if (p.size() == 1) {
			table[*q.begin()] = *p.begin();
		}
		string x;
		for (char c : y) {
			c = table[c];
			if (!c) {
				return "";
			}
			x += c;
		}
		return x;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			string Arg0 = "CAT";
			string Arg1 = "DOG";
			string Arg2 = "GOD";
			string Arg3 = "TAC";

			verify_case(n, Arg3, decode(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "BANANA";
			string Arg1 = "METETE";
			string Arg2 = "TEMP";
			string Arg3 = "";

			verify_case(n, Arg3, decode(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "THEQUICKBROWNFOXJUMPSOVERTHELAZYHOG";
			string Arg1 = "UIFRVJDLCSPXOGPYKVNQTPWFSUIFMBAZIPH";
			string Arg2 = "DIDYOUNOTICESKIPPEDLETTER";
			string Arg3 = "CHCXNTMNSHBDRJHOODCKDSSDQ";

			verify_case(n, Arg3, decode(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SubstitutionCipher ___test;
	___test.run_test(-1);
}
// END CUT HERE
