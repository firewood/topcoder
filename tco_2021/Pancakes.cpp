// BEGIN CUT HERE
/*
TCO21 R1B Medium (350)

PROBLEM STATEMENT

You have a stove and P pancake pans.
The stove has enough heaters to use all pans at the same time.

You want to make N pancakes.
Each pancake must be cooked for exactly two minutes: one minute from one side and then one minute from the other side.

We will measure the time in minutes since you start cooking.
During each minute, each pan must either be unused or it must contain one of the pancakes.
If a pan contains a pancake, the bottom side of the pancake is being cooked.

We will assume that at the beginning/end of each minute you can instantly perform all the necessary actions: getting some pancakes into pans, taking some pancakes out of pans, and flipping some pancakes over (either in the same pan or into a different pan).

Produce one possible schedule to cook all N pancakes in as few minutes as possible.
Return the schedule as a vector <string>.
Each element should describe one minute.
Each element should have P characters: one for each pan.
Use the character '-' to denote an empty pan.
Use the first N English letters to describe the pancakes: the uppercase letter is one side being cooked and the corresponding lowercase letter the other side of the same pancake.
(See the examples.)

Any valid cooking schedule that minimizes the number of minutes needed will be accepted.


DEFINITION
Class:Pancakes
Method:makePancakes
Parameters:int, int
Returns:vector <string>
Method signature:vector <string> makePancakes(int N, int P)


CONSTRAINTS
-N will be between 1 and 26, inclusive.
-P will be between 1 and 26, inclusive.


EXAMPLES

0)
1
3

Returns: {"A--", "-a-" }

N = 1 means we want a single pancake.
P = 3 means we have three pans.

The preparation will take two minutes, because it's not possible to cook the pancake from both sides at the same time.
Having more than one pan does not help us. 
Two of the three pans will remain unused each minute.

In the example output we used a different pan during the second minute. 
This is allowed but not necessary. 
E.g., {"--a", "--A"} is another valid output for this test case, and in that output we use the same pan for both sides of the pancake.


1)
3
1

Returns: {"A", "c", "B", "C", "a", "b" }

We want three pancakes and we only have a single pan. This time the cooking will clearly take us six minutes.

Note that the order in which we cook does not matter. In particular, it is not necessary to cook both sides of a pancake immediately one after another. A pancake can sit and wait with just one side cooked for arbitrarily many minutes.


2)
5
4

Returns: {"bA-e", "ECad", "-BcD" }

Given four pans, a naive solution needs four minutes to prepare five pancakes: cook four of them from one side, then cook them from the other side, and in the next two minutes do the same with the fifth pancake.

However, if we are smart and schedule everything properly, it is possible to prepare five pancakes in only three minutes.

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class Pancakes {
public:
	vector <string> makePancakes(int N, int P) {
		vector <string> ans;
		vector<char> q;
		for (int i = 0; i < N; ++i) {
			q.emplace_back('A' + i);
		}
		for (int i = N; i < P; ++i) {
			q.emplace_back('-');
		}
		for (int i = 0; i < N; ++i) {
			q.emplace_back('a' + i);
		}
		for (int i = 0; i < q.size(); i += P) {
			string s;
			for (int j = 0; j < P; ++j) {
				char c = i + j >= q.size() ? '-' : q[i + j];
				s += c;
			}
			ans.emplace_back(s);
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 3;
			string Arr2[] = {"A--", "-a-" };

			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, makePancakes(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 1;
			string Arr2[] = {"A", "c", "B", "C", "a", "b" };

			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, makePancakes(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 4;
			string Arr2[] = {"bA-e", "ECad", "-BcD" };

			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, makePancakes(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 5;
			int Arg1 = 6;
			string Arr2[] = { "ABCDE-", "abcde-" };

			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, makePancakes(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Pancakes ___test;
	___test.run_test(-1);
}
// END CUT HERE
