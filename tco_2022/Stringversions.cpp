// BEGIN CUT HERE
/*
TCO22 R1B Hard (800)

PROBLEM STATEMENT

Given an array A[0..n-1], an inversion is a pair of indices (i, j) such that i < j but A[i] > A[j].

Inversions are a measure of how sorted the array is. 
For example, an array of n distinct elements has no inversions at all when sorted in ascending order and the maximum number of inversions when sorted in descending order.

A string can be seen as an array of characters.
And as we can compare characters, we can extend the definition of inversions to strings.

For example, the string S = "hello" can be seen as the array S = { 'h', 'e', 'l', 'l', 'o' }.
The pair (0, 1) is an inversion because 0 < 1 while S[0] > S[1].
The pairs (0, 2) and (2, 3) are not inversions: in the first case 'h' < 'l' and in the second case 'l' = 'l'.
In fact, (0, 1) is the only inversion for this particular string.

You are given the length L and the desired number of inversions N.
We are interested in strings of length L that consist of lowercase English letters ('a'-'z') only.
Determine whether one of those strings contains exactly N inversions.
If yes, return any one such string.
If no, return the empty string instead.


DEFINITION
Class:Stringversions
Method:create
Parameters:int, int
Returns:string
Method signature:string create(int L, int N)


CONSTRAINTS
-L will be between 1 and 500, inclusive.
-N will be between 0 and L*(L-1)/2, inclusive.


EXAMPLES

0)
5
1

Returns: "hello"

We want a string of length 5 with exactly 1 inversion. As we saw in the problem statement, "hello" is one of many different strings with this property.


1)
7
0

Returns: "xxxxxxx"

We want a string of length 7 with no inversions at all. As shown by our example answer, a string with seven identical characters has this property. The string "pqrstxy" would also be an acceptable answer. The string "billowy" is probably the only meaningful 7-letter English word with this property.


2)
7
21

Returns: "sponged"

This is the maximum number of inversions a string of length 7 can have. Among valid English words the strings "sponged" and "wronged" have this property, but you can also return any other meaningless string with 21 inversions.


3)
27
351

Returns: ""

There are some arrays of length 27 with exactly 351 inversions. However, there is no string of 27 lowercase English letters with this property. (There are some strings of length 27 with 350 inversions.)

4)
25
152

Returns: "topcoderroundonesubroundb"

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

static uint32_t _x = 2463534242;
static void xorshift32_seed(uint32_t seed) { if (seed) _x = seed; }
static inline uint32_t xorshift32(void) { _x ^= (_x << 13); _x ^= (_x >> 17); _x ^= (_x << 15); return _x; }
static inline uint32_t _rand() { return xorshift32() >> 1; }

class BIT {
	std::vector<int64_t> bit;
	int64_t size;
public:
	BIT() { }
	BIT(int64_t sz) { init(sz); }
	void init(int64_t sz) {
		bit = std::vector<int64_t>((size = sz) + 1);
	}
	int64_t sum(int64_t i) {
		int64_t s = 0;
		while (i > 0) {
			s += bit[i];
			i -= i & -i;
		}
		return s;
	}
	void add(int64_t i, int64_t x) {
		while (i <= size) {
			bit[i] += x;
			i += i & -i;
		}
	}
};

int calc_inversion_number(const string& s) {
	int cnt = 0;
	BIT bit(30);
	for (int i = 0; i < s.length(); ++i) {
		cnt += i - bit.sum(1 + s[i] - 'a');
		bit.add(1 + s[i] - 'a', 1);
	}
	return cnt;
}

class Stringversions {

public:
	string create(int L, int N) {
		string ans;
		int rep = L / 26, cnt = 0, r = L - rep * 26;
		char ch = 'z' + 1;
		for (int i = 0; i < L; ++i) {
			if (--cnt <= 0) {
				--ch;
				cnt = rep + (r-- > 0);
			}
			ans += ch;
		}
		cnt = calc_inversion_number(ans);
		if (cnt < N) {
			return "";
		}

		for (int i = 0; i < L; ++i) {
			if (cnt < N + L - 1 - i) {
				break;
			}
			ans[i] = 'a';
			cnt = calc_inversion_number(ans);
		}

		int offset = max(0, L - 150), range = L - offset;
		while (cnt != N) {
			char &ch = ans[offset + (_rand() % range)];
			if (ch > 'a') {
				--ch;
				cnt = calc_inversion_number(ans);
				if (cnt < N) {
					++ch;
				}
			}
		}

		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, int Required, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received || Required == calc_inversion_number(Received)) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 1;
			string Arg2 = "hello";

			verify_case(n, Arg1, Arg2, create(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 7;
			int Arg1 = 0;
			string Arg2 = "xxxxxxx";

			verify_case(n, Arg1, Arg2, create(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 7;
			int Arg1 = 21;
			string Arg2 = "sponged";

			verify_case(n, Arg1, Arg2, create(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 27;
			int Arg1 = 351;
			string Arg2 = "";

			verify_case(n, Arg1, Arg2, create(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 25;
			int Arg1 = 152;
			string Arg2 = "topcoderroundonesubroundb";

			verify_case(n, Arg1, Arg2, create(Arg0, Arg1));
		}
		n++;



		if ((Case == -1) || (Case == n)) {
			int Arg0 = 500;
			int Arg1 = 0;
			string Arg2 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";

			verify_case(n, Arg1, Arg2, create(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 500;
			int Arg1 = 1234;
			string Arg2 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaadddcccccccccbcccccbcbbbbbbbbbbbbbbbbbbaaaaaaaaaaaaaaaaaaaaaa";

			verify_case(n, Arg1, Arg2, create(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 500;
			int Arg1 = 118482;
			string Arg2 = "a";

			verify_case(n, Arg1, Arg2, create(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 488;
			int Arg1 = 74814;
			string Arg2 = "a";

			verify_case(n, Arg1, Arg2, create(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 429;
			int Arg1 = 2453;
			string Arg2 = "a";

			verify_case(n, Arg1, Arg2, create(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 385;
			int Arg1 = 12726;
			string Arg2 = "a";

			verify_case(n, Arg1, Arg2, create(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 369;
			int Arg1 = 39737;
			string Arg2 = "a";

			verify_case(n, Arg1, Arg2, create(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 59;
			int Arg1 = 471;
			string Arg2 = "a";

			verify_case(n, Arg1, Arg2, create(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 36;
			int Arg1 = 440;
			string Arg2 = "a";

			verify_case(n, Arg1, Arg2, create(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Stringversions ___test;
	___test.run_test(-1);
}
// END CUT HERE
