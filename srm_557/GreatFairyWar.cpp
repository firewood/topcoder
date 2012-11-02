// BEGIN CUT HERE
/*
// SRM 557 Div2 Easy (250)

// PROBLEM STATEMENT
// You are a wizard.
You are facing N fairies, numbered 0 through N-1.
Your goal is to defeat all of them.
You can only attack one fairy at a time.
Moreover, you must fight the fairies in order: you can only attack fairy X+1 after you defeat fairy X.
On the other hand, all fairies that have not been defeated yet will attack you all the time.

Each fairy has two characteristics: her damage per second (dps) and her amount of hit points.
Your damage per second is 1.
That is, you are able to reduce an opponent's hit points by 1 each second.
In other words, if a fairy has H hit points, it takes you H seconds to defeat her.

You are given two vector <int>s, each of length N: dps and hp.
For each i, dps[i] is the damage per second of fairy i, and hp[i] is her initial amount of hit points.
We assume that your number of hit points is sufficiently large to avoid defeat when fighting the fairies.
Compute and return the total number of hit points you'll lose during the fight.
In other words, return the total amount of damage the attacking fairies will deal.


DEFINITION
Class:GreatFairyWar
Method:minHP
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int minHP(vector <int> dps, vector <int> hp)


NOTES
-Damage per second (dps) of a person P is the rate at which P can deal damage to their opponents.


CONSTRAINTS
-dps will contain between 1 and 30 elements, inclusive.
-dps and hp will contain the same number of elements.
-Each element in dps will be between 1 and 30, inclusive.
-Each element in hp will be between 1 and 30, inclusive.


EXAMPLES

0)
{1,2}
{3,4}

Returns: 17

It will take you 3 seconds to defeat fairy 0 and then 4 seconds to defeat fairy 1.
During the first 3 seconds both fairies attack you, dealing 1+2 = 3 damage each second.
During the next 4 seconds fairy 1 continues to attack you, dealing 2 damage each second.
The total number of hit points you lose is 3*(1+2) + 4*2 = 9 + 8 = 17.


1)
{1,1,1,1,1,1,1,1,1,1}
{1,1,1,1,1,1,1,1,1,1}

Returns: 55

The answer is 10+9+...+3+2+1 = 55.


2)
{20,12,10,10,23,10}
{5,7,7,5,7,7}

Returns: 1767


3)
{5,7,7,5,7,7}
{20,12,10,10,23,10}

Returns: 1998


4)
{30,2,7,4,7,8,21,14,19,12}
{2,27,18,19,14,8,25,13,21,30}

Returns: 11029


5)
{1}
{1}

Returns: 1

*/
// END CUT HERE
#include <cmath>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class GreatFairyWar {

public:
	int minHP(vector <int> dps, vector <int> hp) {
		int past = 0;
		int res = 0;
		int i;
		for (i = 0; i < (int)dps.size(); ++i) {
			past += hp[i];
			res += past * dps[i];
		}
		return res;
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
			int Arr0[] = {1,2};
			int Arr1[] = {3,4};
			int Arg2 = 17;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minHP(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1,1,1,1,1,1,1,1,1};
			int Arr1[] = {1,1,1,1,1,1,1,1,1,1};
			int Arg2 = 55;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minHP(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {20,12,10,10,23,10};
			int Arr1[] = {5,7,7,5,7,7};
			int Arg2 = 1767;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minHP(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5,7,7,5,7,7};
			int Arr1[] = {20,12,10,10,23,10};
			int Arg2 = 1998;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minHP(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {30,2,7,4,7,8,21,14,19,12};
			int Arr1[] = {2,27,18,19,14,8,25,13,21,30};
			int Arg2 = 11029;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minHP(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1};
			int Arr1[] = {1};
			int Arg2 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minHP(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	GreatFairyWar ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
