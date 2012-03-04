// BEGIN CUT HERE
/*
// SRM 535 Div2 Easy (250)

// PROBLEM STATEMENT
// Fox Jiro and Eel Saburo are good friends. One day Jiro received a letter
from Saburo. The letter contains four integers representing an encrypted
message. Please help Jiro to decrypt the message.

You are given four ints: AminusB, BminusC, AplusB, and BplusC.
Your task is to find three integers A, B, and C such that:

AminusB = A - B
BminusC = B - C
AplusB = A + B
BplusC = B + C

There is always at most one triplet of integers A, B, C that satisfies
all four equalities.

If it exists, return a vector <int> with exactly three elements: { A, B, C }.
If there are no such integers, return an empty vector <int> instead.


DEFINITION
Class:FoxAndIntegers
Method:get
Parameters:int, int, int, int
Returns:vector <int>
Method signature:vector <int> get(int AminusB, int BminusC, int AplusB, int BplusC)


CONSTRAINTS
-AminusB will be between -30 and 30, inclusive.
-BminusC will be between -30 and 30, inclusive.
-AplusB will be between -30 and 30, inclusive.
-BplusC will be between -30 and 30. inclusive.


EXAMPLES

0)
1
-2
3
4

Returns: {2, 1, 3 }

A - B = 2 - 1 = 1
B - C = 1 - 3 = -2
A + B = 2 + 1 = 3
B + C = 1 + 3 = 4

1)
0
0
5
5

Returns: { }

A = B = C = 2.5 satisfy all four equalities, but A, B, and C must all be integers.

2)
10
-23
-10
3

Returns: {0, -10, 13 }

A, B, and C may be negative or zero.

3)
-27
14
13
22

Returns: { }



4)
30
30
30
-30

Returns: {30, 0, -30 }

*/
// END CUT HERE
#include <cmath>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;
typedef vector<int> IntVec;
typedef vector<LL> LLVec;
typedef vector<string> StrVec;
typedef set<int> IntSet;
typedef set<LL> LLSet;
typedef set<string> StrSet;
typedef set<int, int> IntMap;
typedef set<LL, LL> LLMap;
typedef set<string, string> StrMap;

class FoxAndIntegers {

public:
	vector <int> get(int AminusB, int BminusC, int AplusB, int BplusC) {
		vector <int> res;
		int a = AminusB + AplusB;
		int b = BminusC + BplusC;
		int c = -BminusC + BplusC;
		if ((abs(a)%2)==0 && (abs(b)%2) == 0 && (abs(c)%2) == 0 &&
				a-b == 2*AminusB && b-c == 2*BminusC && a+b == 2*AplusB && b+c == 2*BplusC) {
			res.push_back(a/2);
			res.push_back(b/2);
			res.push_back(c/2);
		}
		return res;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = -2;
			int Arg2 = 3;
			int Arg3 = 4;
			int Arr4[] = {2, 1, 3 };

			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			verify_case(n, Arg4, get(Arg0, Arg1, Arg2, Arg3));
		}
		n++;


		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 0;
			int Arg1 = 0;
			int Arg2 = 5;
			int Arg3 = 5;
//			int Arr4[] = { };
			int Arr4[] = { 1 };

			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			verify_case(n, Arg4, get(Arg0, Arg1, Arg2, Arg3));
		}
		n++;


		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arg1 = -23;
			int Arg2 = -10;
			int Arg3 = 3;
			int Arr4[] = {0, -10, 13 };

			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			verify_case(n, Arg4, get(Arg0, Arg1, Arg2, Arg3));
		}
		n++;


		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = -27;
			int Arg1 = 14;
			int Arg2 = 13;
			int Arg3 = 22;
//			int Arr4[] = { };
			int Arr4[] = { 1 };

			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			verify_case(n, Arg4, get(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 30;
			int Arg1 = 30;
			int Arg2 = 30;
			int Arg3 = -30;
			int Arr4[] = {30, 0, -30 };

			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			verify_case(n, Arg4, get(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FoxAndIntegers ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
