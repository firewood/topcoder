// BEGIN CUT HERE
/*
SRM 680 Div2 Easy (250)

PROBLEM STATEMENT
Bear Limak loves algorithms, especially the ones with words and strings.

Limak's friend recently entered a programming competition and wrote a program.
The program contains a string constant s.
Limak would now like to challenge the program by making it exceed the time limit.
To do that, he must find two different characters in s that are as far apart as possible.

Formally, Limak must find two integers i and j with the following properties:

Both i and j must be valid indices into s. That is, both numbers must be between 0 and n-1, inclusive, where n is the length of s.
The characters s[i] and s[j] must be different.
The difference between i and j must be as large as possible.


You are given the string s.
If Limak cannot choose any integers with the required properties, return -1.
Otherwise, return the largest possible difference between i and j.


DEFINITION
Class:BearPair
Method:bigDistance
Parameters:string
Returns:int
Method signature:int bigDistance(string s)


CONSTRAINTS
-s will have between 2 and 50 characters, inclusive.
-Each character in s will be a lowercase English letter ('a' - 'z').


EXAMPLES

0)
"bear"

Returns: 3

Limak can choose the (0-based) indices 0 and 3.
We have s[0]='b' and s[3]='r', which are indeed two different letters.
The difference between the two indices is 3-0 = 3.


1)
"abcba"

Returns: 3

Here, one optimal solution is for Limak to choose the indices 1 and 4 (corresponding to 'b' and 'a', respectively).
Another optimal solution is to choose indices 0 and 3 (letters 'a' and 'b').
In both cases the difference is 3.


2)
"oooohyeahpotato"

Returns: 13


3)
"zzzzzzzzzzzzzzzzzzzzz"

Returns: -1

Here, Limak can't choose two indices with different letters.


4)
"qw"

Returns: 1


5)
"xxyyxyxyyyyyyxxxyxyxxxyxyxyyyyyxxxxxxyyyyyyyyxxxxx"

Returns: 47

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class BearPair {
public:
	int bigDistance(string s) {
		int ans = -1;
		for (int i = 0; i != s.length(); ++i) {
			for (int j = i + 1; j != s.length(); ++j) {
				if (s[i] != s[j]) {
					ans = max(ans, j - i);
				}
			}
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			string Arg0 = "bear";
			int Arg1 = 3;

			verify_case(n, Arg1, bigDistance(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abcba";
			int Arg1 = 3;

			verify_case(n, Arg1, bigDistance(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "oooohyeahpotato";
			int Arg1 = 13;

			verify_case(n, Arg1, bigDistance(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "zzzzzzzzzzzzzzzzzzzzz";
			int Arg1 = -1;

			verify_case(n, Arg1, bigDistance(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "qw";
			int Arg1 = 1;

			verify_case(n, Arg1, bigDistance(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "xxyyxyxyyyyyyxxxyxyxxxyxyxyyyyyxxxxxxyyyyyyyyxxxxx";
			int Arg1 = 47;

			verify_case(n, Arg1, bigDistance(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BearPair ___test;
	___test.run_test(-1);
}
// END CUT HERE
