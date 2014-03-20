// BEGIN CUT HERE
/*
SRM 601 Div2 Easy (250)

PROBLEM STATEMENT
It's winter time!
Time to eat a lot of mandarins with your friends.

You have several bags with mandarins.
You are given an vector <int> bags.
For each i, the i-th element of bags represents the number of mandarins in the i-th bag.
You are also given an int K.
You want to choose exactly K bags and distribute them among you and your friends.
To be as fair as possible, you want to minimize the difference between the chosen bag with most mandarins and the chosen bag with fewest mandarins.
Return the smallest difference that can be achieved.


DEFINITION
Class:WinterAndMandarins
Method:getNumber
Parameters:vector <int>, int
Returns:int
Method signature:int getNumber(vector <int> bags, int K)


CONSTRAINTS
-bags will contain between 2 and 50 elements, inclusive.
-Each element of bags will be between 1 and 1,000,000,000, inclusive.
-K will be between 2 and N, inclusive, where N is the number of elements in bags.


EXAMPLES

0)
{10, 20, 30}
2

Returns: 10

There are three ways to choose two bags in this case: {10, 20}, {20, 30}, and {10, 30}.
Both in the first case and in the second case the difference between the largest and the smallest number of mandarins is 10.
In the third case the difference is 20.
Thus, the smallest possible difference is 10.


1)
{4, 7, 4}
3

Returns: 3


2)
{4, 1, 2, 3}
3

Returns: 2


3)
{5, 4, 6, 1, 9, 4, 2, 7, 5, 6}
4

Returns: 1


4)
{47, 1000000000, 1, 74}
2

Returns: 27

*/
// END CUT HERE

#include <string> 
#include <vector> 
#include <iostream> 
#include <sstream> 

using namespace std; 

class WinterAndMandarins {
	public:
	int getNumber(vector <int> bags, int K) {
		sort(bags.begin(), bags.end());
		int ans = 1<<30;
		for (int i = 0; i <= ((int)bags.size()-K); ++i) {
			ans = min(ans, bags[i+K-1]-bags[i]);
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
			int Arr0[] = {10, 20, 30};
			int Arg1 = 2;
			int Arg2 = 10;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4, 7, 4};
			int Arg1 = 3;
			int Arg2 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4, 1, 2, 3};
			int Arg1 = 3;
			int Arg2 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5, 4, 6, 1, 9, 4, 2, 7, 5, 6};
			int Arg1 = 4;
			int Arg2 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {47, 1000000000, 1, 74};
			int Arg1 = 2;
			int Arg2 = 27;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE


};
// BEGIN CUT HERE 
int main() {
	WinterAndMandarins ___test;
	___test.run_test(-1);
}
// END CUT HERE

