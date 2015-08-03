// BEGIN CUT HERE
/*
SRM 664 Div2 Easy (250)

// PROBLEM STATEMENT
// Limak is an old brown bear.
Because of his bad eyesight he sometimes has to visit his doctor, Dr. Carrot.
Today is one such day.

Dr. Carrot has a blackboard in his office.
There is a number A written on the blackboard.
In order to examine Limak's eyesight, Dr. Carrot asked him to read the number.
Limak couldn't see the number really well.
He could determine the number of digits correctly, but he was not sure what the individual digits are.
Finally, he decided to announce the number B to the doctor.
The doctor then left the office for a short while.

Limak really doesn't want to wear glasses, so he has decided to cheat.
As soon as the doctor left the room, Limak went to the blackboard to read the correct number A.
Before the doctor returns, Limak has the time to change one of the digits of A to any different digit.
(Note that he may not add any new digits to A and he may not completely erase any digits of A.
He may only change at most one of the digits.)
Limak hopes that he can deceive the doctor by changing the number A into his number B.

You are given the ints A and B.
Return the string "happy" (quotes for clarity) if Limak can convince the doctor that his eyesight is good.
Otherwise, return the string "glasses".

DEFINITION
Class:BearCheats
Method:eyesight
Parameters:int, int
Returns:string
Method signature:string eyesight(int A, int B)


CONSTRAINTS
-A and B will be between 1 and 999,999, inclusive.
-A and B will have the same number of digits.


EXAMPLES

0)
8072
3072

Returns: "happy"

Limak wants to change 8072 into 3072. He can do that by changing the digit 8 to a 3.

1)
508
540

Returns: "glasses"

Limak would need to change two digits, but he only has the time to change at most one.

2)
854000
854000

Returns: "happy"

It is possible that Limak read the number correctly. If that happens, he will not change any digits.

3)
1
6

Returns: "happy"



4)
385900
123000

Returns: "glasses"



*/
// END CUT HERE
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class BearCheats {
	public:
	string eyesight(int A, int B) {
		char a[16], b[16];
		sprintf(a, "%d", A);
		sprintf(b, "%d", B);
		int len = strlen(a);
		if (len == strlen(b)) {
			int c = 0;
			for (int i = 0; i < len; ++i) {
				c += a[i] == b[i];
			}
			if (c >= len - 1) {
				return "happy";
			}
		}
		return "glasses";
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
			int Arg0 = 8072;
			int Arg1 = 3072;
			string Arg2 = "happy";

			verify_case(n, Arg2, eyesight(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 508;
			int Arg1 = 540;
			string Arg2 = "glasses";

			verify_case(n, Arg2, eyesight(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 854000;
			int Arg1 = 854000;
			string Arg2 = "happy";

			verify_case(n, Arg2, eyesight(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 6;
			string Arg2 = "happy";

			verify_case(n, Arg2, eyesight(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 385900;
			int Arg1 = 123000;
			string Arg2 = "glasses";

			verify_case(n, Arg2, eyesight(Arg0, Arg1));
		}
		n++;
	}
// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BearCheats ___test;
	___test.run_test(-1);
}
// END CUT HERE
