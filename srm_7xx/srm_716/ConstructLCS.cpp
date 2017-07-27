// BEGIN CUT HERE
/*
SRM 716 Div1 Easy (250)

PROBLEM STATEMENT
A string S is a subsequence of a string T if we can obtain S from T by erasing some (possibly all or none) of its characters. For example, "000" is a subsequence of "01010".

The longest common subsequence (LCS) of two strings A and B is a string C that is a subsequence of each of them and has the largest length among all strings with this property. Let f(A,B) be the length of the LCS of strings A and B. For example, we have f("101", "111000") = 2, f("101", "110011") = 3, and f("00", "1111") = 0.

You are given three small positive integers ab, bc, and ca.
Please find three strings A, B, C such that:

Each of the strings contains only the characters '0' and '1'.
The length of each string is between 1 and 1,000, inclusive.
f(A, B) = ab
f(B, C) = bc
f(C, A) = ca

Return a string formed as follows: A + " " + B + " " + C.
(I.e., the returned string should contain the three strings A, B, C, separated by single spaces.)

You may assume that a solution always exist.
If there are multiple solutions you may return any of them.


DEFINITION
Class:ConstructLCS
Method:construct
Parameters:int, int, int
Returns:string
Method signature:string construct(int ab, int bc, int ca)


CONSTRAINTS
-ab will be between 1 and 50, inclusive.
-bc will be between 1 and 50, inclusive.
-ca will be between 1 and 50, inclusive.


EXAMPLES

0)
3
4
2

Returns: "101 1010101 1111"

The returned string corresponds to the following solution:

A = "1111"
B = "101"
C = "1010101"

We can easily verify that the only LCS of A and B is "11", the only LCS of B and C is "101", and the only LCS of C and A is "1111".


1)
7
4
4

Returns: "10101010 1010101 1011"

There are other solutions like: A = "1110000", B = "1110000", C = "0000".


2)
8
7
8

Returns: "110101001011 010101101 10101010"


3)
8
6
7

Returns: "110101010 10101010 1111010"


4)
15
17
19

Returns: "000100101101111011000 11110111010011101010 100100001010101001010101000011111"


5)
50
50
50

Returns: "11111111111111111111111111111111111111111111111111 11111111111111111111111111111111111111111111111111 11111111111111111111111111111111111111111111111111"

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef pair<int, int> II;

class ConstructLCS {
public:
	string construct(int ab, int bc, int ca) {
		int abc[3] = { ab,bc,ca };
		sort(abc, abc + 3);
		II v[3];
		v[0].first = abc[2];
		v[1].first = abc[0];
		v[1].second = abc[1] - abc[0];
		v[2].first = abc[2];
		v[2].second = abc[1] - abc[0];
		int seq[3] = { 0,1,2 };
		do {
			if (min(v[seq[0]].first, v[seq[1]].first) + min(v[seq[0]].second, v[seq[1]].second) == ab &&
				min(v[seq[1]].first, v[seq[2]].first) + min(v[seq[1]].second, v[seq[2]].second) == bc &&
				min(v[seq[2]].first, v[seq[0]].first) + min(v[seq[2]].second, v[seq[0]].second) == ca) {
				break;
			}
		} while (next_permutation(seq, seq + 3));
		string ans;
		for (int i = 0; i < 3; ++i) {
			if (i) {
				ans += " ";
			}
			ans += string(v[seq[i]].first, '0');
			ans += string(v[seq[i]].second, '1');
		}
		return ans;
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
			int Arg0 = 3;
			int Arg1 = 4;
			int Arg2 = 2;
			string Arg3 = "101 1010101 1111";

			verify_case(n, Arg3, construct(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 7;
			int Arg1 = 4;
			int Arg2 = 4;
			string Arg3 = "10101010 1010101 1011";

			verify_case(n, Arg3, construct(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 8;
			int Arg1 = 7;
			int Arg2 = 8;
			string Arg3 = "110101001011 010101101 10101010";

			verify_case(n, Arg3, construct(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 8;
			int Arg1 = 6;
			int Arg2 = 7;
			string Arg3 = "110101010 10101010 1111010";

			verify_case(n, Arg3, construct(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 15;
			int Arg1 = 17;
			int Arg2 = 19;
			string Arg3 = "000100101101111011000 11110111010011101010 100100001010101001010101000011111";

			verify_case(n, Arg3, construct(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 50;
			int Arg1 = 50;
			int Arg2 = 50;
			string Arg3 = "11111111111111111111111111111111111111111111111111 11111111111111111111111111111111111111111111111111 11111111111111111111111111111111111111111111111111";

			verify_case(n, Arg3, construct(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ConstructLCS ___test;
	___test.run_test(-1);
}
// END CUT HERE
