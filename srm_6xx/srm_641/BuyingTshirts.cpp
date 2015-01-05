// BEGIN CUT HERE
/*
SRM 641 Div2 Easy (250)

PROBLEM STATEMENT
A local store is selling T-shirts with the face of Fox Ciel printed on them.
Each such T-shirt costs T pesos.
Quimey and Pablo love those T-shirts.
They each buy a new T-shirt whenever they have the money to do so.

Currently, Quimey and Pablo have no money at all.
During the following N days they are going to earn some money and they will use it to buy the T-shirts.
The days are numbered from 0 (today) to N-1 (the day N-1 days in the future).

For each valid i, Q[i] and P[i] are the amounts in pesos Quimey and Pablo will earn on day i.
(Note that each of those amounts is at most T. 
Therefore, Quimey and Pablo will be able to buy at most one T-shirt each day.)

For example, suppose that a T-shirt costs T=10 pesos.
If Q={2,3,5,10}, the following will happen to Quimey:

On day 0, he earns 2 pesos. He now has 2 pesos.
On day 1, he earns 3 pesos. He now has 5 pesos.
On day 2, he earns 5 pesos. He now has 10 pesos, which is enough to buy a T-shirt. He goes to the store and buys one. Afterwards, he has 0 pesos left.
On day 3, he earns 10 pesos. He then goes to buy a second T-shirt. Afterwards, he again has 0 pesos left.

If P={10,8,6,4}, Pablo would buy one T-shirt on day 0, and then another T-shirt on day 2. After buying the T-shirt on day 2 he would have 4 pesos left. After day 3 he would then have a total of 8 pesos, which is still not enough for a T-shirt.
Note that in this example Quimey and Pablo would go to the store together on day 2.

You are given the int T: the price of a single T-shirt.
You are also given the vector <int>s Q and P with N elements each: the amounts Quimey and Pablo earn each day.
Compute and return the number of days on which Quimey and Pablo both go to the store


DEFINITION
Class:BuyingTshirts
Method:meet
Parameters:int, vector <int>, vector <int>
Returns:int
Method signature:int meet(int T, vector <int> Q, vector <int> P)


NOTES
-If you need the number N in your solution, you can determine it as the number of elements in Q.


CONSTRAINTS
-T will be between 1 and 100.
-Q will contain between 1 and 100 elements.
-Q and P will contain the same number of elements.
-Each element of Q will be between 1 and T.
-Each element of P will be between 1 and T.


EXAMPLES

0)
5
{1,2,3,4,5}
{5,4,3,2,1}

Returns: 2

Quimey will buy his T-shirts on days 2, 3, and 4.
Pablo will buy his on days 0, 2, and 4.
They will go to the store together twice: first on day 2 and then on day 4.


1)
10
{10,10,10}
{10,10,10}

Returns: 3


2)
2
{1,2,1,2,1,2,1,2}
{1,1,1,1,2,2,2,2}

Returns: 5

They will both go to the store on the following days: 1, 3, 5, 6, and 7.


3)
100
{1,2,3}
{4,5,6}

Returns: 0

In this test case they do not buy any T-shirts at all.


4)
10
{10,1,10,1}
{1,10,1,10}

Returns: 0

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class BuyingTshirts {
public:
	int meet(int T, vector <int> Q, vector <int> P) {
		int ans = 0;
		int q = 0, p = 0;
		for (int i = 0; i < (int)Q.size(); ++i) {
			q += Q[i], p += P[i];
			ans += q >= T && p >= T;
			q %= T;
			p %= T;
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
			int Arg0 = 5;
			int Arr1[] = {1,2,3,4,5};
			int Arr2[] = {5,4,3,2,1};
			int Arg3 = 2;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, meet(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arr1[] = {10,10,10};
			int Arr2[] = {10,10,10};
			int Arg3 = 3;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, meet(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arr1[] = {1,2,1,2,1,2,1,2};
			int Arr2[] = {1,1,1,1,2,2,2,2};
			int Arg3 = 5;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, meet(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 100;
			int Arr1[] = {1,2,3};
			int Arr2[] = {4,5,6};
			int Arg3 = 0;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, meet(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arr1[] = {10,1,10,1};
			int Arr2[] = {1,10,1,10};
			int Arg3 = 0;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, meet(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BuyingTshirts ___test;
	___test.run_test(-1);
}
// END CUT HERE
