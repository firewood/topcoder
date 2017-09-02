// BEGIN CUT HERE
/*
2017 TCO Algorithm Warsaw Regional Round
Fun SRM Easy (250)

PROBLEM STATEMENT
Have you ever heard the following riddle?

A shop sells one chocolate for one euro.
It also exchanges three chocolate wrappers for a new chocolate.
You have 15 euro. How many chocolates can you eat?

It is said that 90% of the people cannot get the correct answer. Since you are not humans but topcoders,
Elly believes that 90% (or even more) of you can solve it. What did you get? The correct answer is 22.

Elly thinks that the problem has too many constants. One euro per chocolate.
Three wrappers for a new chocolate. Fifteen euro. It can be made so much more generic!
Now the girl has given you the following modified version:

A shop sells one chocolate for P euro.
It also exchanges K chocolate wrappers for a new chocolate.
You have N euro. How many chocolates can you eat?

Given the ints P, K, and N, return the maximum number of chocolates that can be eaten.


DEFINITION
Class:EllysChocolates
Method:getCount
Parameters:int, int, int
Returns:int
Method signature:int getCount(int P, int K, int N)


CONSTRAINTS
-P will be between 1 and 1,000, inclusive.
-K will be between 2 and 1,000, inclusive.
-N will be between 3 and 1,000,000, inclusive.


EXAMPLES

0)
1
3
15

Returns: 22

Elly buys 15 chocolates with the money she has, eats them, and gets 15 wrappers.
She then exchanges them for 5 new chocolates. After eating them as well, she has 5 wrappers, 3 of which she exchanges for a new chocolate. After eating it as well, she again has three wrappers, which she exchanges for one last chocolate.


1)
41
4
1337

Returns: 42


2)
666
13
823172

Returns: 1337


3)
666
222
444

Returns: 0

In this case even a single chocolate costs more than the money Elly has, so she's unable to buy any.

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class EllysChocolates {
public:
	int getCount(int P, int K, int N) {
		int ans = N / P;
		int w = ans;
		while (w >= K) {
			int g = w / K;
			ans += g;
			w %= K;
			w += g;
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
			int Arg0 = 1;
			int Arg1 = 3;
			int Arg2 = 15;
			int Arg3 = 22;

			verify_case(n, Arg3, getCount(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 41;
			int Arg1 = 4;
			int Arg2 = 1337;
			int Arg3 = 42;

			verify_case(n, Arg3, getCount(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 666;
			int Arg1 = 13;
			int Arg2 = 823172;
			int Arg3 = 1337;

			verify_case(n, Arg3, getCount(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 666;
			int Arg1 = 222;
			int Arg2 = 444;
			int Arg3 = 0;

			verify_case(n, Arg3, getCount(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EllysChocolates ___test;
	___test.run_test(-1);
}
// END CUT HERE
