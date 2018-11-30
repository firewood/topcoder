// BEGIN CUT HERE
/*
SRM 742 Div2 Easy (250)

PROBLEM STATEMENT

Elisa is a primary school student. Tomorrow it's her birthday!

In Elisa's country it is customary that when it's your birthday, you are supposed to bring candy for everyone.
Hence, Elisa's mother is now taking Elisa to buy a bag of candy for tomorrow.

Social protocol dictates that candy is always given out to classmates using the following algorithm:

repeat:
    if there is still enough candy for everyone (including you):
        give everyone else one candy
        take one candy for yourself
    else:
        stop (and you get to keep the candy that remained in the bag)

You know that there are K other kids in Elisa's class.

The store carries different brands of candy. You are given their description in the vector <int> candy.
Each element of candy is the number of pieces of candy in one of the bags available at the store.
Find out which bag should Elisa choose if she wants the most candy for herself.
Return the number of pieces of candy she will get to keep if she chooses the bag wisely.


DEFINITION
Class:BirthdayCandy
Method:mostCandy
Parameters:int, vector <int>
Returns:int
Method signature:int mostCandy(int K, vector <int> candy)


CONSTRAINTS
-K will be between 1 and 50, inclusive.
-candy will have between 1 and 50 elements, inclusive.
-Each element of candy will be between 1 and 1000, inclusive.


EXAMPLES

0)
9
{23, 7}

Returns: 7

If Elisa buys the bag with 23 candies, the following will happen:

23 is enough to give everyone a candy, so she gives everyone else a candy and then takes one herself.
13 is enough to give everyone a candy, so she gives everyone else a candy and then takes one herself.
3 is no longer enough to give everyone a candy, so she keeps the remaining 3 candies.

In total, she would have 1+1+3 = 5 candies.
On the other hand, if she buys the bag with 7 candies, she will get to keep all of them.


1)
1
{1, 2}

Returns: 1

Here it does not matter which bag Elisa buys. In either case she will end with a single candy.


2)
4
{43, 81, 17, 1, 9}

Returns: 17


3)
6
{7}

Returns: 1

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class BirthdayCandy {
public:
	int mostCandy(int K, vector <int> candy) {
		int ans = 0;
		for (int c : candy) {
			ans = max(ans, c / (K + 1) + (c % (K + 1)));
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
			int Arg0 = 9;
			int Arr1[] = {23, 7};
			int Arg2 = 7;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, mostCandy(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arr1[] = {1, 2};
			int Arg2 = 1;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, mostCandy(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arr1[] = {43, 81, 17, 1, 9};
			int Arg2 = 17;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, mostCandy(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			int Arr1[] = {7};
			int Arg2 = 1;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, mostCandy(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BirthdayCandy ___test;
	___test.run_test(-1);
}
// END CUT HERE
