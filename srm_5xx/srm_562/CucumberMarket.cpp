// BEGIN CUT HERE
/*
// SRM 562 Div2 Easy (250)

// PROBLEM STATEMENT
// 
Cucumber Boy is young and loves cucumbers.  Therefore, Cucumber Boy will go to the cucumber market to buy some cucumbers.

Different cucumbers may have different costs.  For each i, buying the i-th cucumber (0-based index) costs price[i] yen.

Cucumber Boy's mother gave him budget yen.  However, he does not understand money well.
He just chooses some k unique cucumbers he likes.  If the total price of the chosen cucumbers is not greater than budget yen, he can buy them, otherwise he cannot.

You are given the vector <int> price, the int budget and the int k.  Your method must return "YES" (quotes for clarity) if Cucumber Boy can buy any set of k unique cucumbers, and "NO" if there is some set of k cucumbers that is too expensive for him.


DEFINITION
Class:CucumberMarket
Method:check
Parameters:vector <int>, int, int
Returns:string
Method signature:string check(vector <int> price, int budget, int k)


CONSTRAINTS
-price will contain between 1 and 9 elements, inclusive.
-Each element of price will be between 1 and 1000, inclusive.
-budget will be between 1 and 10000, inclusive.
-k will be between 1 and the number of elements in price, inclusive.


EXAMPLES

0)
{1000,1,10,100}
1110
3

Returns: "YES"

There are 4 choices.

If he chooses cucumbers 0, 1, and 2, the total price will be 1000+1+10 = 1011 yen.
If he chooses cucumbers 0, 1, and 3, the total price will be 1000+1+100 = 1101 yen.
If he chooses cucumbers 0, 2, and 3, the total price will be 1000+10+100 = 1110 yen.
If he chooses cucumbers 1, 2, and 3, the total price will be 1+10+100 = 111 yen.

The result is "YES", because Cucumber Boy can buy any set of k unique cucumbers.


1)
{1000,1,10,100}
1109
3

Returns: "NO"

This case is the same as the example 0, except for the value of budget. 

If he chooses cucumbers 0, 2, and 3, the total price will be 1000+10+100 = 1110 yen.
 1110 yen is greater than the budget therefore the result is "NO".


2)
{33,4}
33
1

Returns: "YES"


3)
{1,1,1,1,1,1}
2
4

Returns: "NO"


4)
{1000,1000,1000,1000,1000,1000,1000,1000,1000}
10000
9

Returns: "YES"

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class CucumberMarket {

public:
	string check(vector <int> price, int budget, int k) {
		sort(price.rbegin(), price.rend());
		int i;
		for (i = 0; i < k; ++i) {
			budget -= price[i];
			if (budget < 0) {
				return "NO";
			}
		}
		return "YES";
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
			int Arr0[] = {1000,1,10,100};
			int Arg1 = 1110;
			int Arg2 = 3;
			string Arg3 = "YES";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, check(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1000,1,10,100};
			int Arg1 = 1109;
			int Arg2 = 3;
			string Arg3 = "NO";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, check(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {33,4};
			int Arg1 = 33;
			int Arg2 = 1;
			string Arg3 = "YES";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, check(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1,1,1,1,1};
			int Arg1 = 2;
			int Arg2 = 4;
			string Arg3 = "NO";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, check(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1000,1000,1000,1000,1000,1000,1000,1000,1000};
			int Arg1 = 10000;
			int Arg2 = 9;
			string Arg3 = "YES";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, check(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	CucumberMarket ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
