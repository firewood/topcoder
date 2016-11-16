// BEGIN CUT HERE
/*
SRM 702 Div2 Easy (250)

PROBLEM STATEMENT

Recently, Alice had to take a test.
The test consisted of a sequence of true/false questions.
Alice was completely unprepared for the test, so she just guessed each answer.

You are given the following inputs:

an int questions: the number of questions on the test.
an int guessed: the number of questions for which Alice guessed that the answer is "true".
an int actual: the actual number of questions for which the answer is "true".

In the test, each correct answer was worth 1 point and each incorrect answer was worth 0 points.
Compute the largest possible number of points Alice could have received.


DEFINITION
Class:TestTaking
Method:findMax
Parameters:int, int, int
Returns:int
Method signature:int findMax(int questions, int guessed, int actual)


CONSTRAINTS
-questions will be between 1 and 50, inclusive.
-guessed, actual will be between 0 and questions, inclusive.


EXAMPLES

0)
3
1
2

Returns: 2

The test consisted of 3 statements.
Alice guessed that 1 of them is true.
Actually, there were 2 true statements on the test.

There are multiple possible outcomes of the test.

For example, it is possible that Alice wrote down the sequence of answers (false,true,false), but the correct sequence of answers is (true,false,true). In this case Alice would have received 0 points.

One possible best scenario for Alice looks as follows: Alice guessed that the answers are (false,false,true), and the correct answers are (true,false,true). In this scenario Alice would have received 0+1+1 = 2 points.


1)
3
2
1

Returns: 2


2)
5
5
0

Returns: 0

Alice guessed five times "true", but all five correct answers were "false".
Thus, Alice certainly received 0 points.


3)
10
8
8

Returns: 10


4)
7
0
2

Returns: 5

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class TestTaking {
public:
	int findMax(int questions, int guessed, int actual) {
		return min(guessed, actual) + min(questions - guessed, questions - actual);
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
			int Arg0 = 3;
			int Arg1 = 1;
			int Arg2 = 2;
			int Arg3 = 2;

			verify_case(n, Arg3, findMax(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 2;
			int Arg2 = 1;
			int Arg3 = 2;

			verify_case(n, Arg3, findMax(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 5;
			int Arg2 = 0;
			int Arg3 = 0;

			verify_case(n, Arg3, findMax(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arg1 = 8;
			int Arg2 = 8;
			int Arg3 = 10;

			verify_case(n, Arg3, findMax(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 7;
			int Arg1 = 0;
			int Arg2 = 2;
			int Arg3 = 5;

			verify_case(n, Arg3, findMax(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TestTaking ___test;
	___test.run_test(-1);
}
// END CUT HERE
