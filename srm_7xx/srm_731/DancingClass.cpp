// BEGIN CUT HERE
/*
SRM 731 Div2 Medium (500)

PROBLEM STATEMENT
Hero is going to give a dancing class.
Exactly n students already signed up for the class.
Hero doesn't know the genders of those students, so he makes the simplifying assumption that each student is either a boy or a girl with equal probability, and that these random choices are mutually independent.

During the class there will be k times when Hero needs to choose one boy and one girl for the demonstration of a new dance move.
Hero is happy if he is able to choose k distinct boy-girl pairs for those demonstrations.
(The same person can be chosen multiple times, as long as it is always with a different partner.)

Hero now wonders what is the probability that he will be happy.
Return "High" if the probability is strictly more than 50%, "Low" if it is strictly less than 50%, and "Equal" if it is exactly 50%.
Note that the return value is case-sensitive.


DEFINITION
Class:DancingClass
Method:checkOdds
Parameters:int, int
Returns:string
Method signature:string checkOdds(int n, int k)


CONSTRAINTS
-n will be between 1 and 500, inclusive.
-k will be between 1 and 500, inclusive.


EXAMPLES

0)
2
1

Returns: "Equal"

There are n=2 participants and Hero needs to choose k=1 boy-girl pair.

With probability 50% one participant is a boy and the other is a girl, which will make Hero happy.

With probability 50% both participants have the same gender, and in that case Hero will be unhappy.
Hence, the probability that Hero will be happy is exactly 50 percent.


1)
3
2

Returns: "High"

Now there are three participants and Hero needs to form two distinct boy-girl pairs.

With probability 1/8 all three participants are boys, and with probability 1/8 all three of them are girls.
In those cases Hero will be unhappy.
In all remaining cases Hero can form exactly two pairs, which is enough to make him happy.

Thus, the probability of Hero being happy is 3/4, and therefore we should return "High".


2)
4
4

Returns: "Low"


3)
500
500

Returns: "High"


4)
40
397

Returns: "Low"


5)
1
1

Returns: "Low"

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class DancingClass {
	long double check(int n, int k) {
		static const int COMBSZ = 501;
		long double C[COMBSZ][COMBSZ] = { 1 };
		for (int i = 1; i < COMBSZ; ++i) {
			C[i][0] = 1;
			for (int j = 1; j <= i; ++j) {
				C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
			}
		}

		long double tot = 0;
		long double base = pow(2, -n);
		for (int boys = 0; boys <= n; ++boys) {
			int girls = n - boys;
			if (boys * girls >= k) {
				tot += base * C[n][boys];
			}
		}
		return tot;
	}

public:
	string checkOdds(int n, int k) {
		long double res = check(n, k);
		if (fabs(res - 0.5) < 1e-9) {
			return "Equal";
		} else {
			return res < 0.5 ? "Low" : "High";
		}
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
			int Arg0 = 2;
			int Arg1 = 1;
			string Arg2 = "Equal";

			verify_case(n, Arg2, checkOdds(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 2;
			string Arg2 = "High";

			verify_case(n, Arg2, checkOdds(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 4;
			string Arg2 = "Low";

			verify_case(n, Arg2, checkOdds(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 500;
			int Arg1 = 500;
			string Arg2 = "High";

			verify_case(n, Arg2, checkOdds(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 40;
			int Arg1 = 397;
			string Arg2 = "Low";

			verify_case(n, Arg2, checkOdds(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 1;
			string Arg2 = "Low";

			verify_case(n, Arg2, checkOdds(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DancingClass ___test;
	___test.run_test(-1);
}
// END CUT HERE
