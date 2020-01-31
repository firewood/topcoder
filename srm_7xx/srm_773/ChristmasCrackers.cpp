// BEGIN CUT HERE
/*
SRM 773 Div2 Easy (250)

PROBLEM STATEMENT

A Christmas cracker is a festive table decoration that resembles an oversized sweet-wrapper.
The middle part of a cracker usually contains some small gift and a terrible Christmas pun.
("What does Santa feel when going down a narrow chimney? Claus-trophobia!")
It is customary that each cracker should be opened by two people.
Each person takes hold of one outer chamber and they pull in opposite directions, causing the cracker to split unevenly and leaving one person holding the central chamber and the prize.

N people (numbered 0 to N-1) are attending a Christmas party.
Each person would like to open at least K Christmas crackers.
What is the smallest total number C of crackers they need, and how should they open them?

You are given the ints N and K. Return a vector <int> with 2*C elements: for each cracker, the numbers of the two people who should open it. Any valid solution will be accepted.


DEFINITION
Class:ChristmasCrackers
Method:crack
Parameters:int, int
Returns:vector <int>
Method signature:vector <int> crack(int N, int K)


CONSTRAINTS
-N will be between 2 and 30, inclusive.
-K will be between 1 and 30, inclusive.


EXAMPLES

0)
2
3

Returns: {0, 1, 0, 1, 0, 1 }


Two people, each of them wants to open at least three crackers. The only optimal solution is obviously to use three crackers and have both people open each cracker. There are multiple ways to report this solution. E.g., {0, 1, 1, 0, 1, 0} would also be a correct answer.


Note that {0, 0, 0, 1, 1, 1} is not a correct answer. The first two elements of this array say that the first cracker should be opened by person 0 and person 0, and that is not allowed: two distinct people must open each cracker.


1)
5
1

Returns: {0, 3, 1, 2, 1, 4 }

If each of five people wants to open at least one cracker, we need at least three crackers. One person will open two crackers.

2)
3
4

Returns: {0, 1, 0, 1, 0, 2, 0, 2, 1, 2, 2, 1 }

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

class ChristmasCrackers {
public:
	vector <int> crack(int N, int K) {
		vector <int> ans;
		for (int i = 0; i < N * K; i += 2) {
			ans.push_back(i % N);
			ans.push_back((i + 1) % N);
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 3;
			int Arr2[] = {0, 1, 0, 1, 0, 1 };

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, crack(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 1;
			int Arr2[] = {0, 3, 1, 2, 1, 4 };

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, crack(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 4;
			int Arr2[] = {0, 1, 0, 1, 0, 2, 0, 2, 1, 2, 2, 1 };

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, crack(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ChristmasCrackers ___test;
	___test.run_test(-1);
}
// END CUT HERE
