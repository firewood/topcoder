// BEGIN CUT HERE
/*
TCO13 Round 1A Easy (250)

PROBLEM STATEMENT
Manao is building a new house. He already purchased a rectangular area where he will place the house.
The basement of the house should be built on a level ground, so Manao will have to level the entire area.
The area is leveled if the difference between the heights of its lowest and highest square meter is at most 1.
Manao wants to measure the effort he needs to put into ground leveling.

You are given a vector <string> area.
Each character in area denotes the height at the corresponding square meter of Manao's area.
Using 1 unit of effort, Manao can change the height of any square meter on his area by 1 up or down.
Return the minimum total effort he needs to put to obtain a leveled area.


DEFINITION
Class:HouseBuilding
Method:getMinimum
Parameters:vector <string>
Returns:int
Method signature:int getMinimum(vector <string> area)


CONSTRAINTS
-area will contain between 1 and 50 elements, inclusive.
-Each element of area will be between 1 and 50 characters long, inclusive.
-All elements of area will be of the same length.
-Each element of area will contain digits ('0'-'9') only.


EXAMPLES

0)
{"10",
 "31"}

Returns: 2

The given area is not leveled, because the minimum height is 0 and the maximum height is 3. Manao needs to reduce the height of lower left square by 2.


1)
{"54454",
 "61551"}

Returns: 7

In the optimal solution each square will have height either 4 or 5. To reach such a configuration, Manao should reduce the height of one square from 6 to 5, and increase the heights of two other squares from 1 to 4.


2)
{"989"}

Returns: 0

The area is already leveled.


3)
{"90"}

Returns: 8


4)
{"5781252",
 "2471255",
 "0000291",
 "1212489"}

Returns: 53

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class HouseBuilding {
public:
	int getMinimum(vector <string> area) {
		int ans = 2000000000;
		for (int i = 0; i < 9; ++i) {
			int sum = 0;
			for (int j = 0; j < (int)area.size(); ++j) {
				for (int k = 0; k < (int)area[j].length(); ++k) {
					int c = area[j][k]-'0';
					sum += min(abs(i-c), abs(i+1-c));
				}
			}
			ans = min(ans, sum);
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
			string Arr0[] = {"10",
 "31"};
			int Arg1 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMinimum(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"54454",
 "61551"};
			int Arg1 = 7;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMinimum(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"989"};
			int Arg1 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMinimum(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"90"};
			int Arg1 = 8;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMinimum(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"5781252",
 "2471255",
 "0000291",
 "1212489"};
			int Arg1 = 53;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMinimum(Arg0));
		}
		n++;


		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"0"};
			int Arg1 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMinimum(Arg0));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	HouseBuilding ___test;
	___test.run_test(-1);
}
// END CUT HERE
