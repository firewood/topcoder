// BEGIN CUT HERE
/*
SRM 594 Div2 Easy (250)

PROBLEM STATEMENT
Fox Ciel is now in high school.
The seats in her classroom are arranged into an n by m matrix.
The rows are numbered from 0 to n-1 (front to back) and the columns from 0 to m-1 (left to right).

At the beginning, Ciel can choose any of the seats.
Then, at the end of each week Ciel will shift one row to the back and one column to the right, wrapping around whenever necessary.
Formally, if her current seat is in row r and column c, then her seat next week will be the one in row ((r+1) modulo n) and column ((c+1) modulo m).

Fox Ciel now wonders whether she can sit in all the seats in the classroom if she follows the above procedure.
As we already mentioned, she can start in any of the seats.
Also, she can attend the school for as many weeks as she wants to.
Return "Possible" if she can sit in all the seats and "Impossible" otherwise.


DEFINITION
Class:FoxAndClassroom
Method:ableTo
Parameters:int, int
Returns:string
Method signature:string ableTo(int n, int m)


CONSTRAINTS
-n will be between 2 and 10, inclusive.
-m will be between 2 and 10, inclusive.


EXAMPLES

0)
2
3

Returns: "Possible"

We will use (r,c) to denote the chair at row r, column c.
Suppose Ciel starts at (1,0).
In the following weeks she will then sit at (0,1), (1,2), (0,0), (1,1), (0,2), (1,0) again, (0,1) again, and so on.
We can see that already after 6 weeks Ciel sat in all the seats.


1)
2
2

Returns: "Impossible"

Suppose that she starts at (0,0).
Then the next week she will sit at (1,1) and the week after that she will be back at (0,0).
She would never sit at (0,1) and (1,0).
Similarly we can show that none of the other starting positions work.


2)
4
6

Returns: "Impossible"


3)
3
6

Returns: "Impossible"


4)
5
7

Returns: "Possible"


5)
10
10

Returns: "Impossible"

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

class FoxAndClassroom {
public:
	string ableTo(int n, int m) {
		return gcd(n, m) == 1 ? "Possible" : "Impossible";
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
			int Arg1 = 3;
			string Arg2 = "Possible";

			verify_case(n, Arg2, ableTo(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 2;
			string Arg2 = "Impossible";

			verify_case(n, Arg2, ableTo(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 6;
			string Arg2 = "Impossible";

			verify_case(n, Arg2, ableTo(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 6;
			string Arg2 = "Impossible";

			verify_case(n, Arg2, ableTo(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 7;
			string Arg2 = "Possible";

			verify_case(n, Arg2, ableTo(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arg1 = 10;
			string Arg2 = "Impossible";

			verify_case(n, Arg2, ableTo(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FoxAndClassroom ___test;
	___test.run_test(0);
}
// END CUT HERE
