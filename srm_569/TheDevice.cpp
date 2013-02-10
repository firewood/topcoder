// BEGIN CUT HERE
/*
SRM 569 Div1 Easy (250)

PROBLEM STATEMENT
Manao works at a laboratory on a highly classified project.
From time to time, he is given a special device and has to determine its exact structure.
Every such device operates on special plates. There are M bits written on each of the plates from left to right.
The device has two inputs and a screen. Each input requires a plate.
When two plates are connected to the device, M bits of output appear on the screen.
Each bit of output is either a binary OR, AND or XOR of the corresponding bits of the input plates.
Manao's task is to determine what operation is carried out for each of the bits.

Manao has N plates.
He is going to test the device on each possible pair of these plates and determine its structure by the outputs on the screen.
It might be that the plates Manao has are not enough to uniquely identify every possible device.
You are given vector <string> plates, where each element describes a plate Manao has. Return the minimum number of additional plates Manao needs to be able to determine the structure of any device.


DEFINITION
Class:TheDevice
Method:minimumAdditional
Parameters:vector <string>
Returns:int
Method signature:int minimumAdditional(vector <string> plates)


CONSTRAINTS
-plates will contain between 1 and 50 elements, inclusive.
-Each element of plates will be between 1 and 50 characters long, inclusive.
-All elements of plates will be of equal length.
-Each element of plates will contain characters from the set {'0', '1'} only.


EXAMPLES

0)
{"010",
 "011",
 "101"}

Returns: 1

It is possible to find two different devices such that no pair of Manao's plates will distinguish between them.
To fix this it is sufficient to add one more plate. An example of such a plate is "101". There are also other plates that would work in its place.


1)
{"0",
 "1",
 "0",
 "1"}

Returns: 0

With these plates, Manao can test the output for every possible pair of bits, which allows him to distinguish between AND, OR and XOR.


2)
{"01010101",
 "10101010"}

Returns: 1


3)
{"10010101011",
 "00010101001",
 "00100010111",
 "00101010101",
 "01010111101"}

Returns: 1


4)
{"1101001011010",
 "0010000010101",
 "1010101011110",
 "1101010100111",
 "1011111110111"}

Returns: 0

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class TheDevice {
public:
	int minimumAdditional(vector <string> plates) {
		int ans = 0;
		for (size_t i = 0; i < plates[0].length(); ++i) {
			int c[2] = {};
			for (size_t j = 0; j < plates.size(); ++j) {
				c[plates[j][i] - '0']++;
			}
			ans = max(ans, 3 - min(1, c[0]) - min(2, c[1]));
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
			string Arr0[] = {"010",
 "011",
 "101"};
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimumAdditional(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"0",
 "1",
 "0",
 "1"};
			int Arg1 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimumAdditional(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"01010101",
 "10101010"};
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimumAdditional(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"10010101011",
 "00010101001",
 "00100010111",
 "00101010101",
 "01010111101"};
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimumAdditional(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"1101001011010",
 "0010000010101",
 "1010101011110",
 "1101010100111",
 "1011111110111"};
			int Arg1 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimumAdditional(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TheDevice ___test;
	___test.run_test(-1);
}
// END CUT HERE
