// BEGIN CUT HERE
/*
SRM 761 Div2 Easy (250)

PROBLEM STATEMENT

Peter was recently on a holiday.
The holiday lasted for totalDays days.
Peter remembers that exactly rainyDays of them were rainy and the others were sunny.

We will use the letters 'R' and 'S' to represent rainy and sunny days.
For example, the string "SSSRSS" represents a 6-day holiday during which day 4 was rainy and the other five days were sunny.

We say that the beauty of the holiday is the maximal number of consecutive sunny days during the holiday.
For example, the beauty of "SSSRSS" is 3 and the beauty of "RRR" is 0.

Given totalDays and rainyDays, determine the smallest possible beauty of Peter's holiday.
Then, construct and return one string that represents such a holiday.

(The returned string should have the correct number of days, it should have the correct number of rainy days, and its beauty must be the smallest among all such strings. If there are multiple optimal solutions, you may return any one of them.)


DEFINITION
Class:Sunshine
Method:weatherReport
Parameters:int, int
Returns:string
Method signature:string weatherReport(int totalDays, int rainyDays)


CONSTRAINTS
-totalDays will be between 1 and 2000, inclusive.
-rainyDays will be between 0 and totalDays, inclusive.


EXAMPLES

0)
6
1

Returns: "SSSRSS"

The example from the problem statement. Another correct answer is "SSRSSS".


1)
3
3

Returns: "RRR"

Another example from the problem statement. This is the only correct answer.


2)
12
8

Returns: "RRSRRSRSRRRS"


3)
8
2

Returns: "SSRSSRSS"


4)
5
0

Returns: "SSSSS"

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

class Sunshine {
public:
	string weatherReport(int totalDays, int rainyDays) {
		string ans;
		int s = totalDays - rainyDays;
		if (s > 0) {
			int div = min(s, rainyDays + 1);
			int per = s / div;
			int r = s - per * div;
			for (int i = 0; i < div; ++i) {
				int cnt = per + (i < r);
				ans += string(cnt, 'S');
				if (rainyDays > 0) {
					ans += 'R';
					--rainyDays;
				}
			}
		}
		ans += string(rainyDays, 'R');
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
			int Arg0 = 6;
			int Arg1 = 1;
			string Arg2 = "SSSRSS";

			verify_case(n, Arg2, weatherReport(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 3;
			string Arg2 = "RRR";

			verify_case(n, Arg2, weatherReport(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 12;
			int Arg1 = 8;
			string Arg2 = "RRSRRSRSRRRS";

			verify_case(n, Arg2, weatherReport(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 8;
			int Arg1 = 2;
			string Arg2 = "SSRSSRSS";

			verify_case(n, Arg2, weatherReport(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 0;
			string Arg2 = "SSSSS";

			verify_case(n, Arg2, weatherReport(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 50;
			int Arg1 = 14;
			string Arg2 = "SSSRSSSRSSSRSSSRSSSRSSSRSSRSSRSSRSSRSSRSSRSSRSSRSS";

			verify_case(n, Arg2, weatherReport(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 50;
			int Arg1 = 15;
			string Arg2 = "SSSRSSSRSSSRSSRSSRSSRSSRSSRSSRSSRSSRSSRSSRSSRSSRSS";

			verify_case(n, Arg2, weatherReport(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Sunshine ___test;
	___test.run_test(-1);
}
// END CUT HERE
