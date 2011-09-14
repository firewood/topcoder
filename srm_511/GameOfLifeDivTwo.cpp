// BEGIN CUT HERE
/*
// SRM 511 Div2 Easy (250)
// PROBLEM STATEMENT
// Cat Taro and Rabbit Hanako invented a new variation of "Game Of Life".


N cells are arranged around a circle. The cells are numbered from 0 to N-1.
For each i between 0 and N-2, inclusive, the i-th cell and the (i+1)-th cell are adjacent to each other.
The (N-1)-th cell and the 0-th cell are adjacent to each other. Each cell has exactly two adjacent cells.
Each cell has a state: "live" or "die".


Taro and Hanako can decide the states of the cells at time 0. For time t > 0, the states are determined as follows:

Consider three cells: the i-th cell and the two cells that are adjacent to the i-th cell.
If at least two of the three cells are "live" at time t-1, the state of the i-th cell at time t will be "live".
If at least two of the three cells are "die" at time t-1, the state of the i-th cell at time t will be "die".

You are given a string init. The number of cells in the game (N) is equal to the number of characters in init.
The i-th character of init represents the state they assign to the i-th cell at time 0.
'1' means "live" and '0' means "die". Return a string that describes the states at time T using the same encoding.


DEFINITION
Class:GameOfLifeDivTwo
Method:theSimulation
Parameters:string, int
Returns:string
Method signature:string theSimulation(string init, int T)


CONSTRAINTS
-init will contain between 3 and 50 characters, inclusive.
-Each character in init will be '0' (zero) or '1' (one).
-T will be between 0 and 1,000, inclusive.


EXAMPLES

0)
"01010"
2

Returns: "00000"

At time 0, Taro and Hanako set the state to "01010".

At time 1, the state becomes "00100".

At time 2, the state becomes "00000".

1)
"010101"
5

Returns: "101010"

The state alternates between "010101" and "101010" repeatedly.

2)
"111010"
58

Returns: "111111"



3)
"111111111"
511

Returns: "111111111"

The state never changes.

4)
"110010000010111110010100001001"
1000

Returns: "110000000001111110000000000001"



5)
"00101110011"
0

Returns: "00101110011"



#line 89 "GameOfLifeDivTwo.cpp"
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

class GameOfLifeDivTwo {
	public:
	string theSimulation(string init, int T) {
		char A[64] = {0};
		char B[64] = {0};
		char *r = A;
		char *w = B;
		strncpy(A, init.c_str(), 60);
		int length = (int)init.length();
		int m = length - 1;
		while (--T >= 0) {
			char *_w = w;
			int i;
			for (i = 0; i < length; ++i) {
				char d = (i == 0) ? r[length - 1] : r[i - 1];
				char e = r[i];
				char f = (i == m) ? r[0] : r[i + 1];
				char g = (d - '0') + (e - '0') + (f - '0');
				*w++ = '0' + (g / 2);
			}
			w = r;
			r = _w;
		}
		return r;
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

static void Test(const char *seq, int T, const char *expected)
{
	vector <int> v = getVector<int>(seq);
	GameOfLifeDivTwo ___test;
	string result = ___test.theSimulation(seq, T);
	printf("result: %s, %s\n", strcmp(result.c_str(), expected) == 0 ? "OK" : "FAILED", result.c_str());
}

int main() {
	Test("01010", 2, "00000");
	Test("010101", 5, "101010");
	Test("111010", 58, "111111");
	Test("111111111", 511, "111111111");
	Test("110010000010111110010100001001", 1000, "110000000001111110000000000001");
	Test("00101110011", 0, "00101110011");
	return 0;
}
// END CUT HERE
