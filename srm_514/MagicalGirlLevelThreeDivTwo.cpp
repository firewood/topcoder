// BEGIN CUT HERE
/*
// SRM 514 Div2 Hard (1000)

// PROBLEM STATEMENT
// Magical Girls are girls who have magical powers. They fight against
evil witches to protect the Earth.

You, one of the Magical Girls, are now fighting against an evil witch.
You want to use ultimate magic to defeat the witch. To use ultimate magic
you have to chant a magical spell. The spell is determined with a sequence A.

A is the sequence of strings which is determined with a sequence first.
Each element of first is a string which contains only '0' and '1'. Let K
be the number of elements in first. Each element of A is defined as follows:

for all i, 0 <= i < K, A[i] = first[i].
Otherwise, A[i] = A[i-1] + A[i-K-1] + A[i-2K-1] + ... (while i-m*K-1 is not
less than 0). Here operator '+' denotes concatenation of strings.

You are given three integers n, lo and hi. Let S be the substring of A[n]
from lo to hi, inclusive. That is, S = A[n][lo..hi] where both lo and hi are
0-based indices into A[n]. The spell you have to chant is S and the power
of the magic is equal to the number of '1's in S. Return the power of the
ultimate magic.


DEFINITION
Class:MagicalGirlLevelThreeDivTwo
Method:theCount
Parameters:vector <string>, int, long long, long long
Returns:int
Method signature:int theCount(vector <string> first, int n, long long lo, long long hi)


CONSTRAINTS
-first will contain between 1 and 50 elements, inclusive.
-Each element of first will contain between 1 and 50 characters, inclusive.
-Each element of first will consist of '0' (zero) and '1' (one).
-n will be between 0 and 100, inclusive.
-hi will be between 0 and min{1,000,000,000,000,000 (10^15), (length of A[n])-1}, inclusive.
-lo will be between 0 and hi, inclusive.
-hi-lo will be at most 1,000.


EXAMPLES

0)
{"101", "01"}
4
2
5

Returns: 2

A[2] = "01", A[3] = "01101", A[4] = "0110101"
S = A[4][2..5] = "1010"


1)
{"01", "10"}
5
4
5

Returns: 1

A[2] = "10", A[3] = "1001", A[4] = "100110", A[5] = "1001101001"
S = A[5][4..5] = "10"


2)
{"1", "11", "111"}
46
10000
11000

Returns: 1001


3)
{"0", "00", "000"}
46
10000
11000

Returns: 0


4)
{"00110110101101001111101101001011010011111011010010"}
100
999999999999915
1000000000000000

Returns: 50


5)
{"10000", "011011001011000001101000010100000111000110110", 
"000001010001011000001101110", "100100000110100001010000", 
"011011010", "01100000010101101110000011100011001000",
"0001010", "010011000", "000101001", "00", "1"}
91
123456
123654

Returns: 76

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;
typedef vector<string> StrVec;

#define MAX_N 100
#define MAX_LENGTH 1000000000000000LL

class MagicalGirlLevelThreeDivTwo {
	int K;
	StrVec First;
	LL Length[MAX_N+1];

	int get_magical_power(int index, LL pos) {
		if (index < K) {
			return First[index][pos] - '0';
		}
		int i;
		for (i = index - 1; i >= 0; i -= K) {
			LL len = Length[i];
			if (pos < len) {
				break;
			}
			pos -= len;
		}
		return get_magical_power(i, pos);
	}

public:
	int theCount(vector <string> first, int n, long long lo, long long hi) {
		K = (int)first.size();
		First = first;
		// generate length table
		memset(Length, 0, sizeof(Length));
		int i, j;
		for (i = 0; i <= n; ++i) {
			if (i < K) {
				Length[i] = first[i].length();
			} else {
				for (j = i-1; j >= 0; j -= K) {
					// ignore remain part exceeds length of 10**15
					Length[i] = min(MAX_LENGTH+1, Length[i] + Length[j]);
				}
			}
		}

		// summarize power of the ultimate magic
		int result = 0;
		LL x;
		for (x = lo; x <= hi; ++x) {
			result += get_magical_power(n, x);
		}
		return result;
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
			string Arr0[] = {"101", "01"};
			int Arg1 = 4;
			long long Arg2 = 2LL;
			long long Arg3 = 5LL;
			int Arg4 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg4, theCount(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"01", "10"};
			int Arg1 = 5;
			long long Arg2 = 4LL;
			long long Arg3 = 5LL;
			int Arg4 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg4, theCount(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"1", "11", "111"};
			int Arg1 = 46;
			long long Arg2 = 10000LL;
			long long Arg3 = 11000LL;
			int Arg4 = 1001;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg4, theCount(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"0", "00", "000"};
			int Arg1 = 46;
			long long Arg2 = 10000LL;
			long long Arg3 = 11000LL;
			int Arg4 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg4, theCount(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"00110110101101001111101101001011010011111011010010"};
			int Arg1 = 100;
			long long Arg2 = 999999999999915LL;
			long long Arg3 = 1000000000000000LL;
			int Arg4 = 50;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg4, theCount(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"10000", "011011001011000001101000010100000111000110110", 
"000001010001011000001101110", "100100000110100001010000", 
"011011010", "01100000010101101110000011100011001000",
"0001010", "010011000", "000101001", "00", "1"};
			int Arg1 = 91;
			long long Arg2 = 123456LL;
			long long Arg3 = 123654LL;
			int Arg4 = 76;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg4, theCount(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MagicalGirlLevelThreeDivTwo ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
