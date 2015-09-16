// BEGIN CUT HERE
/*
SRM 668 Div2 Easy (250)

PROBLEM STATEMENT
You are going to send a message to your friend.
The message is given as the string message.
To confuse potential eavesdroppers, you are going to scramble the message.

Scrambling of a message is performed using the vector <int> key.
If a letter is at the (0-based) position i in the original message, it will appear at the position key[i] in the scrambled message.
(The constraints given below guarantee that this process will produce a valid scrambled message.)

To make the encryption even more confusing, you are going to repeat the above process K times in a row.
Given message, key, and the int K, find and return the final encrypted message.


DEFINITION
Class:VerySecureEncryption
Method:encrypt
Parameters:string, vector <int>, int
Returns:string
Method signature:string encrypt(string message, vector <int> key, int K)


CONSTRAINTS
-N will be between 1 and 10, inclusive.
-message will contain N characters.
-Each character of message will be a lowercase English letter.
-key will contain N elements.
-Each element of key will be between 0 and N-1, inclusive.
-The elements of key will be distinct.
-K will be between 1 and 50, inclusive.


EXAMPLES

0)
"abc"
{1,2,0}
1

Returns: "cab"

The character 'a' will go from position 0 to position key[0]=1.
The character 'b' will go from position 1 to position key[1]=2.
The character 'c' will go from position 2 to position key[2]=0.


1)
"abcde"
{4, 3, 2, 1, 0}
1

Returns: "edcba"


2)
"abcde"
{4, 3, 2, 1, 0}
2

Returns: "abcde"

This is the same message and the same key as in example 1, but now K=2, so we scramble the message twice.
For this particular key we see that each scrambling reverses the order of letters, which means that the final message is the same as the original we started with.


3)
"uogcodlk"
{4, 3, 6, 2, 5, 1, 0, 7}
44

Returns: "goodluck"

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class VerySecureEncryption {
public:
	string encrypt(string message, vector <int> key, int K) {
		string m[2];
		m[0] = message, m[1] = message;
		for (int k = 0; k < K; ++k) {
			int prev = k & 1;
			int curr = prev ^ 1;
			for (int i = 0; i != message.length(); ++i) {
				m[curr][key[i]] = m[prev][i];
			}
		}
		return m[K & 1];
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
			string Arg0 = "abc";
			int Arr1[] = {1,2,0};
			int Arg2 = 1;
			string Arg3 = "cab";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, encrypt(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abcde";
			int Arr1[] = {4, 3, 2, 1, 0};
			int Arg2 = 1;
			string Arg3 = "edcba";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, encrypt(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abcde";
			int Arr1[] = {4, 3, 2, 1, 0};
			int Arg2 = 2;
			string Arg3 = "abcde";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, encrypt(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "uogcodlk";
			int Arr1[] = {4, 3, 6, 2, 5, 1, 0, 7};
			int Arg2 = 44;
			string Arg3 = "goodluck";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, encrypt(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	VerySecureEncryption ___test;
	___test.run_test(-1);
}
// END CUT HERE
