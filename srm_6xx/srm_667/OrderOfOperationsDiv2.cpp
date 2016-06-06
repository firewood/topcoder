// BEGIN CUT HERE
/*
SRM 667 Div2 Medium (500)

PROBLEM STATEMENT

Cat Noku has just finished writing his first computer program.
Noku's computer has m memory cells.
The cells have addresses 0 through m-1.
Noku's program consists of n instructions.
The instructions have mutually independent effects and therefore they may be executed in any order.
The instructions must be executed sequentially (i.e., one after another) and each instruction must be executed exactly once.

You are given a description of the n instructions as a vector <string> with n elements.
Each instruction is a string of m characters.
For each i, character i of an instruction is '1' if this instruction accesses memory cell i, or '0' if it does not.

Noku's computer uses caching, which influences the time needed to execute an instruction.
More precisely, executing an instruction takes k^2 units of time, where k is the number of new memory cells this instruction accesses.
(I.e., k is the number of memory cells that are accessed by this instruction but have not been accessed by any previously executed instruction.
Note that k may be zero, in which case the current instruction is indeed executed in 0 units of time.)

Noku's instructions can be executed in many different orders.
Clearly, different orders may lead to a different total time of execution.
Find and return the shortest amount of time in which it is possible to execute all instructions.


DEFINITION
Class:OrderOfOperationsDiv2
Method:minTime
Parameters:vector <string>
Returns:int
Method signature:int minTime(vector <string> s)


CONSTRAINTS
-n,m will be between 1 and 20, inclusive.
-s will have exactly n elements.
-Each element of s will have exactly m characters.
-Each character of s[i] will be either '0' or '1' for all valid i.


EXAMPLES

0)
{
 "111",
 "001",
 "010"
}

Returns: 3

Cat Noku has 3 instructions.
The first instruction ("111") accesses all three memory cells.
The second instruction ("001") accesses only memory cell 2.
The third instruction ("010") accesses only memory cell 1.
If Noku executes these three instructions in the given order, it will take 3^2 + 0^2 + 0^2 = 9 units of time.
However, if he executes them in the order "second, third, first", it will take only 1^2 + 1^2 + 1^2 = 3 units of time.
This is one optimal solution.
Another optimal solution is to execute the instructions in the order "third, second, first".


1)
{
 "11101",
 "00111",
 "10101",
 "00000",
 "11000"
}

Returns: 9


2)
{
  "11111111111111111111"
}

Returns: 400

A single instruction that accesses all 20 memory cells.


3)
{
  "1000",
  "1100",
  "1110"
}

Returns: 3


4)
{
  "111",
  "111",
  "110",
  "100"
}

Returns: 3

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

static inline int popcount(unsigned int b)
{
#ifdef __GNUC__
	return __builtin_popcount(b);
#elif _MSC_VER >= 1400
	return __popcnt(b);
#else
	b = (b & 0x55555555) + (b >> 1 & 0x55555555);
	b = (b & 0x33333333) + (b >> 2 & 0x33333333);
	b = (b & 0x0F0F0F0F) + (b >> 4 & 0x0F0F0F0F);
	b += b >> 8;
	b += b >> 16;
	return b & 0x3F;
#endif
}

class OrderOfOperationsDiv2 {
	int N;
	int W;
	int M[50];
	int m[1048576];

	void dfs(int bits, int cost) {
		m[bits] = cost;
		for (int i = 0; i < N; ++i) {
			int a = bits & M[i];
			if (a) {
				int cnt = popcount(a);
				int b = bits ^ a;
				int c = cost + cnt * cnt;
				if (m[b] > c) {
					dfs(b, c);
				}
			}
		}
	}

public:
	int minTime(vector <string> s) {
		N = 0;
		W = (int)s[0].length();
		int final_bits = 0;
		for (string a : s) {
			int c = 0;
			for (int i = 0; i < W; ++i) {
				c |= ((a[i] - '0') << i);
			}
			M[N++] = c;
			final_bits |= c;
		}
		memset(m, 0x3f, sizeof(m));
		dfs(final_bits, 0);
		return m[0];
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
			string Arr0[] = {
 "111",
 "001",
 "010"
};
			int Arg1 = 3;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minTime(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
 "11101",
 "00111",
 "10101",
 "00000",
 "11000"
};
			int Arg1 = 9;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minTime(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
  "11111111111111111111"
};
			int Arg1 = 400;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minTime(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
  "1000",
  "1100",
  "1110"
};
			int Arg1 = 3;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minTime(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
  "111",
  "111",
  "110",
  "100"
};
			int Arg1 = 3;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minTime(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	OrderOfOperationsDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
