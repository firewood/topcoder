// BEGIN CUT HERE
/*
SRM 643 Div2 Easy (250)

PROBLEM STATEMENT

The King of Byteland has an army that consists of R*C soldiers.
He has just arranged the soldiers into a grid with R rows and C columns.
Two soldiers are neighbors if they stand next to each other in a row or in a column.

Each of the soldiers is currently either happy or sad.
You are given their current states in a vector <string> state with R elements, each containing C characters.
The character state[i][j] is either 'H' (if the soldier in row i, column j is happy) or 'S' (if that soldier is sad).

Happiness is contagious.
Whenever two neighbors are both happy, they will tell each other jokes and after a minute that will make all of their neighbors happy as well.

Here's an example.
There are two happy neighbors among many sad soldiers:

{"SSSSS",
 "SSHHS",
 "SSSSS"}

This is the situation after one minute: all of their neighbors are happy now.

{"SSHHS",
 "SHHHH",
 "SSHHS"}

And this is the situation after another minute. Now all the neighbors of the soldiers that are currently happy became happy as well.

{"SHHHH",
 "HHHHH",
 "SHHHH"}

After another minute, all the soldiers in the King's army would be happy.

The King wants all his soldiers to be happy.
Sometimes it's easy, as in the above example: all he has to do is wait for a while and all soldiers will become happy.
However, it is not always the case.
For example, in the situation below the happiness would not spread anywhere, each soldier would remain in his original state forever.
(Note that a single happy soldier does not make his neighbors happy.)

{"SSSSS",
 "SSHSH",
 "HSSSS"}

The King can make a soldier happy by giving him an award for excellent service.
Obviously, the King could make all soldiers happy by giving awards to all of them.
But the King is smart and knows that there is a better solution.
He will only give the awards to a few carefully selected soldiers and then he will simply wait until the happiness spreads to the rest of the army.

You are given the vector <string> state.
Compute and return the smallest number of awards the king has to give to make all soldiers happy in the end.


DEFINITION
Class:TheKingsArmyDiv2
Method:getNumber
Parameters:vector <string>
Returns:int
Method signature:int getNumber(vector <string> state)


CONSTRAINTS
-state will contain between 3 and 50 elements, inclusive.
-Each element of state will contain between 3 and 50 characters, inclusive.
-Each element of state will contain the same number of characters.
-Each character in each element of state will be either 'H' or 'S'.


EXAMPLES

0)
{"SSSSS",
 "SSHHS",
 "SSSSS"}

Returns: 0

This is the first example in the problem statement. No awards are necessary, all soldiers will become happy anyway.


1)
{"SSSSS",
 "SSHSH",
 "HSSSS"}

Returns: 1

This is the second example in the problem statement. The King needs to give at least one award. One optimal solution is to give an award to the soldier in row 1, column 3. (Both indices are 0-based.)


2)
{"SSS",
 "SSS",
 "SSS"}

Returns: 2

Here the King must give awards to two soldiers.


3)
{"HSHSHSH", "SSSHSSS", "SSHSHSS", "SHSHSHS"}

Returns: 1


4)
{"HHSH", "HHHS", "HSSS", "SHSH", "HHHS", "HSHH", "SSSH"}

Returns: 0

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class TheKingsArmyDiv2 {
public:
	int getNumber(vector <string> state) {
		int H = (int)state.size(), W = (int)state[0].length();
		int ans = 2;
		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				if (state[i][j] == 'H') {
					ans = 1;
					if (j > 0 && state[i][j - 1] == 'H') {
						return 0;
					}
					if (i > 0 && state[i - 1][j] == 'H') {
						return 0;
					}
				}
			}
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
			string Arr0[] = {"SSSSS",
 "SSHHS",
 "SSSSS"};
			int Arg1 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"SSSSS",
 "SSHSH",
 "HSSSS"};
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"SSS",
 "SSS",
 "SSS"};
			int Arg1 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"HSHSHSH", "SSSHSSS", "SSHSHSS", "SHSHSHS"};
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"HHSH", "HHHS", "HSSS", "SHSH", "HHHS", "HSHH", "SSSH"};
			int Arg1 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TheKingsArmyDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
